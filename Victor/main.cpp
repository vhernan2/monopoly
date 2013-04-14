#include <iostream>
#include <string>
#include "SDL/SDL.h"
using namespace std;

// global variables

//Window Attributes
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 680;
const int SCREEN_BPP = 32;

SDL_Surface *screen;

// loadImage function will be used to load any image used for the game
SDL_Surface *loadImage( string fileName ){

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



// the main menu function will display the main menu for the game
int mainMenu(){

  SDL_Surface *background = NULL;
  SDL_Surface *start = NULL;
  SDL_Surface *options = NULL;
  SDL_Surface *credits = NULL;
  SDL_Surface *highscores = NULL;
  SDL_Surface *quit = NULL;

 
  screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
  // SET WINDOW CAPTION
  SDL_WM_SetCaption( "Monopoly - Main Menu" , NULL);
  // Load and Apply background
  //  background = loadImage
  //blit

  // Load images
  start = loadImage("data/START.bmp");
  options = loadImage("data/OPTIONS.bmp");
  credits = loadImage("data/CREDITS.bmp");
  highscores = loadImage("data/HIGHSCORES.bmp");
  quit = loadImage("data/QUIT.bmp");

  // place buttons 
  blit(512, 450, start, screen);
  blit(512, 500, options, screen);
  blit(512, 550, highscores, screen);
  blit(512, 600, credits, screen);
  blit(512, 650, quit, screen);
  cout << "All images loaded.";

  // Update screen
  if (SDL_Flip( screen ) == -1 ){
    return 1;
  }

  SDL_Delay(10000);
  SDL_FreeSurface( start );
  SDL_FreeSurface( options );
  SDL_FreeSurface( highscores );
  SDL_FreeSurface( credits );
  SDL_FreeSurface( quit );
  SDL_FreeSurface( screen );

  return 0;
}

int main (int argc, char* argv[]){
 SDL_Init(SDL_INIT_EVERYTHING);

  if (screen == NULL){
    return 1;
  }

  // ensure that SDL subsystems are up and running
  if ( SDL_Init (SDL_INIT_EVERYTHING ) ==1 ){
    cout << "ERROR INITIALIZING SDL" << endl;
  }


  mainMenu();
  SDL_Delay(2000);

  
}
