#include "SDL_logic.h"

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

SDL_logic::SDL_logic(){

}

SDL_logic::~SDL_logic(){

}

char SDL_logic::getResponse(){

	bool quit = false;
        char c;

        while (quit == false) {
                while( SDL_PollEvent( &event ) ){
                        if (event.type == SDL_KEYDOWN){
                                switch (event.key.keysym.sym){
                                case SDLK_b:
                                        c = 'b';
                                        quit = true;
                                        break;
                                case SDLK_n:
                                        c = 'n';
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

