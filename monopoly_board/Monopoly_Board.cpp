/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

#include "Monopoly_Board.h"
#include "PlayerPiece.h"

using namespace std;

SDL_Surface* Monopoly_Board::load_image( string filename )
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
            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF );

            //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }
    }

    //Return the optimized image
    return optimizedImage;
}

void Monopoly_Board::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface *background )
{
    //Temporary rectangle to hold the offsets
    SDL_Rect offset;

    //Get the offsets
    offset.x = x;
    offset.y = y;

    //Blit the surface
    SDL_BlitSurface( source, NULL, background, &offset );
}

bool Monopoly_Board::init()
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
    SDL_WM_SetCaption( "DuLacpoly" , NULL );

    //If everything initialized fine
    return true;
}

bool Monopoly_Board::load_files(int numPlayers)
{
    background = load_image( "DuLacpoly_840.png" );

    if( background == NULL )
    {
        return false;
    }

    piece[0] = load_image( "Piece_Images/Knute_Rockne.png" );
    piece[1] = load_image( "Piece_Images/Guinness.png");
    piece[2] = load_image( "Piece_Images/Claddagh.png" );
    piece[3] = load_image( "Piece_Images/Francis.png");
    piece[4] = load_image( "Piece_Images/Leprechaun.png");
    piece[5] = load_image( "Piece_Images/ND_logo.png");
    piece[6] = load_image( "Piece_Images/Shamrock.png");

    return true;
}

void Monopoly_Board::clean_up()
{
    cout << "Entered\n";
    SDL_FreeSurface( background );
    cout << "Freed background\n";
    for(int i = 0; i < 7; i++) { 
	SDL_FreeSurface( piece[i] ); 
	cout << "Freed piece["<<i<<"]\n";
    }
    
    SDL_Quit();
    
}

Monopoly_Board::Monopoly_Board( int numPlayers )
{
    //========================
    //Initialize a game
    players = numPlayers;//playGame.getPlayers();
    SCREEN_WIDTH = 840;
    SCREEN_HEIGHT = 840;
    SCREEN_BPP = 32;
//    *background = NULL;
  //  *screen = NULL;
    //background = NULL;
    //screen = NULL;

    //========================

    //Quit flag
    bool quit = false;

    //Initialize
    if( init() == false )
    {
	cout << "No init\n";
  //      return 1;
    } else cout << "CHEER ";

    //Load the files
    if( load_files(4) == false )
    {
	cout << "No file load\n";
    //    return 1;
    } else cout << "CHEER FOR ";

    //Apply the surfaces to the screen
    apply_surface( 0, 0, background, screen );
    for (int i = 0; i < players; i++) { 
	apply_surface( unique_piece[i].getX(), unique_piece[i].getY(), piece[i], screen ); 
     }

    //Update the screen
    if( SDL_Flip( screen ) == -1 )
    {
	cout << "No SDL_Flip\n";
      //  return 1;
    } else cout << "OLD NOTRE DAME!\n";

}

Monopoly_Board::~Monopoly_Board(){

}

bool Monopoly_Board::keep_playing(){

    bool quit = false;
    bool forReturn = false;

    //While the user hasn't quit
    while( quit == false )
    {
	    char c = sdl.getResponse(99);
	    switch (c){
	        case 'n':
		    forReturn = true;
		    quit = true;
		    break;
		case 'q':
		    forReturn = false;
		    quit = true;
		break;		    
	    }
	SDL_Flip(screen);
    }

    //Free the surfaces and quit SDL

    return forReturn;
}

void Monopoly_Board::turn(int currentPlayer, int currentLocation){

    apply_surface(0, 0, background, screen);
    unique_piece[currentPlayer].move(currentLocation);
    for (int i = 0; i < players; i++ ) { 
	apply_surface(unique_piece[i].getX(), unique_piece[i].getY(), piece[i], screen); 
	cout << "Player " << i << "- (" << unique_piece[i].getX() << "," << unique_piece[i].getY() << ")\n";
    }
    SDL_Flip(screen);
}

SDL_Surface* Monopoly_Board::getScreen(){
	return screen; 
} 
