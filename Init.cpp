#include "main.h"

int VideoFlags = 0;                         
SDL_Surface * MainWindow = NULL; // SDL drawing surface

bool w = false , s = false , a = false , d = false, u = false , p = false, l = false , r = false; // Set key press flags to false

void CreateWindow(const char * strWindowName, int width, int height, int VideoFlags)
{
    MainWindow = SDL_SetVideoMode(width, height, SDEPTH, VideoFlags);     
    SDL_WM_SetCaption(strWindowName, strWindowName);
	ToggleFullScreen();
}


void CreateTexture(unsigned int texArray[],char *strFileName,int texID)
{
	    SDL_Surface *pBitmap[1];

	    if( strFileName == NULL )                           
	    return ;
	    
	    pBitmap[0] = SDL_LoadBMP(strFileName);   // SDL loads the bitmap and store the data      

	    // error checking
	    if(pBitmap[0] == NULL)
	    {
	        cerr << " Failed loading " << strFileName << " : " << SDL_GetError() << endl;
	        Quit(0);
	    }

	    // Tell openGL about our texture and give it an ID, hold this reference in an array
	    glGenTextures(1, &texArray[texID]); 

	    glBindTexture(GL_TEXTURE_2D, texArray[texID]); // bind the texture to the arrays index and initialise the texture
	    
	    int width  = pBitmap[0] -> w;
	    int height = pBitmap[0] -> h;
	    unsigned char * data = (unsigned char *) (pBitmap[0] -> pixels);  // actual pixel data      

	    int BytesPerPixel = pBitmap[0] -> format -> BytesPerPixel;

	    unsigned char *pixels = new unsigned char[width * height * 3];

	    int count = 0;
	    
	    // Extract the r, g and b
	    for(int i = 0; i < (width * height); ++i)
	    {
	        byte r,g,b;                                                

	        Uint32 pixel_value = 0;                                    
	        
	        for(int j = BytesPerPixel - 1 ; j >=0; --j)                
	        {
	            pixel_value = pixel_value << 8;                        
	            pixel_value = pixel_value | data[ (i * BytesPerPixel) + j ];  
	        }                                                                 

	        SDL_GetRGB(pixel_value, pBitmap[0] -> format, (Uint8 *)&r, (Uint8 *)&g, (Uint8 *)&b);     

	        pixels[count++] = r;          
	        pixels[count++] = g;          
	        pixels[count++] = b;          

	        pixel_value = 0;                                           
	    }
	    
	    // builds different versions of the texture for different distances
	    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, pBitmap[0]->w, pBitmap[0]->h, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	  
	    // Quality of texture, Linear = best, Nearest = faster but blotchy
	    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);    
	    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
	    
	    SDL_FreeSurface(pBitmap[0]);                       
}

void SetupPixelFormat(void)
{
    VideoFlags    = SDL_OPENGL;     // Tell SDL we're using OpenGL                    
    VideoFlags   |= SDL_HWPALETTE;  // Tell SADL we have exclusive access to the hardware colour pallette.                     
    VideoFlags   |= SDL_RESIZABLE;  // The windows resizeable                    

    const SDL_VideoInfo * VideoInfo = SDL_GetVideoInfo();   // Get video hardware info  

    if(VideoInfo == NULL)                                     
    {
        cerr << "Failed getting Video Info : " << SDL_GetError() << endl;          
        Quit(0);
    }

    if(VideoInfo -> hw_available)                      
        VideoFlags |= SDL_HWSURFACE; // If we have a graphics card
    else
        VideoFlags |= SDL_SWSURFACE; // Otherwise we're running opengl in software mode

    if(VideoInfo -> blit_hw)                            
        VideoFlags |= SDL_HWACCEL; // Use Blitting if its there

	// Tell SDL to set some OpenGL stuff
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );         // tell SDL that the GL drawing is going to be double buffered
	SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE,   SDEPTH);         // size of depth buffer 
	SDL_GL_SetAttribute( SDL_GL_STENCIL_SIZE, 0);       	// we aren't going to use the stencil buffer
	SDL_GL_SetAttribute( SDL_GL_ACCUM_RED_SIZE, 0);     
	SDL_GL_SetAttribute( SDL_GL_ACCUM_GREEN_SIZE, 0);   
	SDL_GL_SetAttribute( SDL_GL_ACCUM_BLUE_SIZE, 0);
	SDL_GL_SetAttribute( SDL_GL_ACCUM_ALPHA_SIZE, 0);
}

void SizeOpenGLScreen(int w, int h)            
{
	// make our viewport cover whole window.
	glViewport(0,0,w,h);                

	glMatrixMode(GL_PROJECTION);                        
	glLoadIdentity();                                   

	// Aspect ratio of window, 
	// i.e > view angle, aspect ratio of width to height, closest distance before it clips 
	// and furtherest distance before it stops drawing
	gluPerspective(45.0f,(GLfloat)w/(GLfloat)h, .5f ,10000.0f);

	glMatrixMode(GL_MODELVIEW);                                                             
}

void InitializeGL(int width, int height)
{       

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);                              

	glEnable(GL_COLOR_MATERIAL); 

	// Depth testing makes sure objects closer will be drawn in front of objects further away
	glEnable( GL_DEPTH_TEST );  

	// Enable Texturing                           
	glEnable( GL_TEXTURE_2D );       					  

	SizeOpenGLScreen(width, height);                    
}

int main(void)
{
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) 	// try to initialize SDL video module               
    {
        cerr << "Failed initializing SDL Video : " << SDL_GetError() << endl;      
        return 1;
    }

    SetupPixelFormat();

    CreateWindow("Game", SWIDTH, SHEIGHT, VideoFlags);

    Init();

    MainGameLoop();

    return 0;
}

void Quit(int ret_val)
{
    SDL_Quit();
    exit(ret_val);                                        
}
