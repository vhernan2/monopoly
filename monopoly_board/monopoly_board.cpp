/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <fstream>

#include "Mike/Player.h"
#include "Mike/Tile.h"
#include "Mike/Board.h"
#include "Mike/Property.h"
#include "Mike/Game.h"
#include "Mike/CardSpaces.h"
#include "Mike/Bland.h"
#include "Mike/Tax.h"
#include "Mike/Jail.h"
#include "Mike/Utility.h"


//Screen attributes
const int SCREEN_WIDTH = 840;
const int SCREEN_HEIGHT = 840;
const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *background = NULL;
SDL_Surface *piece[8];
//SDL_Surface *piece2 = NULL;
//SDL_Surface *piece3 = NULL;
//SDL_Surface *piece4 = NULL;
//SDL_Surface *piece5 = NULL;
//SDL_Surface *piece6 = NULL;
//SDL_Surface *piece7 = NULL;
//SDL_Surface *piece8 = NULL;

SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

using namespace std;

class PlayerPiece {
    public:
    PlayerPiece();
    void move(int);
    int getX();
    int getY();

    private:
    int x, y;

};

PlayerPiece::PlayerPiece() {
    x = 720;
    y = 780;
}

void PlayerPiece::move(int location){

    if (location <= 10) y = 790;
    if ((location > 10) && (location <=20 )) x = 20;
    if ((location > 20) && (location <=30 )) y = 20;
    if (location > 30) x = 765;

    switch (location) {

	case 0:
		x = 745;
		break;
	case 1:
	case 29:
		x = 656;
		break;
	case 2:
	case 28:
		x = 592;
		break;
	case 3:
	case 27:
		x = 522;
		break;
	case 4:
	case 26:
		x = 461;
		break;
	case 5:
	case 25:
		x = 397;
		break;
	case 6:
	case 24:
		x = 328;
		break;
	case 7:
	case 23:
		x = 266;
		break;
	case 8:
	case 22:
		x = 200;
		break;
	case 9:
	case 21:
		x = 138;
		break;
	case 10:
		x = 9;
		y = 791;
		break;
	case 11:
	case 39:
		y = 651;
		break;
	case 12:
	case 38:
		y = 586;
		break;
	case 13:
	case 37:
		y = 521;
		break;
	case 14:
	case 36:
		y = 458;
		break;
	case 15:
	case 35:
		y = 391;
		break;
	case 16:
	case 34:
		y = 326;
		break;
	case 17:
	case 33:
		y = 265;
		break;
	case 18:
	case 32:
		y = 198;
		break;
	case 19:
	case 31:
		y = 136;
		break;
	case 20:
		x = 30;
		y = 36;
		break;
	case 30:
		//This is the go to jail
		x = 45;
		y = 739;
		break;
	default:
		//go to center of the board - all is wrong if this happens
		x = 400;
		y = 400;
		break;

    }
	
}

int PlayerPiece::getX(){
	return x;
}

int PlayerPiece::getY(){
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

bool load_files(int numPlayers)
{
    //Load the background image
    background = load_image( "DuLacpoly_840.png" );

    //If the background didn't load
    if( background == NULL )
    {
        return false;
    }

    string input;

    ifstream dataFile ("image_folder.txt");

    int count = 0;

    string names[numPlayers];

    while(dataFile.is_open()){
           while(dataFile.good() && (count < numPlayers)){
                    getline(dataFile, input);
                    names[count] = input;
                    count++;
            }
            dataFile.close();
    }

    //Load the piece figure
    piece[0] = load_image( "Images/" + names[0] );
    piece[1] = load_image( "Images/" + names[1] );
    piece[2] = load_image( "Images/" + names[2] );
    piece[3] = load_image( "Images/" + names[3] );

    //If the piece figure didn't load
//    if( pieceObject == NULL )
//    {
//        return false;
//    }

    return true;
}

void clean_up()
{
    //Free the surfaces
    SDL_FreeSurface( background );
    for(int i = 0; i < 8; i++) { SDL_FreeSurface( piece[i] ); }
//    SDL_FreeSurface( piece2 );
//    SDL_FreeSurface( piece3 );
//    SDL_FreeSurface( piece4 );
//    SDL_FreeSurface( piece5 );
//    SDL_FreeSurface( piece6 );
//    SDL_FreeSurface( piece7 );
//    SDL_FreeSurface( piece8 );


    //Quit SDL
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //========================
    //Initialize a game
    Game playGame;
    int players = playGame.getPlayers();
    int currentPlayer;
    //========================	

    

    //Quit flag
    bool quit = false;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    //Load the files
    if( load_files(players) == false )
    {
        return 1;
    }

    //Create the piece objects
    PlayerPiece unique_piece[players];

    cout << "Right before Applying the surfaces" << endl;

    //Apply the surfaces to the screen
    apply_surface( 0, 0, background, screen );
    for (int i = 0; i < players; i++) { apply_surface( unique_piece[i].getX(), unique_piece[i].getY(), piece[i], screen ); }

    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
        return 1;
    }

    cout << "Begin playing " << endl;

    //While the user hasn't quit
    while( quit == false )
    {
        //While there's events to handle
        while( SDL_PollEvent( &event ) )
        {

	    if (event.type == SDL_KEYDOWN){
		switch (event.key.keysym.sym){
		    case SDLK_SPACE:
			playGame.turn();
			currentPlayer = playGame.getCurrentPlayer();
			cout << currentPlayer << endl;
			apply_surface(0, 0, background, screen);
			cout << "Player " << currentPlayer << " position: "<<playGame.getPlayerLocation(currentPlayer)<<endl;
			unique_piece[currentPlayer].move(playGame.getPlayerLocation(currentPlayer));
			for (int i = 0; i < players; i++ ) { 
				apply_surface(unique_piece[i].getX(), unique_piece[i].getY(), piece[i], screen); 
				cout << "Player " << i << "- (" << unique_piece[i].getX() << "," << unique_piece[i].getY() << ")\n";
			}
		    break;
		    case SDLK_ESCAPE:
			quit = true;
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
