/**********************************************
 * The menu header had definitions for the    *
 * various menus that are used throughout the *
 * game.                                      *
 *********************************************/

#ifndef MENU_H
#include "functions.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include <iostream>
#include <fstream>

// incuded functions
void startMenu();
void mainMenu();
//Window Attributes
const int SCREEN_WIDTH = 840;
const int SCREEN_HEIGHT = 840;
const int SCREEN_BPP = 32;
SDL_Surface *screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
int x, y; // used for offsets
bool xOut = false;
SDL_Event mouseEvent;


void cleanUp(){

}

void startMenu(){

  SDL_Surface *namePrompt = NULL;
  SDL_Surface *pieceSelectPrompt = NULL;
  SDL_Color textColor = {255,255,255};  // Text Color
  SDL_Color bColor = {255,255,244};
  SDL_FillRect(screen,NULL, 0x000000);
  SDL_WM_SetCaption( "Monopoly - Start", "Monopoly");

  // Font
  TTF_Font *font = NULL;
  font = TTF_OpenFont("lazy.ttf", 28);

    

  namePrompt = TTF_RenderText_Shaded(font, "Enter your Name Player (value):", textColor,bColor);
    // pieceSelectPrompt = TTF_RenderText_Solid(font, "Select your piece:", textColor);
     blit(100, 200, namePrompt, screen);
     blit(100, 300, pieceSelectPrompt, screen);
   SDL_Flip(screen);
  while (xOut == false){
    while (SDL_PollEvent( &mouseEvent )){
      if(mouseEvent.type == SDL_QUIT ){
	//	SDL_FreeSurface(pieceSelectPrompt);
	//SDL_FreeSurface(namePrompt);
	//	TTF_CloseFont(font);
	//TTF_Quit();

	xOut = true;
      }
    }
  }
}

void optionsMenu(){
  SDL_Surface *optionsScreen = SDL_SetVideoMode( SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP, SDL_SWSURFACE);
  SDL_Surface *soundPrompt = NULL;
  SDL_Surface *onButton = NULL;
  SDL_Surface *offButton = NULL;
  SDL_Surface *okButton = NULL;
  SDL_Surface *cancelButton = NULL;
}

void creditsMenu(){
  SDL_Surface *creditsScreen = SDL_SetVideoMode( SCREEN_WIDTH * (2/3), SCREEN_HEIGHT * (2/3), SCREEN_BPP, SDL_SWSURFACE);
  SDL_Surface *okButton = NULL;
  SDL_Surface *creditsText = NULL;
  //  TTF_Font *font = TTF_OpenFont("lazy.ttf", 28);
  // SDL_Color creditsColor = {100,200,0};
  // creditsText = TTF_RenderText_Solid(font,"credits", creditsColor);
  std::ifstream credits;
  credits.open("credits.txt");
  if (credits.is_open()){
    std::cout << "File opened successfully." << std::endl;
  }
  else std::cout << "Unable to open credits file." << std::endl;
}

void highscoresMenu(){

}

void quitMenu(){
   SDL_WM_SetCaption("Quit?", "Quit");
   SDL_Surface *verifyQuitScreen = NULL;
   SDL_Surface *quitPrompt = NULL;
  // Font
  TTF_Font *font = TTF_OpenFont("lazy.ttf", 28);
  // Text Color
  SDL_Color textColor = {255,255,255};
  quitPrompt = TTF_RenderText_Solid(font, "Are you sure you want to quit?", textColor);
  verifyQuitScreen = SDL_SetVideoMode( SCREEN_WIDTH/2, SCREEN_HEIGHT/5, SCREEN_BPP, SDL_SWSURFACE );
  SDL_WM_SetCaption("Are You Sure?", NULL);
  blit(5,10,quitPrompt,verifyQuitScreen);
  SDL_Flip(verifyQuitScreen);
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
  
  SDL_WM_SetCaption( "Monopoly - Main Menu" , "Monopoly"); // SET WINDOW CAPTION
   
  // Load images
  background = loadImage("data/DuLacpoly_840.png");
  start = loadImage("data/START.bmp");
  options = loadImage("data/OPTIONS.bmp");
  credits = loadImage("data/CREDITS.bmp");
  highscores = loadImage("data/HIGHSCORES.bmp");
  quit = loadImage("data/QUIT.bmp");

  // place buttons
  blit(0,0, background,screen);
  blit(420, 400, start, screen);
  blit(420, 450, options, screen);
  blit(420, 500,  credits, screen);
  blit(400, 550, highscores, screen);
  blit(420, 600, quit, screen);
  
  // display screen
  SDL_Flip(screen);

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
	  if( (x > 420 && x < 470) && (y > 380 && y < 420) ){
	    SDL_FreeSurface(start);
	    SDL_FreeSurface(options);
	    SDL_FreeSurface(credits);
	    SDL_FreeSurface(highscores);
	    SDL_FreeSurface(quit);
	    startMenu();

	  }
	  else if( (x > 420 && x < 470) && (y > 430 && y < 470) ){
	    optionsMenu();
	  }
	  else if( (x > 400 && x < 490) && (y > 480 && y < 520) ){
	    highscoresMenu();
	  }
	  else if( (x > 420 && x < 470) && (y > 530 && y < 570) ){
	    creditsMenu();
	  }
	  else if( (x > 420 && x < 470) && (y > 580 && y < 620) ){
	    quitMenu();
	  }
	}
	else if(mainMenuEvent.button.button == SDL_BUTTON_RIGHT){
	  std::cout << "Right Click Disabled.";

	}
      }
    }

  }
 }

#endif
