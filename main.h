#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>                                     
#include <GL/glu.h>    
#include <math.h>                
#include "SDL.h"

//#define pSpeed 0.01f

// Screen width, height and bits per pixel. This shouldn't really be hardcoded, Maybe keep this as default settings.
#define SWIDTH 1024                           
#define SHEIGHT 768                              
#define SDEPTH 16                            

using namespace std;

#define MAX_TEXTURES 100 

typedef unsigned char byte;

typedef unsigned int UINT;
extern UINT g_Textures[MAX_TEXTURES];                   

extern int VideoFlags;                                 
extern SDL_Surface * MainWindow;                       
	

void fpsRate();   

struct tVector3	// Extended 3D Vector Struct
{			
	tVector3() {} // Struct Constructor
	tVector3 (float new_x, float new_y, float new_z) // Init Constructor	 
	{ x = new_x; y = new_y; z = new_z; }
	// overload + operator
	tVector3 operator+(tVector3 vVector) {return tVector3(vVector.x+x, vVector.y+y, vVector.z+z);}
	// overload - operator
	tVector3 operator-(tVector3 vVector) {return tVector3(x-vVector.x, y-vVector.y, z-vVector.z);}
	// overload * operator
	tVector3 operator*(float number)	 {return tVector3(x*number, y*number, z*number);}
	// overload / operator
	tVector3 operator/(float number)	 {return tVector3(x/number, y/number, z/number);}
	
	float x, y, z;						// 3D vector coordinates
};

// As it says on the tin
void MainGameLoop(void);

// This allows us to configure our window for OpenGL and backbuffered
void SetupPixelFormat(void);

void CreateWindow(const char *strWindowName, int width, int height, int VideoFlags);

void ToggleFullScreen(void);

void InitializeGL(int width, int height);

void Init();

void CreateTexture(UINT textureArray[],char *strFileName,int textureID);

void ToggleFullScreen();

void HandleKeyDownEvent(SDL_keysym * keysym);

void HandleKeyUpEvent(SDL_keysym * keysym);

void RenderScene();

void drawText();
void drawShip();
void drawNacelle(float x, float y);
void drawNacelleThruster(float x, float y);
void drawBridgeFrontWindow();
void drawRearEngine();

void drawCharacter(float x, float y, float z, float w, float h);
//void drawStarScape();
void drawStarScape(float x, float y, float z, float width, float height, float length);
void drawStars();


void SizeOpenGLScreen(int width, int height);

void Quit(int ret_val);
				
#endif
