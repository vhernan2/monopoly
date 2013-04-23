#include "SDL_logic.h"

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

SDL_logic::SDL_logic(){

}

SDL_logic::~SDL_logic(){

}

void apply_surface( int x, int y, SDL_Surface* source )
{
        //Temporary rectangle to hold the offsets
        SDL_Rect offset;

        //Get the offsets
        offset.x = x;
        offset.y = y;

	//Blit the surface
//	SDL_BlitSurface( source, NULL, destination, &offset );
}
                        

char SDL_logic::getResponse(){

	bool quit = false;
        char c;

        while (quit == false) {
                while( SDL_PollEvent( &event ) ){
                        if (event.type == SDL_KEYDOWN){
                                switch (event.key.keysym.sym){
				case SDLK_SPACE:
					c = 'n';
					quit = true;
					break;
                                case SDLK_b:
                                        c = 'b';
                                        quit = true;
                                        break;
                                case SDLK_n:
                                        c = 'n';
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

