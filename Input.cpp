#include "main.h"

extern bool w, s, a, d, u, p, l, r;

void HandleKeyDownEvent(SDL_keysym * keysym)
{
    switch(keysym -> sym)			
    {
        case SDLK_ESCAPE:                                  
            Quit(0);     

		case SDLK_F1 :                       
			ToggleFullScreen();
			break ;

        case SDLK_w :                                  
            w = true;             
            break;
            
        case SDLK_s :                                 
			s = true;
            break;

		case SDLK_a :                                  
            a = true;             
            break;

		case SDLK_d :                                  
            d = true;             
            break;

		case SDLK_UP :                                     
            u = true;                              
            break;
            
		case SDLK_DOWN :                                    
            p = true;                            
            break;

		case SDLK_LEFT :
            l = true;                            
            break;

		case SDLK_RIGHT :
            r = true;     
  
        default:                                           
            break;                                         
    }
}

void HandleKeyUpEvent(SDL_keysym * keysym)
{
    switch(keysym -> sym)			
    { 
        case SDLK_w :                                  
            w = false;             
            break;
            
        case SDLK_s :                                 
			s = false;
            break;
       
		case SDLK_a :                                  
            a = false;             
            break;

		case SDLK_d :                                  
            d = false;             
            break;

		case SDLK_UP :                                     
            u = false;                              
            break;
            
		case SDLK_DOWN :                                    
            p = false;                            
            break;

		case SDLK_LEFT :
            l = false;                           
            break;

		case SDLK_RIGHT :
            r = false;

        default:                                           
            break;                                         
    }
}


