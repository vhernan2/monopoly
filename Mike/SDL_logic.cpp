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

