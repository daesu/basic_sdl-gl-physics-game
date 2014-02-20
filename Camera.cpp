#include "main.h"
#include "camera.h"

#define pSpeed 1.0f // How fast the camera moves

extern bool w, s, a, d, u, p, l, r; // Boolean flags for key stroke movement

float frameInterval = 0.0f; 

double thrustVal = 0;
double maxThrust = 0.1; 
double maxMinusThrust = -0.1;

void CCamera::PositionCam(float posx,  float posy,  float posz, float viewx, float viewy, float viewz, float upx,   float upy,   float upz)
{
	mPos	= tVector3(posx,  posy,  posz ); // Starting vector position
	mView	= tVector3(viewx, viewy, viewz); // Starting view vector (where the camera is looking towards)
	mUp	= tVector3(upx,   upy,   upz  ); // Up vector
}

// Move forwards and backward
void CCamera::Move(float speed)
{
	tVector3 vVector = mView - mPos;	
	
	// forward positive cameraspeed and backward negative -cameraspeed.
	mPos.x  = mPos.x  + vVector.x * speed;
	mPos.z  = mPos.z  + vVector.z * speed;
	mView.x = mView.x + vVector.x * speed;
	mView.z = mView.z + vVector.z * speed;
	mPos.y  = mPos.y  + vVector.y * speed;
	mView.y = mView.y + vVector.y * speed;
}

// Rotate the view
void CCamera::RotateView(float speed)
{
	tVector3 vVector = mView - mPos;	

	mView.z = (float)(mPos.z + sin(speed)*vVector.x + cos(speed)*vVector.z);
	mView.x = (float)(mPos.x + cos(speed)*vVector.x - sin(speed)*vVector.z);
	//mView.y = (float)(mPos.y + cos(speed)*vVector.x - sin(speed)*vVector.z);
}
// Strafe (Sidestep)
void CCamera::Strafe(float speed)
{
	tVector3 vVector = mView - mPos;	
	tVector3 vOrthoVector;              

	// OrthoVector gets a vector perpendicular to the view minus the position
	vOrthoVector.x = -vVector.z;
	vOrthoVector.z =  vVector.x;

	// left positive cameraspeed and right negative -speed.
	mPos.x  = mPos.x  + vOrthoVector.x * speed;
	mPos.z  = mPos.z  + vOrthoVector.z * speed;
	mView.x = mView.x + vOrthoVector.x * speed;
	mView.z = mView.z + vOrthoVector.z * speed;
}

// Mouselook
void CCamera::MouseView()
{
	int mX,mY;	
	int midScreenX = SWIDTH  >> 1;	// Binary division
	int midScreenY = SHEIGHT >> 1;	
	float angle_y  = 0.0f;				
	float angle_z  = 0.0f;												
	
	SDL_GetMouseState(&mX,&mY);	// Get the mouse cursor position

	if( (mX == midScreenX) && (mY == midScreenY) ) return;

    	SDL_WarpMouse(midScreenX, midScreenY);      // Move the mouse cursor position                      					
	angle_y = (float)( (midScreenX - mX) ) / 1000;		
	angle_z = (float)( (midScreenY - mY) ) / 1000;  

	mView.y += angle_z * 2;

	if((mView.y - mPos.y) > 8)  mView.y = mPos.y + 8;
	if((mView.y - mPos.y) <-8)  mView.y = mPos.y - 8;
	
	RotateView(-angle_y); 	// Rotate to the new view defined by the mouse position
}

void CCamera::ChkMovement()
{
	
	float nSpeed = pSpeed * frameInterval;

	// If we pressed w
	if(w) {                
	//Move(nSpeed);
		if(thrustVal >= maxThrust){
		}                
		else{
			thrustVal = thrustVal + 0.001;
			//thrustVal = thrustVal + 0.01;
		}    
	}

	if(s) {            
	//Move(-nSpeed); 
		if(thrustVal <= maxMinusThrust){
		}                
		else{
			thrustVal = thrustVal - 0.001;
			//thrustVal = thrustVal - 0.01;
		}                   
	}
   
	// We assume banking left or right will automatically correct itself once you stop banking
	if(a) {            
        	Strafe(-nSpeed); // Strafe left
    	}

    	if(d) {            
        	Strafe(nSpeed); // Strafe Right
    	}

	// If momentum is more then 0 (moving forward)
	if(thrustVal > 0){
		Move(thrustVal);
	}
	
	// If momentum is less then 0 (moving backward)
	if(thrustVal < 0){
		Move(thrustVal);	
	}

	if(l) {            
		RotateView(-nSpeed);    
	}

	if(r) {           
		RotateView(nSpeed);    
	}

}

// Camera look at
void CCamera::Look()
{
    gluLookAt(mPos.x, mPos.y, mPos.z, mView.x, mView.y, mView.z, mUp.x, mUp.y, mUp.z);
}

// FPS rate and time based movemet
void fpsRate()
{
    static float framesPS = 0.0f;     
    static float lastFrameTime = 0.0f;     
    static char strFrameRate[50] = {0};        

    static float frameTime = 0.0f;              

    float theTime = SDL_GetTicks() * 0.001f;  // Get the time              

    frameInterval = theTime - frameTime;
    frameTime = theTime;

    ++framesPS;

    if( theTime - lastFrameTime > 1.0f )
    {
        lastFrameTime = theTime;

        framesPS = 0;
    }
}
