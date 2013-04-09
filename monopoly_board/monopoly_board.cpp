/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//Include SDL functions and datatypes
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

const int SCREEN_WIDTH = 840;
const int SCREEN_HEIGHT = 840;
const int SCREEN_BPP = 32;

SDL_Surface *image = NULL; 
SDL_Surface *screen = NULL;

SDL_Event event;

using namespace std;

SDL_Surface *load_image( string filename ) {

    //Temporary storage for the image that's loaded 
    SDL_Surface* loadedImage = NULL; 
    //The optimized image that will be used 
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    if( loadedImage != NULL ) { 
        //Create an optimized image 
        optimizedImage = SDL_DisplayFormat( loadedImage ); 
        //Free the old image 
        SDL_FreeSurface( loadedImage );
    }

    return optimizedImage;

} 

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination ) {

    SDL_Rect offset;
    offset.x = x;
    offset.y = y;

    SDL_BlitSurface( source, NULL, destination, &offset );

}

bool init(){
    //Initialize all SDL subsystems
    
    if ( SDL_Init( SDL_INIT_EVERYTHING ) == -1) {
	return false;
    }

    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    if (screen == NULL) {
	return false;
    }

    SDL_WM_SetCaption( "Monopoly Board", NULL);

    return true;
}

bool load_files(){
    image = load_image( "DuLacpoly_840.png" );

    if( image == NULL ) {
	return false;
    }

    return true;

}

void clean_up(){

    SDL_FreeSurface( image );

    SDL_Quit();

}

int main( int argc, char* args[] )
{
   
    bool quit = false;

    if( init() == false ) return 1;

    if (load_files() == false ) return 1;

    apply_surface( 0, 0, image, screen );

    //Update Screen
    if (SDL_Flip( screen ) == -1){
	return -1;
    }

    while (quit == false) {
        while (SDL_PollEvent(&event)){
	    if(event.type == SDL_QUIT) {
		quit = true;
	    }
	}
    }

    //Free the loaded image
    clean_up();

    //Quit SDL
    SDL_Quit();

    return 0;
}
