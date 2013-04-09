/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

//Screen attributes
const int SCREEN_WIDTH = 840;
const int SCREEN_HEIGHT = 840;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *background = NULL;
SDL_Surface *battleship = NULL;
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

using namespace std;

class Battleship {
    public:
    Battleship();
    void move();
    int getX();
    int getY();

    private:
    int x, y;

};

Battleship::Battleship() {
    x = 720;
    y = 780;
}

void Battleship::move(){
   if ((x == 720) && (y == 780)) x = 20;
   else {
	if ((x == 20) && (y == 780)) y = 60;
	else {
            if ((x == 20) && (y == 60)) x = 720;
	    else {
		if ((x == 720) && (y == 60)) y = 780;
	    }
	}
   }
}

int Battleship::getX(){
	return x;
}

int Battleship::getY(){
	return y;
}

SDL_Surface *load_image( string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized image that will be used
    SDL_Surface* optimizedImage = NULL;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );

    //If the image loaded
    if( loadedImage != NULL )
    {
        //Create an optimized image
        optimizedImage = SDL_DisplayFormat( loadedImage );

        //Free the old image
        SDL_FreeSurface( loadedImage );

        //If the image was optimized just fine
        if( optimizedImage != NULL )
        {
            //Map the color key
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0xFF, 0xFF, 0xFF );

            //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }
    }

    //Return the optimized image
    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
{
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Get the offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, destination, &offset );
}

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return 1;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Foo says \"Hello!\"", NULL );

    //If everything initialized fine
    return true;
}

bool load_files()
{
    //Load the background image
    background = load_image( "DuLacpoly_840.png" );

    //If the background didn't load
    if( background == NULL )
    {
        return false;
    }

    //Load the stick figure
    battleship = load_image( "Little_Battleship.png" );

    //If the stick figure didn't load
    if( battleship == NULL )
    {
        return false;
    }

    return true;
}

void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface( background );
    SDL_FreeSurface( battleship );

    //Quit SDL
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //Load the files
    if( load_files() == false )
    {
        return 1;
    }

    //Create the battleship object
    Battleship ship;

    //Apply the surfaces to the screen
    apply_surface( 0, 0, background, screen );
    apply_surface( ship.getX(), ship.getY(), battleship, screen );

    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }

    //While the user hasn't quit
    while( quit == false )
    {
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {

	    if (event.type == SDL_KEYDOWN){
		switch (event.key.keysym.sym){
		    case SDLK_SPACE:
			apply_surface(0, 0, background, screen);
			ship.move();
			apply_surface(ship.getX(), ship.getY(), battleship, screen);
		    break;		    
		}
		SDL_Flip(screen);
	    }

            //If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }
    }

    //Free the surfaces and quit SDL
    clean_up();

    return 0;
}
