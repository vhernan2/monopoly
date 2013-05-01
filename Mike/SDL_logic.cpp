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
			if (event.type == SDL_QUIT){
				c = 'q';
				quit = true;
			}
//=======================================

/*
			if (event.type == SDL_MOUSEBUTTONDOWN){
if(event.button.button == SDL_BUTTON_LEFT){
                mouseX = event.button.x;
                mouseY = event.button.y;
                if( (mouseX > 150+329 && mouseX <150+507) && (mouseY > 500+57 && mouseY < 500+102) ){ 
                  c = 'r';
                  quit = true;
                }
                else if( (mouseX > 150+81 && mouseX < 150+214 ) && (mouseY > 500+60 && mouseY < 500+102) ){ 
                  c = 'v';
                  quit = true;
                }
                else if( (mouseX > 150+15 && mouseX < 150+281 ) && (mouseY > 500+7 && mouseY < 500+57) ){ 
                  c = 'm';
                  quit = true;
                }
                else if( (mouseX > 150+361 && mouseX < 150+513 ) && (mouseY > 500+10 && mouseY<500+56) ){ 
                  c = 'b';
                  quit = true;
                }
              }    
            }

*/

//=======================================
//=======================================

/*

if (event.type == SDL_MOUSEBUTTONDOWN){
              if(event.button.button == SDL_BUTTON_LEFT){
                mouseX = event.button.x;
                mouseY = event.button.y;
                if( (mouseX > 150+398 && mouseX <150+479) && (mouseY > 150+504 && mouseY < 150+541) ){
                  c = 'r';
                  quit = true;
                }
                else if( (mouseX > 150+81 && mouseX < 150+214 ) && (mouseY > 150+504 && mouseY < 150+540) ){
                  c = 'v';
                  quit = true;
                }
                else if( (mouseX > 150+15 && mouseX < 150+281 ) && (mouseY > 150+454 && mouseY < 150+538) ){
                  c = 'm';
                  quit = true;
                }
                else if( (mouseX > 150+361 && mouseX < 150+513 ) && (mouseY > 150+455 && mouseY<150+500) ){
                  c = 'y';
                  quit = true;
                }
              }
            }

*/

//=======================================
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

