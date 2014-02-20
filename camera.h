#ifndef _CAMERA_H
#define _CAMERA_H

//#define pSpeed 0.001 // How do i set this so it will be the same on different machines ?

class CCamera 
{
	public:

		tVector3 mPos;	
		tVector3 mView;		
		tVector3 mUp;			

		void PositionCam(float posx, float posy,float posz,
		 				 float viewx, float viewy, float viewz,
						 float upx,   float upy,   float upz);

		void Move(float speed);
		void RotateView(float speed);
		void RotateUpDown(float speed);		
		void ChkMovement();
		//void ChkThrust(float t);
		void Strafe(float speed);
		void MouseView();
	    //void Update();		// Not needed

	    // This uses gluLookAt() to tell OpenGL where to look
	    void Look();     
};

extern CCamera p_Camera;  

#endif
