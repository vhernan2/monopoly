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
	int mouseX, mouseY;

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
                                                        c = 24;
                                                        quit = true;
                                                }
						if( (mouseX > 150+99 && mouseX <150+158) && (mouseY > 150+47 && mouseY < 150+105) ){ 
                                                        c = 23;
                                                        quit = true;
                                                }
						if( (mouseX > 150+188 && mouseX <150+246) && (mouseY > 150+48 && mouseY < 150+106) ){ 
                                                        c = 21;
                                                        quit = true;
                                                }
						if( (mouseX > 150+20 && mouseX <150+78) && (mouseY > 150+126 && mouseY < 150+184) ){ 
                                                        c = 39;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+102 && mouseX <150+162) && (mouseY > 150+126 && mouseY < 150+184) ){
                                                        c = 37;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+22 && mouseX <150+80) && (mouseY > 150+207 && mouseY < 150+264) ){
                                                        c = 6;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+107 && mouseX <150+166) && (mouseY > 150+207 && mouseY < 150+265) ){
                                                        c = 8;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+198 && mouseX <150+257) && (mouseY > 150+209 && mouseY < 150+267) ){
                                                        c = 9;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+22 && mouseX <150+80) && (mouseY > 150+279 && mouseY < 150+336) ){
                                                        c = 3;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+107 && mouseX <150+165) && (mouseY > 150+279 && mouseY < 150+336) ){
                                                        c = 1;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+30 && mouseX <150+87) && (mouseY > 150+355 && mouseY < 150+412) ){
                                                        c = 26;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+108 && mouseX <150+166) && (mouseY > 150+355 && mouseY < 150+412) ){
                                                        c = 27;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+188 && mouseX <150+246) && (mouseY > 150+356 && mouseY < 150+412) ){
                                                        c = 29;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+34 && mouseX <150+90) && (mouseY > 150+429 && mouseY < 150+486) ){
                                                        c = 34;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+112 && mouseX <150+169) && (mouseY > 150+430 && mouseY < 150+486) ){
                                                        c = 32;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+190 && mouseX <150+248) && (mouseY > 150+429 && mouseY < 150+485) ){
                                                        c = 31;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+312 && mouseX <150+370) && (mouseY > 150+58 && mouseY < 150+115) ){
                                                        c = 16;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+394 && mouseX <150+452) && (mouseY > 150+56 && mouseY < 150+113) ){
                                                        c = 18;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+467 && mouseX <150+524) && (mouseY > 150+56 && mouseY < 150+111) ){
                                                        c = 19;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+315 && mouseX <150+372) && (mouseY > 150+130 && mouseY < 150+186) ){
                                                        c = 14;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+394 && mouseX <150+452) && (mouseY > 150+130 && mouseY < 150+186) ){
                                                        c = 13;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+471 && mouseX <150+529) && (mouseY > 150+130 && mouseY < 150+186) ){
                                                        c = 11;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+394 && mouseX <150+451) && (mouseY > 150+214 && mouseY < 150+270) ){
                                                        c = 35;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+470 && mouseX <150+527) && (mouseY > 150+213 && mouseY < 150+270) ){
                                                        c = 25;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+395 && mouseX <150+453) && (mouseY > 150+284 && mouseY < 150+340) ){
                                                        c = 5;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+474 && mouseX <150+531) && (mouseY > 150+283 && mouseY < 150+337) ){
                                                        c = 15;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+396 && mouseX <150+452) && (mouseY > 150+355 && mouseY < 150+412) ){
                                                        c = 12;
                                                        quit = true;
                                                }
                                                if( (mouseX > 150+475 && mouseX <150+531) && (mouseY > 150+356 && mouseY < 150+411) ){
                                                        c = 28;
                                                        quit = true;
                                                }


					}
					if ((type == 2) || (type == 99)){
						if( (mouseX > 150+75 && mouseX <150+225) && (mouseY > 150+225 && mouseY < 150+375) ){
                                                        c = 'h';
                                                        quit = true;
                                                }
						if( (mouseX > 150+325 && mouseX <150+425) && (mouseY > 150+225 && mouseY < 150+375) ){
                                                        c = 'l';
                                                        quit = true;
                                                }
						if( (mouseX > 150+425 && mouseX <150+525) && (mouseY > 150+425 && mouseY < 150+525) ){
                                                        c = 'e';
                                                        quit = true;
                                                }
					}
					if ((type == 21) || (type == 99)){
						if( (mouseX > 150+25 && mouseX <150+125) && (mouseY > 150+150 && mouseY < 150+250) ){
                                                        c = 1;
                                                        quit = true;
                                                }
						if( (mouseX > 150+150 && mouseX <150+250) && (mouseY > 150+150 && mouseY < 150+250) ){
                                                        c = 2;
                                                        quit = true;
                                                }
						if( (mouseX > 150+275 && mouseX <150+375) && (mouseY > 150+150 && mouseY < 150+250) ){
                                                        c = 3;
                                                        quit = true;
                                                }
						if( (mouseX > 150+400 && mouseX <150+500) && (mouseY > 150+150 && mouseY < 150+250) ){
                                                        c = 4;
                                                        quit = true;
                                                }
						if( (mouseX > 150+425 && mouseX <150+525) && (mouseY > 150+425 && mouseY < 150+525) ){
                                                        c = 'q';
                                                        quit = true;
                                                }
					}
					if ((type == 22) || (type == 99)){
						if( (mouseX > 150+75 && mouseX <150+175) && (mouseY > 150+225 && mouseY < 150+325) ){
                                                        c = 1;
                                                        quit = true;
                                                }
						if( (mouseX > 150+375 && mouseX <150+475) && (mouseY > 150+225 && mouseY < 150+325) ){
                                                        c = 0;
                                                        quit = true;
                                                }												
						if( (mouseX > 150+425 && mouseX <150+525) && (mouseY > 150+425 && mouseY < 150+525) ){
                                                        c = 'q';
                                                        quit = true;
                                                }
					}
					if ((type == 3) || (type == 99)){
						cout << "entered 3" << endl;
						if( (mouseX >150+386 && mouseX <150+536) && (mouseY > 150+486 && mouseY < 150+544) ){
							c = 'c';
							quit = true;
						}
						if( (mouseX >150+128 && mouseX <150+383) && (mouseY > 150+125 && mouseY < 150+175) ){
                                                        c = '0';
                                                        quit = true;
                                                }
                                                if( (mouseX >150+127 && mouseX <150+383) && (mouseY > 150+210 && mouseY < 150+260) ){
                                                        c = '1';
                                                        quit = true;
                                                }
                                                if( (mouseX >150+127 && mouseX <150+381) && (mouseY > 150+297 && mouseY < 150+347) ){
                                                        c = '2';
                                                        quit = true;
                                                }
                                                if( (mouseX >150+125 && mouseX <150+379) && (mouseY > 150+377 && mouseY < 150+426) ){
                                                        c = '3';
                                                        quit = true;
                                                }
                                                if( (mouseX >150+122 && mouseX <150+377) && (mouseY > 150+460 && mouseY < 150+509) ){
                                                        c = '4';
                                                        quit = true;
                                                }

					}
					if ((type == 31) || (type == 99)){
						if( (mouseX >150+25 && mouseX <150+125) && (mouseY > 150+425 && mouseY < 150+525) ){
							c = 'y';
							quit = true;
						}
                                                if( (mouseX >150+425 && mouseX <150+525) && (mouseY > 150+425 && mouseY < 150+525) ){
						        c = 'n';
                                                        quit = true;
                                                }
					}
					if (type == 99){
						c = '['; //return a blank value
						quit = true;
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

