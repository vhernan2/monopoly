#include <iostream>
#include <string>
<<<<<<< HEAD
#include "SDL/SDL.h"
=======
#include "functions.h"
<<<<<<< HEAD
#include "menu.h"
=======
#include "button.h"
//#include "SDL/SDL.h"
>>>>>>> 4653ecbc581dc7f31defaa4af38fb33a299dd40f
>>>>>>> 5ec428ac91c515961b36804a335a9a02fe961fc2
using namespace std;

// global variables


<<<<<<< HEAD
// loadImage function will be used to load any image used for the game
SDL_Surface *loadImage( string fileName ){

<<<<<<< HEAD
=======
  SDL_Surface* loaded = NULL;   // temp storage for laoded image
  SDL_Surface* optimized = NULL;
  loaded = SDL_LoadBMP( fileName.c_str() );   // load

  // verify loaded and continue
  if( loaded != NULL ){
    optimized = SDL_DisplayFormat(loaded);     // optimize
    SDL_FreeSurface( loaded );     // Free old 
  }
  return optimized;
}

// Surface Blitting Function
void blit(int x, int y, SDL_Surface* source, SDL_Surface* destination){

  SDL_Rect offset;

  offset.x = x;
  offset.y = y;

  SDL_BlitSurface( source, NULL, destination, &offset);

}
=======

>>>>>>> 4653ecbc581dc7f31defaa4af38fb33a299dd40f



// the main menu function will display the main menu for the game
void mainMenu(){

<<<<<<< HEAD
  SDL_Surface *background = NULL;
  SDL_Surface *start = NULL;
  SDL_Surface *options = NULL;
  SDL_Surface *credits = NULL;
  SDL_Surface *highscores = NULL;
  SDL_Surface *quit = NULL;
  SDL_Surface *screen = NULL;
 
=======
  bool xOut = false;
  SDL_Event mainMenuEvent;
  SDL_Surface *background = NULL;
  /*  SDL_Surface *start = NULL;
  SDL_Surface *options = NULL;
  SDL_Surface *credits = NULL;
  SDL_Surface *highscores = NULL;
  SDL_Surface *quit = NULL;*/
  SDL_Surface *mainMenuButtons = NULL;
  SDL_Surface *screen = NULL;
  SDL_Rect clip[5]; // hold offsets & dimensions for buttons

>>>>>>> 4653ecbc581dc7f31defaa4af38fb33a299dd40f
  screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
  // SET WINDOW CAPTION
  SDL_WM_SetCaption( "Monopoly - Main Menu" , NULL);
  // Load and Apply background
  //  background = loadImage
  //blit
<<<<<<< HEAD

=======
  /*
>>>>>>> 4653ecbc581dc7f31defaa4af38fb33a299dd40f
  // Load images
  start = loadImage("data/START.bmp");
  options = loadImage("data/OPTIONS.bmp");
  credits = loadImage("data/CREDITS.bmp");
  highscores = loadImage("data/HIGHSCORES.bmp");
  quit = loadImage("data/QUIT.bmp");

<<<<<<< HEAD
  // place buttons 
  blit(512, 450, start, screen);
  blit(512, 500, options, screen);
  blit(512, 550, highscores, screen);
  blit(512, 600, credits, screen);
  blit(512, 650, quit, screen);
  cout << "All images loaded.";

=======

  cout << "All images loaded.";
  */
  // START BUTTON CLIP
  clip[0].x = 512;
  clip[0].y = 450;
  clip[0].w = 5;
  clip[0].h = 5;
 // OPTIONS BUTTON CLIP
  clip[1].x = 512;
  clip[1].y = 500;
  clip[1].w = 5;
  clip[1].h = 5;
 // HIGHSCORES BUTTON CLIP
  clip[2].x = 512;
  clip[2].y = 550;
  clip[2].w = 5;
  clip[2].h = 5;
 // CREDITS BUTTON CLIP
  clip[3].x = 512;
  clip[3].y = 600;
  clip[3].w = 5;
  clip[3].h = 5;
 // QUIT BUTTON CLIP
  clip[4].x = 512;
  clip[4].y = 650;
  clip[4].w = 5;
  clip[4].h = 5;

  // place buttons 
  blit(512, 450, mainMenuButtons, screen, &clip[0] );
  blit(512, 500, mainMenuButtons, screen, &clip[1] );
  blit(512, 550,  mainMenuButtons, screen, &clip[2] );
  blit(512, 600, mainMenuButtons, screen, &clip[3] );
  blit(512, 650, mainMenuButtons, screen, &clip[4] );
  
>>>>>>> 4653ecbc581dc7f31defaa4af38fb33a299dd40f
  // Update screen
  if (SDL_Flip( screen ) == -1 ){
    cout << "SCREEN UPDATED";
    SDL_Flip(screen);
  }

<<<<<<< HEAD
  SDL_Delay(10000);
  SDL_FreeSurface( start );
  SDL_FreeSurface( options );
  SDL_FreeSurface( highscores );
  SDL_FreeSurface( credits );
  SDL_FreeSurface( quit );
  SDL_FreeSurface( screen );
=======
  // HANDLE EVENTS
  // HANDLE X-OUT
  while (xOut == false){
    while (SDL_PollEvent( &mainMenuEvent )){
      if(mainMenuEvent.type == SDL_QUIT ){
	xOut = true;
      }
    }

  }
  SDL_FreeSurface( mainMenuButtons );
>>>>>>> 4653ecbc581dc7f31defaa4af38fb33a299dd40f

}

>>>>>>> 5ec428ac91c515961b36804a335a9a02fe961fc2
int main (int argc, char* argv[]){
 SDL_Init(SDL_INIT_EVERYTHING);

  // ensure that SDL subsystems are up and running
  if ( SDL_Init (SDL_INIT_EVERYTHING ) ==1 ){
    cout << "ERROR INITIALIZING SDL" << endl;
  }


  mainMenu();
<<<<<<< HEAD
  SDL_Delay(2000);
=======
>>>>>>> 4653ecbc581dc7f31defaa4af38fb33a299dd40f

  
}
