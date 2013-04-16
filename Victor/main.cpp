#include <iostream>
#include <string>
#include "functions.h"
#include "button.h"
//#include "SDL/SDL.h"
using namespace std;

// global variables

//Window Attributes
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 680;
const int SCREEN_BPP = 32;





// the main menu function will display the main menu for the game
void mainMenu(){

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

  screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
  // SET WINDOW CAPTION
  SDL_WM_SetCaption( "Monopoly - Main Menu" , NULL);
  // Load and Apply background
  //  background = loadImage
  //blit
  /*
  // Load images
  start = loadImage("data/START.bmp");
  options = loadImage("data/OPTIONS.bmp");
  credits = loadImage("data/CREDITS.bmp");
  highscores = loadImage("data/HIGHSCORES.bmp");
  quit = loadImage("data/QUIT.bmp");


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
  
  // Update screen
  if (SDL_Flip( screen ) == -1 ){
    cout << "SCREEN UPDATED";
    SDL_Flip(screen);
  }

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

}

int main (int argc, char* argv[]){
 SDL_Init(SDL_INIT_EVERYTHING);

  // ensure that SDL subsystems are up and running
  if ( SDL_Init (SDL_INIT_EVERYTHING ) ==1 ){
    cout << "ERROR INITIALIZING SDL" << endl;
  }


  mainMenu();

  
}
