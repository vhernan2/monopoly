/**********************************************
 * The menu header had definitions for the    *
 * various menus that are used throughout the *
 * game.                                      *
 *********************************************/

#ifndef MENU_H
#include "functions.h"
#include "SDL/SDL_ttf.h"
#include <iostream>
#include <fstream>

// incuded functions
void startMenu();
void mainMenu();

//Window Attributes
const int SCREEN_WIDTH = 840;
const int SCREEN_HEIGHT = 840;
const int SCREEN_BPP = 32;

// Globals
static int numberOfPlayers;
int x, y; // used for offsets
bool xOut = false; // used to detect xing out of screen

// Font
TTF_Font *font = NULL;
// Text Color
SDL_Color textColor = {255,255,255};
SDL_Color bColor = {0,0,0};

SDL_Surface *screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
SDL_Surface *quit = loadImage("data/QUIT.bmp");
SDL_Surface *mainMenuButton = loadImage("data/mainMenu.bmp"); // like quit

SDL_Event mouseEvent; // used to detect mouse clicks
SDL_Event keyPress; // used to detect a key press

void cleanUp(){
	TTF_CloseFont(font);
	TTF_Quit();

}

void startMenu(){

  SDL_Surface *namePrompt = NULL;
  SDL_Surface *pieceSelectPrompt = NULL;
  SDL_Surface *b1 = NULL, *b2 = NULL, *b3 = NULL, *b4 = NULL, *b5 = NULL, *b6 = NULL;
  SDL_Color textColor = {255,255,255};  // Text Color
  SDL_Color bColor = {0,0,0};
  SDL_FillRect(screen,NULL, 0x000000);
  SDL_WM_SetCaption( "Monopoly - Start", "Monopoly");

  // Font


  if (font == NULL)
    mainMenu();
    
  // Load buttons
  b1 = loadImage("data/1.bmp");
  b2 = loadImage("data/2.bmp");
  b3 = loadImage("data/3.bmp");
  b4 = loadImage("data/4.bmp");
  b5 = loadImage("data/5.bmp");
  b6 = loadImage("data/6.bmp");

  namePrompt = TTF_RenderText_Shaded(font, "How Many Players will be participating today?:", textColor,bColor);
  // pieceSelectPrompt = TTF_RenderText_Solid(font, "Select your piece:", textColor);
     blit(10, 200, namePrompt, screen);
     blit(170, 250, b1, screen);
     blit(220, 250, b2, screen);
     blit(270, 250, b3, screen);
     blit(320, 250, b4, screen);
     blit(370, 250, b5, screen);
     blit(420, 250, b6, screen);
     blit(200, 500, quit, screen);
     blit(100, 500, mainMenuButton,screen);

   SDL_Flip(screen);
  
  while (xOut == false){
    while (SDL_PollEvent( &mouseEvent )){  
      if (mouseEvent.type == SDL_QUIT){
	xOut = true;
	SDL_FreeSurface(namePrompt);
      }
      else if (mouseEvent.type == SDL_MOUSEBUTTONDOWN){
	// If left click
	if(mouseEvent.button.button == SDL_BUTTON_LEFT){
	  // get mouse locations
	  x = mouseEvent.button.x;
	  y = mouseEvent.button.y; 
	  if ( (x > 170 && x < 180) && (y > 250 && y < 270) ) { // if one player
	    SDL_FreeSurface(b1);
	    b1 = loadImage("data/1pressed.bmp");
	    blit(170, 250, b1, screen);
	    SDL_Flip(screen);
	    numberOfPlayers=1;
	  }
	  else if ( (x > 220 && x < 230) && (y > 250 && y < 270) ) { // two players
	    b2 = loadImage("data/2pressed.bmp");
	    numberOfPlayers=2;
	  }
	  else if ( (x > 270 && x < 280) && (y > 250 && y < 270) ) { // 3 players
	    b3 = loadImage("data/3pressed.bmp");
	    numberOfPlayers=3;
	  }
	  else if ( (x > 320 && x < 330) && (y > 250 && y < 270) ) { // 4 players
	    b4 = loadImage("data/4pressed.bmp");
	    numberOfPlayers=4;
	  }
	  else if ( (x > 370 && x < 380) && (y > 250 && y < 270) ) { // 5 players
	    b5 = loadImage("data/5pressed.bmp");
	    numberOfPlayers=5;
	  }
	  else if ( (x > 420 && x < 430) && (y > 250 && y < 270) ) { // 6 players
	    b6 = loadImage("data/6pressed.bmp");
	    numberOfPlayers=6;
	  }
	  else if ( (x > 500 && x < 550) && (y > 500 && y < 550) ) { // quit button selected
	    xOut = true;
	  }
	  else if ( (x > 200 && x < 250) && (y > 500 && y < 550) ) { // main menu button selected 
	    mainMenu();
	  }
	}

    }
     }}
}

