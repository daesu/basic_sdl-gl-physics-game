#include "main.h"

void drawShip()
{
	glBegin(GL_QUADS);
	//torso
		// Front Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f,  40.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 20.0f, 0.0f,  40.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 20.0f,  10.0f,  40.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f,  10.0f,  40.0f);	
		// Back Face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f,  10.0f, 0.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 20.0f,  10.0f, 0.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 20.0f, 0.0f, 0.0f);	
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f,  10.0f, 0.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f,  10.0f,  40.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 20.0f,  10.0f,  40.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 20.0f,  10.0f, 0.0f);	
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 20.0f, 0.0f, 0.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 20.0f, 0.0f,  40.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f,  40.0f);	
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 20.0f, 0.0f, 0.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 20.0f,  10.0f, 0.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 20.0f,  10.0f, 40.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 20.0f, 0.0f,  40.0f);	
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f,  40.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f,  10.0f,  40.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f,  10.0f, 0.0f);	

	//bridge
		// Front Face	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, 12.0f,  -25.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 28.0f, 12.0f,  -25.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 28.0f,  13.0f,  -25.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  13.0f,  -25.0f);	
		// Back Face	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, 12.0f, -8.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f,  13.0f, -8.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 28.0f,  13.0f, -8.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 28.0f, 12.0f, -8.0f);	
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  13.0f, -8.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f,  13.0f,  -25.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 28.0f,  13.0f,  -25.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 28.0f,  13.0f, -8.0f);	
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f, 12.0f, -8.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(28.0f, 12.0f, -8.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(28.0f, 12.0f,  -25.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, 12.0f,  -25.0f);	
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(28.0f, 12.0f, -8.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(28.0f,  13.0f, -8.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(28.0f,  13.0f,  -25.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(28.0f, 12.0f,  -25.0f);	
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, 12.0f, -8.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, 12.0f,  -25.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f,  13.0f,  -25.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  13.0f, -8.0f);	

	//Bridge front bit
		// Front Face	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(5.0f, 8.0f,  -15.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 15.0f, 8.0f,  -15.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 15.0f,  10.0f,  -15.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(5.0f,  10.0f,  -15.0f);		
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(5.0f,  10.0f, 0.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(5.0f,  10.0f,  0.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 15.0f,  10.0f,  0.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 15.0f,  10.0f, 0.0f);	
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f, 8.0f, 0.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 15.0f, 8.0f, 0.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 15.0f, 8.0f,  -15.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 8.0f,  -15.0f);	
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 15.0f, 8.0f, 0.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 15.0f,  10.0f, 0.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 15.0f,  10.0f,  -15.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 15.0f, 8.0f,  -15.0f);	
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(5.0f, 8.0f, 0.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 8.0f,  -15.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f,  10.0f,  -15.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(5.0f,  10.0f, 0.0f);	


	//bridge top bit
		// Front Face	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(5.0f, 10.0f,  -15.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 15.0f, 10.0f,  -15.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 15.0f,  12.0f,  -15.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(5.0f,  12.0f,  -15.0f);	
		// Back Face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(15.0f, 10.0f, 35.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(15.0f,  12.0f, 35.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 5.0f,  12.0f, 35.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 5.0f, 10.0f, 35.0f);	
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(5.0f,  12.0f, 35.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(5.0f,  12.0f,  -15.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 15.0f,  12.0f,  -15.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 15.0f,  12.0f, 35.0f);	
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 15.0f, 10.0f, 35.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 15.0f,  12.0f, 35.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 15.0f,  12.0f,  -15.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 15.0f, 10.0f,  -15.0f);	
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(5.0f, 10.0f, 35.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(5.0f, 10.0f,  -15.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(5.0f,  12.0f,  -15.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(5.0f,  12.0f, 35.0f);	



	//nacelle link bow left
		// Front Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, 0.0f,  5.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.0f, 0.0f,  5.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.0f,  4.0f,  5.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  4.0f,  5.0f);	
		// Back Face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, 0.0f, 15.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f,  4.0f, 15.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.0f,  4.0f, 15.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.0f, 0.0f, 15.0f);	
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  4.0f, 15.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f,  4.0f,  5.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.0f,  4.0f,  5.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.0f,  4.0f, 15.0f);	
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f, 0.0f, 15.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.0f, 0.0f, 15.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.0f, 0.0f,  5.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, 0.0f,  5.0f);	

	//nacelle link bow right
		// Front Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(20.0f, 0.0f,  5.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 40.0f, 0.0f,  5.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 40.0f,  4.0f,  5.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(20.0f,  4.0f,  5.0f);	
		// Back Face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(20.0f, 0.0f, 15.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(20.0f,  4.0f, 15.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 40.0f,  4.0f, 15.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 40.0f, 0.0f, 15.0f);	
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(20.0f,  4.0f, 15.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(20.0f,  4.0f,  5.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 40.0f,  4.0f,  5.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 40.0f,  4.0f, 15.0f);	
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(20.0f, 0.0f, 15.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 40.0f, 0.0f, 15.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 40.0f, 0.0f,  5.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(20.0f, 0.0f,  5.0f);	

	//nacelle link left aft
		// Front Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, 0.0f,  30.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.0f, 0.0f,  30.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.0f,  4.0f,  30.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  4.0f,  30.0f);	
		// Back Face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, 0.0f, 35.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f,  4.0f, 35.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.0f,  4.0f, 35.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.0f, 0.0f, 35.0f);	
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  4.0f, 35.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f,  4.0f,  30.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.0f,  4.0f,  30.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.0f,  4.0f, 35.0f);	
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f, 0.0f, 35.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.0f, 0.0f, 35.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.0f, 0.0f,  30.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, 0.0f,  30.0f);	

	//nacelle link right aft
		// Front Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(20.0f, 0.0f,  30.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 40.0f, 0.0f,  30.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 40.0f,  4.0f,  30.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(20.0f,  4.0f,  30.0f);	
		// Back Face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(20.0f, 0.0f, 35.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(20.0f,  4.0f, 35.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 40.0f,  4.0f, 35.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 40.0f, 0.0f, 35.0f);	
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(20.0f,  4.0f, 35.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(20.0f,  4.0f,  30.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 40.0f,  4.0f,  30.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 40.0f,  4.0f, 35.0f);	
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(20.0f, 0.0f, 35.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 40.0f, 0.0f, 35.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 40.0f, 0.0f,  30.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(20.0f, 0.0f,  30.0f);	
	
	glEnd();

}

void drawNacelle(float x, float y)
{
	//nacelle right
	glBegin(GL_QUADS);
		// Front Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, 0.0f,  65.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(y, 0.0f,  65.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( y,  5.0f,  65.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,  5.0f,  65.0f);	
		// Back Face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x, 0.0f, -5.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,  5.0f, -5.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( y,  5.0f, -5.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(y, 0.0f, -5.0f);	
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,  5.0f, -5.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,  5.0f,  65.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( y,  5.0f,  65.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(y,  5.0f, -5.0f);	
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x, 0.0f, -5.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( y, 0.0f, -5.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( y, 0.0f,  65.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x, 0.0f,  65.0f);	
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f( y, 0.0f, -5.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(y,  5.0f, -5.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(y,  5.0f,  65.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( y, 0.0f,  65.0f);
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, 0.0f, -5.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x, 0.0f,  65.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,  5.0f,  65.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,  5.0f, -5.0f);	
	glEnd();


}

void drawNacelleThruster(float x, float y)
{
	glBegin(GL_QUADS);
		// Front Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, 1.0f,  67.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( y, 1.0f,  67.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( y,  4.0f,  67.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,  4.0f,  67.0f);	
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,  4.0f, 65.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x,  4.0f,  67.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( y,  4.0f,  67.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( y,  4.0f, 65.0f);	
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x, 1.0f, 65.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(y, 1.0f, 65.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(y, 1.0f,  67.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x, 1.0f,  67.0f);	
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f(y, 1.0f, 65.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(y,  4.0f, 65.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(y,  4.0f,  67.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(y, 1.0f,  67.0f);	
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(x, 1.0f, 65.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(x, 1.0f,  67.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(x,  4.0f,  67.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(x,  4.0f, 65.0f);	
	glEnd();

}

void drawBridgeFrontWindow()
{
	//Bridge front Window
	glBegin(GL_QUADS);
		// Front Face	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, 12.0f,  -25.1f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 28.0f, 12.0f,  -25.1f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 28.0f,  13.0f,  -25.1f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  13.0f,  -25.1f);		
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  13.0f, -25.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f,  13.0f,  -25.1f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 28.0f,  13.0f,  -25.1f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 28.0f,  13.0f, -25.0f);	
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f, 12.0f, -25.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 28.0f, 12.0f, -25.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 28.0f, 12.0f,  -25.1f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, 12.0f,  -25.1f);	
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 28.0f, 12.0f, -25.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 28.0f,  13.0f, -25.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 28.0f,  13.0f,  -25.1f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 28.0f, 12.0f,  -25.1f);	
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, 12.0f, -25.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, 12.0f,  -25.1f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.0f,  13.0f,  -25.1f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0f,  13.0f, -25.0f);	
	glEnd();
}

void drawRearEngine(){
		//Rear engine
		// Back Face
	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(2.0f, 2.0f,  41.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 18.0f, 2.0f,  41.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 18.0f,  8.0f, 41.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(2.0f,  8.0f,  41.0f);			
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(2.0f,  8.0f, 41.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(2.0f,  8.0f,  40.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 18.0f,  8.0f,  40.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 18.0f,  8.0f, 41.0f);	
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(2.0f, 2.0f, 41.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 18.0f, 2.0f, 41.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 18.0f, 2.0f,  40.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(2.0f, 2.0f,  40.0f);	
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 18.0f, 2.0f, 41.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 18.0f,  8.0f, 41.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 18.0f,  8.0f,  40.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 18.0f, 2.0f,  40.0f);	
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(2.0f, 2.0f, 41.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(2.0f, 2.0f,  40.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(2.0f,  8.0f,  40.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(2.0f,  8.0f, 41.0f);

	//Engine
		glTexCoord2f(0.0f, 0.0f); glVertex3f(4.0f, 4.0f,  42.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 16.0f, 4.0f,  42.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 16.0f,  6.0f, 42.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(4.0f,  6.0f,  42.0f);			
		// Top Face
		glTexCoord2f(0.0f, 1.0f); glVertex3f(4.0f,  6.0f, 42.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f(4.0f,  6.0f,  41.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 16.0f,  6.0f,  41.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 16.0f,  6.0f, 42.0f);	
		// Bottom Face
		glTexCoord2f(1.0f, 1.0f); glVertex3f(4.0f, 4.0f, 42.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 16.0f, 4.0f, 42.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 16.0f, 4.0f,  41.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, 4.0f,  41.0f);	
		// Right face
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 16.0f, 4.0f, 42.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 16.0f,  6.0f, 42.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 16.0f,  6.0f,  41.0f);	
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 16.0f, 4.0f,  41.0f);	
		// Left Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(4.0f, 4.0f, 42.0f);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, 4.0f,  41.0f);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f(4.0f,  6.0f,  41.0f);	
		glTexCoord2f(0.0f, 1.0f); glVertex3f(4.0f,  6.0f, 42.0f);
	glEnd();	

}
