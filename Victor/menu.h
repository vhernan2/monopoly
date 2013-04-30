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

// included functions
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
SDL_Event mouseEvent; // used to detect mouse clicks
SDL_Event keyPress; // used to detect a key press



void cleanUp(){
	TTF_CloseFont(font);
	TTF_Quit();

}

void startMenu(){
SDL_WM_SetCaption( "Monopoly - Start", "Monopoly");
  SDL_Surface *startMenu = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
  SDL_Surface *ok = loadImage("data/OK.bmp");
  SDL_Surface *mainMenuButton = loadImage("data/mainMenu.bmp");
  SDL_Surface *namePrompt = NULL;
  SDL_Surface *b1 = NULL, *b2 = NULL, *b3 = NULL, *b4 = NULL, *b5 = NULL, *b6 = NULL;
  SDL_Color textColor = {255,255,255};  // Text Color
  SDL_Color bColor = {0,0,0};

  // location variables
  int b1X, b2X, b3X, b4X, b5X, b6X, oX, mmX;
  int b1Y, b2Y, b3Y, b4Y, b5Y, b6Y, oY, mmY;

  font = TTF_OpenFont("/usr/share/fonts/paktype/PakTypeNaqsh.ttf", 28);
  namePrompt = TTF_RenderText_Shaded(font, "How Many Players will be participating today?:", textColor,bColor);


  


  //  if (font == NULL)
  //  mainMenu();
    
  // Load buttons 43 x 31 px
  b1 = loadImage("data/1.bmp");
  b2 = loadImage("data/2.bmp");
  b3 = loadImage("data/3.bmp");
  b4 = loadImage("data/4.bmp");
  b5 = loadImage("data/5.bmp");
  b6 = loadImage("data/6.bmp");

  // define button locations
  b1X = ( SCREEN_WIDTH/7 );
  b2X = ( SCREEN_WIDTH*2/7 );
  b3X = ( SCREEN_WIDTH*3/7 );
  b4X = ( SCREEN_WIDTH*4/7 );
  b5X = ( SCREEN_WIDTH*5/7 );
  b6X = ( SCREEN_WIDTH*6/7 );
  b1Y = b2Y = b3Y = b4Y = b5Y = b6Y = ( SCREEN_HEIGHT/3 );
  oX = 3*SCREEN_WIDTH/4; oY = SCREEN_HEIGHT-100 ;
  mmX = SCREEN_WIDTH/4; mmY= SCREEN_HEIGHT-100;
     blit(10, 200, namePrompt, startMenu);
     blit(b1X, b1Y, b1, startMenu);
     blit(b2X, b2Y, b2, startMenu);
     blit(b3X, b3Y, b3, startMenu);
     blit(b4X, b4Y, b4, startMenu);
     blit(b5X, b5Y, b5, startMenu);
     blit(b6X, b6Y, b6, startMenu);
     blit(oX, oY, ok, startMenu);
     blit(mmX, mmY, mainMenuButton,startMenu);

   SDL_Flip(startMenu);
  
  while (xOut == false){
    while (SDL_PollEvent( &mouseEvent )){  
      if (mouseEvent.type == SDL_QUIT){
	xOut = true;
	SDL_FreeSurface(namePrompt);
      }
      else if (mouseEvent.type == SDL_MOUSEBUTTONDOWN){
	// If left click
	if(mouseEvent.button.button == SDL_BUTTON_LEFT){
	  x = mouseEvent.button.x;
	  y = mouseEvent.button.y; 
	  if ( (x > b1X && x < b1X+43) && (y > b1Y && y < b1Y+31) ) { // if one player
	    // This allows for returning a pressed button to unpressed
	    SDL_FreeSurface(b1); SDL_FreeSurface(b2); SDL_FreeSurface(b3);
	    SDL_FreeSurface(b4); SDL_FreeSurface(b5); SDL_FreeSurface(b6);
	    b1 = loadImage("data/1pressed.bmp"); b6 = loadImage("data/6.bmp");
	    b2 = loadImage("data/2.bmp"); b3 = loadImage("data/3.bmp");
	    b4 = loadImage("data/4.bmp"); b5 = loadImage("data/5.bmp");
	    // Reapply Surfaces
	    blit(b1X, b1Y, b1, startMenu);
	    blit(b2X, b2Y, b2, startMenu);
	    blit(b3X, b3Y, b3, startMenu);
	    blit(b4X, b4Y, b4, startMenu);
	    blit(b5X, b5Y, b5, startMenu);
	    blit(b6X, b6Y, b6, startMenu);
	    SDL_Flip(startMenu); // Refresh Screen
	    numberOfPlayers=1; // Player Value 
	    
	  }
	  else if ( (x > b2X && x < b2X+43) && (y > b2Y && y < b2Y+31) ) { // two players
	    // This allows for returning a pressed button to unpressed
	    SDL_FreeSurface(b1); SDL_FreeSurface(b2); SDL_FreeSurface(b3);
	    SDL_FreeSurface(b4); SDL_FreeSurface(b5); SDL_FreeSurface(b6);
	    SDL_FreeSurface(startMenu);
	    b1 = loadImage("data/1.bmp"); b6 = loadImage("data/6.bmp");
	    b2 = loadImage("data/2pressed.bmp"); b3 = loadImage("data/3.bmp");
	    b4 = loadImage("data/4.bmp"); b5 = loadImage("data/5.bmp");
	    // Reapply Surfaces
	    blit(b1X, b1Y, b1, startMenu);
	    blit(b2X, b2Y, b2, startMenu);
	    blit(b3X, b3Y, b3, startMenu);
	    blit(b4X, b4Y, b4, startMenu);
	    blit(b5X, b5Y, b5, startMenu);
	    blit(b6X, b6Y, b6, startMenu);
	    SDL_Flip(startMenu); // Refresh Screen
	    numberOfPlayers=2; // Player Value 

	  }
	  else if ( (x > b3X && x < b3X+43) && (y > b3Y && y < b3Y+31) ) { // 3 players
	    // This allows for returning a pressed button to unpressed
	    SDL_FreeSurface(b1); SDL_FreeSurface(b2); SDL_FreeSurface(b3);
	    SDL_FreeSurface(b4); SDL_FreeSurface(b5); SDL_FreeSurface(b6);
	    b1 = loadImage("data/1.bmp"); b6 = loadImage("data/6.bmp");
	    b2 = loadImage("data/2.bmp"); b3 = loadImage("data/3pressed.bmp");
	    b4 = loadImage("data/4.bmp"); b5 = loadImage("data/5.bmp");
	    // Reapply Surfaces
	    blit(b1X, b1Y, b1, startMenu);
	    blit(b2X, b2Y, b2, startMenu);
	    blit(b3X, b3Y, b3, startMenu);
	    blit(b4X, b4Y, b4, startMenu);
	    blit(b5X, b5Y, b5, startMenu);
	    blit(b6X, b6Y, b6, startMenu);
	    SDL_Flip(startMenu); // Refresh Screen
	    numberOfPlayers=3; // Player Value 
	  }
	  else if ( (x > b4X && x < b4X+43) && (y > b4Y && y < b4Y+31) ) { // 4 players
	    // This allows for returning a pressed button to unpressed
	    SDL_FreeSurface(b1); SDL_FreeSurface(b2); SDL_FreeSurface(b3);
	    SDL_FreeSurface(b4); SDL_FreeSurface(b5); SDL_FreeSurface(b6);
	    b1 = loadImage("data/1.bmp"); b6 = loadImage("data/6.bmp");
	    b2 = loadImage("data/2.bmp"); b3 = loadImage("data/3.bmp");
	    b4 = loadImage("data/4pressed.bmp"); b5 = loadImage("data/5.bmp");
	    // Reapply Surfaces
	    blit(b1X, b1Y, b1, startMenu);
	    blit(b2X, b2Y, b2, startMenu);
	    blit(b3X, b3Y, b3, startMenu);
	    blit(b4X, b4Y, b4, startMenu);
	    blit(b5X, b5Y, b5, startMenu);
	    blit(b6X, b6Y, b6, startMenu);
	    SDL_Flip(startMenu); // Refresh Screen
	    numberOfPlayers=4; // Player Value 
	  }
	  else if ( (x > b5X && x < b5X+43) && (y > b5Y && y < b5Y+31) ) { // 5 players
	    // This allows for returning a pressed button to unpressed
	    SDL_FreeSurface(b1); SDL_FreeSurface(b2); SDL_FreeSurface(b3);
	    SDL_FreeSurface(b4); SDL_FreeSurface(b5); SDL_FreeSurface(b6);
	    b1 = loadImage("data/1.bmp"); b6 = loadImage("data/6.bmp");
	    b2 = loadImage("data/2.bmp"); b3 = loadImage("data/3.bmp");
	    b4 = loadImage("data/4.bmp"); b5 = loadImage("data/5pressed.bmp");
	    // Reapply Surfaces
	    blit(b1X, b1Y, b1, startMenu);
	    blit(b2X, b2Y, b2, startMenu);
	    blit(b3X, b3Y, b3, startMenu);
	    blit(b4X, b4Y, b4, startMenu);
	    blit(b5X, b5Y, b5, startMenu);
	    blit(b6X, b6Y, b6, startMenu);
	    SDL_Flip(startMenu); // Refresh Screen
	    numberOfPlayers=5; // Player Value 
	  }
	  else if ( (x > b6X && x < b6X+43) && (y > b6Y && y < b6Y+41) ) { // 6 players
	    // This allows for returning a pressed button to unpressed
	    SDL_FreeSurface(b1); SDL_FreeSurface(b2); SDL_FreeSurface(b3);
	    SDL_FreeSurface(b4); SDL_FreeSurface(b5); SDL_FreeSurface(b6);
	    b1 = loadImage("data/1.bmp"); b6 = loadImage("data/6pressed.bmp");
	    b2 = loadImage("data/2.bmp"); b3 = loadImage("data/3.bmp");
	    b4 = loadImage("data/4.bmp"); b5 = loadImage("data/5.bmp");
	    // Reapply Surfaces
	    blit(b1X, b1Y, b1, startMenu);
	    blit(b2X, b2Y, b2, startMenu);
	    blit(b3X, b3Y, b3, startMenu);
	    blit(b4X, b4Y, b4, startMenu);
	    blit(b5X, b5Y, b5, startMenu);
	    blit(b6X, b6Y, b6, startMenu);
	    SDL_Flip(startMenu); // Refresh Screen
	    numberOfPlayers=6; // Player Value 
	  }
	  if ( (x > oX && x < oX+109) && (y > oY && y < oY+23) ) { // ok button selected
	    xOut = true;
	    std::cout << "NAME INFORMATION";
	  }
	  if ( (x > mmX && x < mmX+109) && (y > mmY && y < mmY+23) ) { // main menu button selected 
	    mainMenu();
	  }

	}
	
    }
     }}
}