void optionsMenu(){
  SDL_Surface *optionsScreen = SDL_SetVideoMode( SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP, SDL_SWSURFACE);
  SDL_Surface *soundPrompt = NULL;
  SDL_Surface *onButton = NULL;
  SDL_Surface *offButton = NULL;
  SDL_Surface *okButton = NULL;
  SDL_Surface *cancelButton = NULL;
  
  SDL_WM_SetCaption( "Monopoly - Options", "Options");
  font = TTF_OpenFont("/usr/share/fonts/paktype/PakTypeNaqsh.ttf", 28);
  // Load Surfaces
  soundPrompt = TTF_RenderText_Shaded(font, "Sound: ", textColor,bColor);

  // Apply Surface
  blit (10, 100, soundPrompt,optionsScreen);
  blit(100, 500, mainMenuButton,optionsScreen);
  // FLIP
  SDL_Flip(optionsScreen);
}

void creditsMenu(){
  SDL_Surface *creditsScreen = SDL_SetVideoMode( SCREEN_WIDTH , SCREEN_HEIGHT , SCREEN_BPP, SDL_SWSURFACE);
  SDL_WM_SetCaption( "Monopoly - Credits", "Credits");
  SDL_Surface *okButton = NULL;
  SDL_Surface *creditsText = NULL;
  
SDL_Color creditsColor = {100,200,0};
  // creditsText = TTF_RenderText_Solid(font,"credits", creditsColor);
/* std::ifstream credits;
  std::string line,output;
  credits.open("credits.txt");
  if (credits.is_open()){
    while (!credits.eof()){
      line = getline(credits,output);
      creditsText = TTF_RenderText_Shaded(font,line,textColor,bColor);
      blit(10,10, creditsText,creditsScreen);
    }
    SDL_Flip(creditsScreen);
  }
*/
 SDL_RWops *file = SDL_RWFromFile("credits.txt", "r"); // load credits file
 creditsText = SDL_LoadBMP_RW(file,1);
 blit(100,100, creditsText, creditsScreen);
 SDL_Flip(creditsScreen);
}

void quitMenu(){
   SDL_WM_SetCaption("Quit?", "Quit");
   SDL_Surface *verifyQuitScreen = NULL;
   SDL_Surface *quitPrompt = NULL;
   SDL_Surface *background = NULL;

  font = TTF_OpenFont("/usr/share/fonts/paktype/PakTypeNaqsh.ttf", 28);
  quitPrompt = TTF_RenderText_Shaded(font, "Are you sure you want to quit?", textColor,bColor);
  background = loadImage("data/quitBg.bmp");

  verifyQuitScreen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

  SDL_WM_SetCaption("Are You Sure?", NULL);
  blit(0, 0, background, verifyQuitScreen);
  blit(200,600,quitPrompt,verifyQuitScreen);
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
  
  SDL_WM_SetCaption( "Monopoly - Main Menu" , "Monopoly"); // SET WINDOW CAPTION
   
  // Load images
  background = loadImage("data/board.bmp");
  start = loadImage("data/START.bmp");
  options = loadImage("data/OPTIONS.bmp");
  credits = loadImage("data/CREDITS.bmp");

  // place buttons
  blit(240,2400, background,screen);
  blit(420, 400, start, screen);
  blit(420, 450, options, screen);
  blit(420, 500,  credits, screen);
  blit(420, 550, quit, screen);
  
  // display screen
  SDL_Flip(screen);

  // HANDLE EVENTS
  // HANDLE X-OUT
  while (xOut == false){
    while (SDL_PollEvent( &mainMenuEvent )){
      if(mainMenuEvent.type == SDL_QUIT ){  // if x-out
	xOut = true;
      }
      else if (mainMenuEvent.type == SDL_MOUSEBUTTONDOWN){ // detect mouse clicks
	// If left click
	if(mainMenuEvent.button.button == SDL_BUTTON_LEFT){
	  // get mouse locations
	  x = mainMenuEvent.button.x;
	  y = mainMenuEvent.button.y;
	  if( (x > 420 && x < 470) && (y > 380 && y < 420) ){ // if quit
	    SDL_FreeSurface(start);
	    SDL_FreeSurface(options);
	    SDL_FreeSurface(credits);
	    SDL_FreeSurface(quit);
	    startMenu();

	  }
	  else if( (x > 420 && x < 470) && (y > 430 && y < 470) ){
	    optionsMenu();
	  }
	  else if( (x > 400 && x < 490) && (y > 480 && y < 520) ){
	    creditsMenu();
	  }
	  else if( (x > 420 && x < 470) && (y > 530 && y < 570) ){
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
