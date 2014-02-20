#include "main.h"
#include "camera.h"

extern bool w, s, a, d; 

CCamera p_Camera; //Camera object

// Defines unique identifers

#define SPACE 0
#define METAL 1
#define GREY 2
#define BORG 3

// Maximum # of textures
UINT g_Texture[MAX_TEXTURES] = {0};                                                          

void Init()
{
    	InitializeGL(SWIDTH, SHEIGHT);  //Initialise Opengl with the screen width and height         

	SDL_WM_GrabInput(SDL_GRAB_ON); // SDL grab events

    	if ( SDL_ShowCursor(SDL_DISABLE) != SDL_DISABLE )
              cerr << SDL_GetError() << endl;

	if( SDL_EnableKeyRepeat(100,SDL_DEFAULT_REPEAT_INTERVAL) )
    	{
        cerr << "Failed enabling key repeat" << endl;
        Quit(1);
    	}

	// Initial Camera position
	p_Camera.PositionCam(0, 20.5f, 6,   0, 20.5f, 0,   0, 1, 0);  
	//p_Camera.PositionCam(0, 0, 0,   0, 0, 0,   0, 0, 0); 
	
	// Setup the various textures assigned to various values.
	CreateTexture(g_Texture, "Space.bmp", SPACE);
	CreateTexture(g_Texture, "metalwork.bmp", METAL);
	CreateTexture(g_Texture, "Grey.bmp", GREY);
	CreateTexture(g_Texture, "BorgShip.bmp", BORG);
	
}

void MainGameLoop(void)
{
	bool done = false;
	bool finished = false;
	SDL_Event e;

    while(finished == false)
    {
	done = false;
        while(SDL_PollEvent(& e))                    //Check for events
        {
		done = false;
            switch (e.type )                          
            {
                case SDL_QUIT :                                         
	               	finished = true;                                        
                    break;

				// on KeyDown
		case SDL_KEYDOWN :                                      
                    HandleKeyDownEvent( & e. key.keysym );         
                    break;
                    
				// on KeyUp                
		case SDL_KEYUP :										
                    HandleKeyUpEvent(& e.key.keysym) ;           
                    break;                 case SDL_VIDEORESIZE :                                  
                    MainWindow = SDL_SetVideoMode( e.resize.w, e.resize.h, SDEPTH, VideoFlags );
                    SizeOpenGLScreen(e.resize.w, e.resize.h);   
    
                    if(MainWindow == NULL)                             
                    {
                        cerr << " Failed resizing SDL window : " << SDL_GetError() << endl;   
                        Quit(0);
                    }
                    break;

                default:                                    
                    break;                                  
            }
			
        } 
	p_Camera.MouseView(); 	// Has the mouse moved ?                   
	p_Camera.ChkMovement(); // Do we need to move the camera ?
	RenderScene();          // draw :P
    } 
}

// Full screen or window mode
void ToggleFullScreen(void)
{
    if(SDL_WM_ToggleFullScreen(MainWindow) == 0)       
    {
        cerr << "Toggle Fullscreen Failed: " << SDL_GetError() << endl;   
        Quit(0);
    }
}

// Create Skybox
void CreateSkyBox(float x, float y, float z, float width, float height, float length)
{
	// Enabling 2D texturing
	glEnable( GL_TEXTURE_2D );

	// Bind the SPACE texture to the objects drawn next
	glBindTexture(GL_TEXTURE_2D, g_Texture[SPACE]);

	// This centers the skybox
	x = x - width  / 2;
	y = y - height / 2;
	z = z - length / 2;

    glBegin(GL_QUADS);        
        // BACK Side
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, z);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, z);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, z); 
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, z);
 
        // FRONT Side
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z + length);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y + height, z + length);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z + length); 
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y, z + length);   
    
        // BOTTOM 
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y,z + length);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y,z + length); 
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y,z);

        // TOP Side
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y + height,z);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y + height,z + length);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y + height, z + length); 
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height, z);       
        
        // LEFT Side
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x,y,z);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x,y,z + length);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x,y + height,z + length); 
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x,y + height,z);      

        // RIGHT Side
        glTexCoord2f(0.0f, 0.0f); glVertex3f(x + width, y,z);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y,z + length);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height,z + length); 
        glTexCoord2f(0.0f, 1.0f); glVertex3f(x + width, y + height,z);
    glEnd();

	// Disable 2D texturing
	glDisable(GL_TEXTURE_2D);
}

// Draw the spaceship object
void drawSpaceShip()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, g_Texture[METAL]);
	drawShip();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, g_Texture[GREY]);
	drawNacelleThruster(-10,-20);
	drawNacelleThruster(30,40);
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, g_Texture[METAL]);
	drawNacelle(-10,-20);
	drawNacelle(30,40);
	glDisable(GL_TEXTURE_2D);
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, g_Texture[GREY]);
	drawRearEngine();
	glDisable(GL_TEXTURE_2D);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, g_Texture[GREY]);
	drawBridgeFrontWindow();
	glDisable(GL_TEXTURE_2D);

}


void drawCharacter()
{
	// Allocate a quadric object to use as a sphere
	GLUquadricObj *pObj = gluNewQuadric();

	// Allow quadric texturing
	gluQuadricTexture(pObj, true);
		
	// Translate the spheres position to always be in front of the Camera (Third Person View)
	glTranslatef(p_Camera.mView.x, (p_Camera.mView.y - 2), p_Camera.mView.z);

	// Enable texturing for the following objects
	glEnable(GL_TEXTURE_2D);

	//Bind the texture 'BORG' to the following objects
	glBindTexture(GL_TEXTURE_2D, g_Texture[BORG]);

	// Gets first object in Quadric stack
	glPushName(BORG);	

	// So we don't affect any other quadrics, specify new matrix
	glPushMatrix();										
		glTranslatef(0, 0, 0);		  // translate sphere to (0, 0, 0,)	
		gluSphere(pObj, 1.5f, 20, 20);  // Draw a sphere radius 1.5		
	glPopMatrix();	// End this matrix									
	// Disable texturing
	glDisable(GL_TEXTURE_2D);

	// Make sure nothing else will be associated with the ‘BORG’ id
	glPopName();

	// Free the quadric
	gluDeleteQuadric(pObj);

}

void RenderScene() 
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear everything   
	glLoadIdentity();                                    // Reset the matrix

	p_Camera.Look();                                    

	// Create a Skybox with these values
	CreateSkyBox(0, 0, 0, 1200, 1000, 1200); 
	drawSpaceShip();
	drawCharacter();

	// Swap the backbuffers to the front
	SDL_GL_SwapBuffers();	

	// FPS rate and time based movement
	fpsRate();

}

