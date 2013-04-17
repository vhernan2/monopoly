/**********************************************
 * The menu header had definitions for the    *
 * various menus that are used throughout the *
 * game.                                      *
 *********************************************/

#ifndef MENU_H
#include "functions.h"

//Window Attributes
const int SCREEN_WIDTH = 840;
const int SCREEN_HEIGHT = 840;
const int SCREEN_BPP = 32;
int x, y; // used for offsets
SDL_Surface *screen = NULL;
bool xOut = false;

void startMenu(){
  SDL_WM_SetCaption( "Monopoly - Start", "Monopoly");
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    SDL_Flip(screen);
    SDL_Delay(2000);
}

void optionsMenu(){

}

void creditsMenu(){

}

void highscoresMenu(){

}

void quitMenu(){
  SDL_WM_SetCaption("Are You Sure?", "Quit");
  screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
  SDL_Surface *verifyQuit = NULL;
  SDL_Delay(2000);
  
}

// the main menu function will display the main menu for the game
void mainMenu(){

  SDL_Event mainMenuEvent;
  SDL_Surface *background = NULL;
  SDL_Surface *start = NULL;
  SDL_Surface *options = NULL;
  SDL_Surface *credits = NULL;
  SDL_Surface *highscores = NULL;
  SDL_Surface *quit = NULL;
  

  screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
  // SET WINDOW CAPTION
  SDL_WM_SetCaption( "Monopoly - Main Menu" , "Monopoly");
  // Load and Apply background
  //  background = loadImage
  //blit

  // Load images
  start = loadImage("data/START.bmp");
  options = loadImage("data/OPTIONS.bmp");
  credits = loadImage("data/CREDITS.bmp");
  highscores = loadImage("data/HIGHSCORES.bmp");
  quit = loadImage("data/QUIT.bmp");
  std::cout << "All images loaded.";


  // place buttons 
  blit(512, 450, start, screen);
  blit(512, 500, options, screen);
  blit(512, 550,  credits, screen);
  blit(512, 600, highscores, screen);
  blit(512, 650, quit, screen);
  
  // Update screen
  if (SDL_Flip( screen ) == -1 ){
    std::cout << "SCREEN UPDATED";
    SDL_Flip(screen);
  }

  // HANDLE EVENTS
  // HANDLE X-OUT
  while (xOut == false){
    while (SDL_PollEvent( &mainMenuEvent )){
      if(mainMenuEvent.type == SDL_QUIT ){
	xOut = true;
      }
      if (mainMenuEvent.type == SDL_MOUSEBUTTONDOWN){
	// If left click
	if(mainMenuEvent.button.button == SDL_BUTTON_LEFT){
	  // get mouse locations
	  x = mainMenuEvent.button.x;
	  y = mainMenuEvent.button.y;
	  if( (x > 450 && x < 550) && (y > 430 && y < 470) ){
	    SDL_FreeSurface(screen);
	    startMenu();
	  }
	  if( (x > 450 && x < 550) && (y > 480 && y < 520) ){
	    SDL_FreeSurface(screen);
	    startMenu();
	  }
	  if( (x > 450 && x < 550) && (y > 530 && y < 570) ){
	    SDL_FreeSurface(screen);
	    startMenu();
	  }
	  if( (x > 450 && x < 550) && (y > 440 && y < 480) ){
	    SDL_FreeSurface(screen);
	    startMenu();
	  }
	  if( (x > 450 && x < 550) && (y > 440 && y < 480) ){
	    SDL_FreeSurface(screen);
	    startMenu();
	  }
	}
	if(mainMenuEvent.button.button == SDL_BUTTON_RIGHT){
	  std::cout << "Right Click Disabled.";

	}
      }
    }

  }
  // Free surfaces

}



#endif