void optionsMenu(){
  SDL_Surface *optionsScreen = SDL_SetVideoMode( SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP, SDL_SWSURFACE);
  SDL_Surface *mainMenuButton = loadImage("data/mainMenuButton.bmp");
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
  
  font = TTF_OpenFont("/usr/share/fonts/paktype/PakTypeNaqsh.ttf", 28);

  std::ifstream credits;
  std::string line;
  const char *output;
  int textX=0, textY = 0;
  credits.open("credits.txt");
  if (credits.is_open()){
    while (credits >> line){
      output = line.c_str();
      creditsText = TTF_RenderText_Shaded(font,output,textColor,bColor);
      blit(textX,textY, creditsText, creditsScreen);
      if ((textX+line.length()*20+100) >= SCREEN_WIDTH){
	textX = 0;
	textY = textY + 100;
      }
      else textX += line.length()*20;
          }
  }


 
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
SDL_Surface *screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
  SDL_Surface *quit = loadImage("data/QUIT.bmp");
  SDL_Surface *mainMenuButton = loadImage("data/mainMenu.bmp"); // like quit

  SDL_WM_SetCaption( "Monopoly - Main Menu" , "Monopoly"); // SET WINDOW CAPTION
  SDL_Event mainMenuEvent;
  SDL_Surface *background = NULL;
  SDL_Surface *start = NULL;
  SDL_Surface *options = NULL;
  SDL_Surface *credits = NULL;
  
  int sX = SCREEN_WIDTH/2 , oX = SCREEN_WIDTH/2, cX = SCREEN_WIDTH/2, qX = SCREEN_WIDTH/2;
  int sY = (SCREEN_HEIGHT*2/3);
  int oY = sY + 75;
  int cY = oY + 75;
  int qY = cY + 75;
   
  // Load images
  background = loadImage("data/mainMenuBackground.bmp");
  start = loadImage("data/START.bmp");
  options = loadImage("data/OPTIONS.bmp");
  credits = loadImage("data/CREDITS.bmp");

  // place buttons
  blit(0,0, background,screen);
  blit(sX, sY, start, screen);
  blit(oX, oY, options, screen);
  blit(cX, cY,  credits, screen);
  blit(qX, qY, quit, screen);
  
  // display screen
  SDL_Flip(screen);

  // HANDLE EVENTS

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

	  // size of buttons are 109 x 23 so check boundaries for button press
	  if( (x > sX && x < sX + 109) && (y > sY && y < sY + 23) ){ // if start
	    SDL_FreeSurface(background);
	    SDL_FreeSurface(start);
	    SDL_FreeSurface(options);
	    SDL_FreeSurface(credits);
	    SDL_FreeSurface(quit);
	    SDL_Flip(screen);
	    startMenu();

	  }
	  else if( (x > oX && x < oX + 109) && (y > oY && y < oY + 23) ){
	    optionsMenu();
	  }
	  else if( (x > cX && x < cX + 109) && (y > cY && y < cY + 23) ){
	    creditsMenu();
	  }
	  else if( (x > qX && x < qX + 109) && (y > qY && y < qY + 23) ){
	    quitMenu();
	  }
	}
	else if(mainMenuEvent.button.button == SDL_BUTTON_RIGHT){
	  // do nothing
	}
      }
    }

  }
 }

#endif
