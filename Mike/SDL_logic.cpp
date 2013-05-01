#include "SDL_logic.h"

#include <iostream>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

SDL_logic::SDL_logic(){

}

SDL_logic::~SDL_logic(){

}

void SDL_logic::apply_surface( int x, int y, SDL_Surface* source , SDL_Surface* destination)
{
        //Temporary rectangle to hold the offsets
        SDL_Rect offset;

        //Get the offsets
        offset.x = x;
        offset.y = y;

	//Blit the surface
	SDL_BlitSurface( source, NULL, destination, &offset );
	SDL_Flip(destination);
}
                       
SDL_Surface* SDL_logic::load_files(string filename)
{

    cout << "welcome\n";

    SDL_Surface* loadedImage = NULL;

    SDL_Surface* optimizedImage = NULL;

    loadedImage = IMG_Load( filename.c_str() );

    cout << "loadedImage\n";

    if( loadedImage != NULL )
    {
	cout << "Loaded image exists\n";

    } else { 
	cout <<"Oh no...\n";
    }

    cout << "Return the optimized image\n";

    return loadedImage;
 

}

void SDL_logic::clean_up()
{
}
 

char SDL_logic::getResponse(int type){

	//0 - preRoll/postRoll
	//1 - spritMap
	//99 - hold value (i.e. using this to wait for event)

	bool quit = false;
        char c;

        while (quit == false) {
                while( SDL_PollEvent( &event ) ){
			if (event.type == SDL_QUIT){
				c = 'q';
				quit = true;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN){
				if(event.button.button == SDL_BUTTON_LEFT){
                			mouseX = event.button.x;
                			mouseY = event.button.y;
					if ((type == 0) || (type == 99)) {
	                			if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){ 
			                		c = 'm';
					                quit = true;
				                }
				                else if( (mouseX > 150+33 && mouseX < 150+146 ) && (mouseY > 150+500 && mouseY < 150+536) ){ 
					                c = 'v';
				        	        quit = true;
				        	}
			        	        else if( (mouseX > 150+203 && mouseX < 150+350 ) && (mouseY > 150+503 && mouseY < 150+537) ){ 
					                c = 't';
					                quit = true;
			                	}
				                else if( (mouseX > 150+364 && mouseX < 150+498 ) && (mouseY > 150+461 && mouseY<150+491) ){ 
				                	c = 'b';
				        	        quit = true;
		        		        }
						else if( (mouseX > 150+403 && mouseX < 150+536 ) && (mouseY > 150+508 && mouseY<150+536) ){
                	                                c = 'r';
        	                                        quit = true;
	                                        }
					}
					if ((type == 1) || (type == 99)){
						if( (mouseX > 150+19 && mouseX <150+74) && (mouseY > 150+49 && mouseY < 150+106) ){ 
                                                        c = 0;
                                                        quit = true;
                                                }
						if( (mouseX > 150+99 && mouseX <150+158) && (mouseY > 150+47 && mouseY < 150+105) ){ 
                                                        c = 'm';
                                                        quit = true;
                                                }
						if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){ 
                                                        c = 'm';
                                                        quit = true;
                                                }
						if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){ 
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+59 && mouseX <150+301) && (mouseY > 150+460 && mouseY < 150+490) ){
                                                        c = 'm';
                                                        quit = true;
                                                }


					}
			       }    
			}
                        if (event.type == SDL_KEYDOWN){
                                switch (event.key.keysym.sym){
				case SDLK_SPACE:
					c = 'n';
					quit = true;
					break;
				case SDLK_0:
					c = '0';
					quit = true;
					break;
				case SDLK_1:
					c = '1';
					quit = true;
					break;
				case SDLK_2:
					c = '2';
					quit = true;
					break;
				case SDLK_3:
					c = '3';
					quit = true;
					break;
				case SDLK_4:
					c = '4';
					quit = true;
					break;
				case SDLK_5:
					c = '5';
					quit = true;
					break;
				case SDLK_6:
					c = '6';
					quit = true;
					break;
				case SDLK_7:
					c = '7';
					quit = true;
					break;
				case SDLK_8:
					c = '8';
					quit = true;
					break;
				case SDLK_9:
					c = '9';
					quit = true;
					break;

                                case SDLK_b:
                                        c = 'b';
                                        quit = true;
                                        break;
				case SDLK_c:
					c = 'c';
					quit = true;
					break;
				case SDLK_m:
					c= 'm';
					quit = true;
					break;
                                case SDLK_n:
                                        c = 'n';
                                        quit = true;
                                        break;
				case SDLK_o:
					c = 'o';
					quit = true;
					break;
				case SDLK_q:
					c = 'q';
					quit = true;
					break;
                                case SDLK_r:
                                        c = 'r';
                                        quit = true;
                                        break;
                                case SDLK_t:
                                        c= 't';
                                        quit = true;
                                        break;
                                case SDLK_v:
                                        c='v';
                                        quit = true;
                                        break;
                                case SDLK_y:
                                        c='y';
                                        quit = true;
                                        break;
                                }
                        }
                }
        }
        return c;

}

