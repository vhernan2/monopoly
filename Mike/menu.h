/**********************************************
 * The menu header had definitions for the    *
 * various menus that are used throughout the *
 * game.                                      *
 *********************************************/

#ifndef MENU_H
#include "functions.h"
#include "audio.h"
#include "SDL/SDL_ttf.h"
#include <iostream>
#include <fstream>


int mainMenu();

// Globals

int x, y; // used for offsets
extern bool SFXOn;// used to determine whether to enable Sound Effects
bool xOut;
extern TTF_Font *font;
// Text Color
extern SDL_Color textColor;
extern SDL_Color bColor;
SDL_Event mouseEvent; // used to detect mouse clicks
extern SDL_Event keyPress;
static int numberOfPlayers;

// testing one display
SDL_Surface *display;


// Font
 // used to detect a key press
bool musicOn = true; // used to determine whether to play music



inline void cleanUp(){
	TTF_CloseFont(font);
	TTF_Quit();

}

inline int startMenu(){
  xOut = false;
  SDL_WM_SetCaption( "Monopoly - Start", "Monopoly");
  display = SDL_SetVideoMode( 840,840,32, SDL_SWSURFACE );
  SDL_Surface *ok = loadImage("data/OK.bmp");
  SDL_Surface *mainMenuButton = loadImage("data/mainMenu.bmp");
  SDL_Surface *background = loadImage( "JLo/howManyBg.bmp" );
  SDL_Surface *namePrompt = NULL;
  SDL_Surface *b2 = NULL, *b3 = NULL, *b4 = NULL, *b5 = NULL, *b6 = NULL;
  SDL_Color textColor = {255,255,255};  // Text Color
  SDL_Color bColor = {0,0,0};

  // location variables
  int b1X, b2X, b3X, b4X, b5X, b6X, oX, mmX;
  int b1Y, b2Y, b3Y, b4Y, b5Y, b6Y, oY, mmY;
  TTF_Init();
  font = TTF_OpenFont("/usr/share/fonts/sil-padauk/Padauk.ttf", 28);
  namePrompt = TTF_RenderText_Shaded(font, "How Many Players will be participating today?", textColor,bColor);
  

  //  if (font == NULL)
  //  mainMenu();
    
  // Load buttons 43 x 31 px
  b2 = loadImage("data/2.bmp");
  b3 = loadImage("data/3.bmp");
  b4 = loadImage("data/4.bmp");
  b5 = loadImage("data/5.bmp");
  b6 = loadImage("data/6.bmp");

  // define button locations
  b2X = ( 840*1/6 );
  b3X = ( 840*2/6 );
  b4X = ( 840*3/6 );
  b5X = ( 840*4/6 );
  b6X = ( 840*5/6 );
  b2Y = b3Y = b4Y = b5Y = b6Y = ( 840/5 );
  oX = 4*840/5; oY = 840-80 ;
  mmX = 840/5; mmY= 840-80;

  blit(b2X+30, 50, namePrompt, background);
  blit(b2X, b2Y, b2, background);
  blit(b3X, b3Y, b3, background);
  blit(b4X, b4Y, b4, background);
  blit(b5X, b5Y, b5, background);
  blit(b6X, b6Y, b6, background);
  blit(oX, oY, ok, background);
  blit(mmX, mmY, mainMenuButton,background);
  
  blit(0,0,background,display);
  SDL_Flip(display);
  
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
	  /*	  if ( (x > b1X && x < b1X+43) && (y > b1Y && y < b1Y+31) ) { // if one player
	    // This allows for returning a pressed button to unpressed
	    SDL_FreeSurface(b1); SDL_FreeSurface(b2); SDL_FreeSurface(b3);
	    SDL_FreeSurface(b4); SDL_FreeSurface(b5); SDL_FreeSurface(b6);
	    b1 = loadImage("data/1pressed.bmp"); b6 = loadImage("data/6.bmp");
	    b2 = loadImage("data/2.bmp"); b3 = loadImage("data/3.bmp");
	    b4 = loadImage("data/4.bmp"); b5 = loadImage("data/5.bmp");
	    // Reapply Surfaces
	    blit(b1X, b1Y, b1, display);
	    blit(b2X, b2Y, b2, display);
	    blit(b3X, b3Y, b3, display);
	    blit(b4X, b4Y, b4, display);
	    blit(b5X, b5Y, b5, display);
	    blit(b6X, b6Y, b6, display);
	    SDL_Flip(display); // Refresh Screen
	    numberOfPlayers 1; // Player Value 
	    
	  }
	  else*/ if ( (x > b2X && x < b2X+43) && (y > b2Y && y < b2Y+31) ) { // two players
	    // This allows for returning a pressed button to unpressed
	    SDL_FreeSurface(b2); SDL_FreeSurface(b3);
	    SDL_FreeSurface(b4); SDL_FreeSurface(b5); SDL_FreeSurface(b6);
	    SDL_FreeSurface(display);
	    b6 = loadImage("data/6.bmp");
	    b2 = loadImage("data/2pressed.bmp"); b3 = loadImage("data/3.bmp");
	    b4 = loadImage("data/4.bmp"); b5 = loadImage("data/5.bmp");
	    // Reapply Surfaces
	    
	    blit(b2X, b2Y, b2, background);
	    blit(b3X, b3Y, b3, background);
	    blit(b4X, b4Y, b4, background);
	    blit(b5X, b5Y, b5, background);
	    blit(b6X, b6Y, b6, background);
	    blit(0,0,background,display);
	    SDL_Flip(display); // Refresh Screen
	    numberOfPlayers= 2; // Player Value 
	    
	  }
	  else if ( (x > b3X && x < b3X+43) && (y > b3Y && y < b3Y+31) ) { // 3 players
	    // This allows for returning a pressed button to unpressed
	    SDL_FreeSurface(b2); SDL_FreeSurface(b3);
	    SDL_FreeSurface(b4); SDL_FreeSurface(b5); SDL_FreeSurface(b6);
	    b6 = loadImage("data/6.bmp");
	    b2 = loadImage("data/2.bmp"); b3 = loadImage("data/3pressed.bmp");
	    b4 = loadImage("data/4.bmp"); b5 = loadImage("data/5.bmp");
	    // Reapply Surfaces
	    
	    blit(b2X, b2Y, b2, display);
	    blit(b3X, b3Y, b3, display);
	    blit(b4X, b4Y, b4, display);
	    blit(b5X, b5Y, b5, display);
	    blit(b6X, b6Y, b6, display);
	    SDL_Flip(display); // Refresh Screen
	    numberOfPlayers=3; // Player Value 
	  }
	  else if ( (x > b4X && x < b4X+43) && (y > b4Y && y < b4Y+31) ) { // 4 players
	    // This allows for returning a pressed button to unpressed
	    SDL_FreeSurface(b2); SDL_FreeSurface(b3);
	    SDL_FreeSurface(b4); SDL_FreeSurface(b5); SDL_FreeSurface(b6);
	    b6 = loadImage("data/6.bmp");
	    b2 = loadImage("data/2.bmp"); b3 = loadImage("data/3.bmp");
	    b4 = loadImage("data/4pressed.bmp"); b5 = loadImage("data/5.bmp");
	    // Reapply Surfaces
	    
	    blit(b2X, b2Y, b2, display);
	    blit(b3X, b3Y, b3, display);
	    blit(b4X, b4Y, b4, display);
	    blit(b5X, b5Y, b5, display);
	    blit(b6X, b6Y, b6, display);
	    SDL_Flip(display); // Refresh Screen
	    numberOfPlayers=4; // Player Value 
	  }
	  else if ( (x > b5X && x < b5X+43) && (y > b5Y && y < b5Y+31) ) { // 5 players
	    // This allows for returning a pressed button to unpressed
	    SDL_FreeSurface(b2); SDL_FreeSurface(b3);
	    SDL_FreeSurface(b4); SDL_FreeSurface(b5); SDL_FreeSurface(b6);
	    b6 = loadImage("data/6.bmp");
	    b2 = loadImage("data/2.bmp"); b3 = loadImage("data/3.bmp");
	    b4 = loadImage("data/4.bmp"); b5 = loadImage("data/5pressed.bmp");
	    // Reapply Surfaces
	    
	    blit(b2X, b2Y, b2, display);
	    blit(b3X, b3Y, b3, display);
	    blit(b4X, b4Y, b4, display);
	    blit(b5X, b5Y, b5, display);
	    blit(b6X, b6Y, b6, display);
	    SDL_Flip(display); // Refresh Screen
	    numberOfPlayers= 5; // Player Value 
	  }
	  else if ( (x > b6X && x < b6X+43) && (y > b6Y && y < b6Y+41) ) { // 6 players
	    // This allows for returning a pressed button to unpressed
	    SDL_FreeSurface(b2); SDL_FreeSurface(b3);
	    SDL_FreeSurface(b4); SDL_FreeSurface(b5); SDL_FreeSurface(b6);
	    b6 = loadImage("data/6pressed.bmp");
	    b2 = loadImage("data/2.bmp"); b3 = loadImage("data/3.bmp");
	    b4 = loadImage("data/4.bmp"); b5 = loadImage("data/5.bmp");
	    // Reapply Surfaces
	    
	    blit(b2X, b2Y, b2, display);
	    blit(b3X, b3Y, b3, display);
	    blit(b4X, b4Y, b4, display);
	    blit(b5X, b5Y, b5, display);
	    blit(b6X, b6Y, b6, display);
	    SDL_Flip(display); // Refresh Screen
	    numberOfPlayers= 6; // Player Value 
	  }
	  if ( (x > oX && x < oX+109) && (y > oY && y < oY+23) ) { // ok button selected
	    SDL_FreeSurface(b2); SDL_FreeSurface(b3);
	    SDL_FreeSurface(b4); SDL_FreeSurface(b5); SDL_FreeSurface(b6);
	    SDL_FreeSurface(ok);
	    SDL_FreeSurface(mainMenuButton);
	    SDL_FillRect(display,NULL,0x000000);
	    SDL_Flip(display);
	    return numberOfPlayers;
	  }
0	  if ( (x > mmX && x < mmX+109) && (y > mmY && y < mmY+23) ) { // main menu button selected 
  return 0;
	  }
	}	
      }
    }
  }
}

inline void optionsMenu(){
xOut = false;
// Surface for Options Menu
 display = SDL_SetVideoMode( 840,840,32, SDL_SWSURFACE);
 SDL_Surface *soundPrompt = NULL;
 SDL_Surface *onButton = NULL;
 SDL_Surface *offButton = NULL;
 SDL_Surface *okButton = loadImage( "data/OK.bmp" );
 SDL_Event optionEvent;
  
 SDL_WM_SetCaption( "Monopoly - Options", "Options"); // Caption
 font = TTF_OpenFont("/usr/share/fonts/sil-padauk/Padauk.ttf", 28); // Font

  // locations
 int onX = 100;
 int offX = 300;
 int okX = 840/2;
 int onY = 100;
 int offY = onY;
 int okY = 840-100;

 // Load Surfaces
 onButton = loadImage( "data/ON.bmp" );
 offButton = loadImage( "data/OFF.bmp" );
 soundPrompt = TTF_RenderText_Shaded(font, "Sound: ", textColor,bColor);
 
 // Apply Surfaces
 blit (10, 50, soundPrompt,display);
 blit (onX, onY, onButton, display);
 blit (offX, offY, offButton, display);
 blit (okX, okY, okButton, display);

 // FLIP
 SDL_Flip(display);

  // Option Menu Event Handling
   while (xOut == false){
    while (SDL_PollEvent( &optionEvent )){
      if(optionEvent.type == SDL_QUIT ){  // if x-out
	xOut = true;
      }
      else if (optionEvent.type == SDL_MOUSEBUTTONDOWN){ // detect mouse clicks
	// If left click
	if(optionEvent.button.button == SDL_BUTTON_LEFT){
	  // get mouse locations
	  x = optionEvent.button.x;
	  y = optionEvent.button.y;

	  // size of buttons are 53 x 23 so check boundaries for button press
	  if( (x > onX && x < onX + 53) && (y > onY && y < onY + 23) ){ // if on
	    SDL_FreeSurface(offButton);
	    SDL_FreeSurface(onButton);
	    onButton = loadImage( "data/ONpressed.bmp" );
	    offButton = loadImage( "data/OFF.bmp" );
	    blit(onX,onY,onButton,display);
	    blit(offX,offY,offButton,display);
	    if (musicOn = false)
	      gameMusic();
	    musicOn = true;
	    SDL_Flip(display);
	  }
	  else if( (x > offX && x < offX + 53) && (y > offY && y < offY + 23) ){ // if off button
	    SDL_FreeSurface(onButton);
	    SDL_FreeSurface(offButton);
	    offButton = loadImage( "data/OFFpressed.bmp" );
	    onButton = loadImage( "data/ON.bmp" );
	    blit(onX,onY,onButton,display);
	    blit(offX,offY,offButton,display);
	    musicOn = false;
	    closeMusic();
	    SDL_Flip(display);
	    

	  }
	  else if( (x > okX && x < okX + 109) && (y > okY && y < okY + 23) ){ // OK button
	    SDL_FreeSurface(onButton);
	    SDL_FreeSurface(offButton);
	    SDL_FreeSurface(okButton);
	    mainMenu();
	  }
	}
	else if(optionEvent.button.button == SDL_BUTTON_RIGHT){
	  // do nothing
	}
      }
    }
   }
}

inline void creditsMenu(){
  display = SDL_SetVideoMode( 840 , 840 , 32, SDL_SWSURFACE);
  SDL_WM_SetCaption( "Monopoly - Credits", "Credits");
  SDL_Surface *okButton = loadImage("data/OK.bmp");
  SDL_Surface *creditsText = NULL;
  SDL_Event creditsEvent;
  
  font = TTF_OpenFont("/usr/share/fonts/sil-padauk/Padauk.ttf", 28);
  std::ifstream credits;
  std::string line;
  const char *output;
  int textX=0, textY = 0;
  credits.open("credits.txt");
  if (credits.is_open()){
    while (credits >> line){
      output = line.c_str();
      creditsText = TTF_RenderText_Shaded(font,output,textColor,bColor);
      blit(textX,textY, creditsText, display);
      if ((textX+(line.length()*25+100)) >= 840){
	textX = 0;
	textY = textY + 50;
      }
      else if (line.length() < 10){
	textX += 20*line.length();
      }
      else textX += 13*line.length();
          }
  }
  blit(840/2, 840-100, okButton, display);
 
  SDL_Flip(display);

   while (xOut == false){
    while (SDL_PollEvent( &creditsEvent )){
      if(creditsEvent.type == SDL_QUIT ){  // if x-out
	xOut = true;
      }
      else if (creditsEvent.type == SDL_MOUSEBUTTONDOWN){ // detect mouse clicks
	// If left click
	if(creditsEvent.button.button == SDL_BUTTON_LEFT){
	  // get mouse locations
	  x = creditsEvent.button.x;
	  y = creditsEvent.button.y;

	  if( (x > 840/2 && x < 840/2 + 109) && (y > 840-100 && y < 840 - 77) ){ // if on
	    SDL_FreeSurface(creditsText);
	    SDL_FreeSurface(okButton);
	    okButton = loadImage( "data/OKpressed.bmp" );
	    blit(840/2, 840-100, okButton, display);
	    SDL_Flip(display);
	    mainMenu();
	  }
       	}
	else if(creditsEvent.button.button == SDL_BUTTON_RIGHT){
	  // do nothing
	}
      }
    }
   }
}

inline void quitMenu(){
   SDL_WM_SetCaption("Quit?", "Quit");
   SDL_Surface *verifyQuitScreen = NULL;
   SDL_Surface *quitPrompt = NULL;
   SDL_Surface *background = NULL;
   SDL_Surface *okButton = NULL;
   SDL_Surface *cancelButton = NULL;
   SDL_Event quitEvent;

   font = TTF_OpenFont("/usr/share/fonts/sil-padauk/Padauk.ttf", 28);
   quitPrompt = TTF_RenderText_Shaded(font, "Are you sure you want to quit?", textColor,bColor);
   background = loadImage("data/quitBg.bmp");
   okButton = loadImage( "data/OK.bmp" );
   cancelButton = loadImage( "data/CANCEL.bmp" );
  verifyQuitScreen = SDL_SetVideoMode( 840, 840, 32, SDL_SWSURFACE );

  SDL_WM_SetCaption("Are You Sure?", NULL);
  blit(0, 0, background, verifyQuitScreen);
  blit(200,600,quitPrompt,verifyQuitScreen);
  blit(400, 700, okButton, verifyQuitScreen);
  blit(200, 700, cancelButton, verifyQuitScreen);
  SDL_Flip(verifyQuitScreen);

   while (xOut == false){
    while (SDL_PollEvent( &quitEvent )){
      if(quitEvent.type == SDL_QUIT ){  // if x-out
	xOut = true;
      }
      else if (quitEvent.type == SDL_MOUSEBUTTONDOWN){ // detect mouse clicks
	// If left click
	if(quitEvent.button.button == SDL_BUTTON_LEFT){
	  // get mouse locations
	  x = quitEvent.button.x;
	  y = quitEvent.button.y;

	  if( (x > 200 && x < 309) && (y > 700 && y < 723) ){ // if cancel
	    SDL_FreeSurface(okButton);
	    SDL_FreeSurface(quitPrompt);
	    SDL_FreeSurface(cancelButton);
	    SDL_FreeSurface(background);
	    SDL_Flip(verifyQuitScreen);
	    mainMenu();
	  }
	  else if( (x>400 && x<509)&& (y>700 && y < 723) ){ // if OK
	    SDL_FreeSurface(okButton);
	    SDL_FreeSurface(quitPrompt);
	    SDL_FreeSurface(background);
	    cleanUp();
	    xOut=true;
	  }
       	}
	else if(quitEvent.button.button == SDL_BUTTON_RIGHT){
	  // do nothing
	}
      }
    }
   }
  
  
}

// the main menu function will display the main menu for the game
inline int mainMenu(){
musicOn = true;
  display = SDL_SetVideoMode( 840, 840, 32, SDL_SWSURFACE );
  SDL_Surface *quit = loadImage("data/QUIT.bmp");
  SDL_Surface *mainMenuButton = loadImage("data/mainMenu.bmp"); // like quit

  SDL_WM_SetCaption( "Monopoly - Main Menu" , "Monopoly"); // SET WINDOW CAPTION
  SDL_Event mainMenuEvent;
  SDL_Surface *background = NULL;
  SDL_Surface *start = NULL;
  SDL_Surface *options = NULL;
  SDL_Surface *credits = NULL;
  
  int sX = 840/2 , oX = 840/2, cX = 840/2, qX = 840/2;
  int sY = (840*2/3);
  int oY = sY + 75;
  int cY = oY + 75;
  int qY = cY + 75;
   
  // Load images
  background = loadImage("data/mainMenuBackground.bmp");
  start = loadImage("data/START.bmp");
  options = loadImage("data/OPTIONS.bmp");
  credits = loadImage("data/CREDITS.bmp");

  // place buttons
  blit(0,0, background,display);
  blit(sX, sY, start, display);
  blit(oX, oY, options, display);
  blit(cX, cY,  credits, display);
  blit(qX, qY, quit, display);
  
  // display display
  SDL_Flip(display);

  // sound 
  if (musicOn)
    gameMusic();
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
	    SDL_Flip(display);
	    return -1;

	  }
	  else if( (x > oX && x < oX + 109) && (y > oY && y < oY + 23) ){
	    SDL_FreeSurface(background);
	    SDL_FreeSurface(start);
	    SDL_FreeSurface(options);
	    SDL_FreeSurface(credits);
	    SDL_FreeSurface(quit);
	    optionsMenu();
	  }
	  else if( (x > cX && x < cX + 109) && (y > cY && y < cY + 23) ){
	    SDL_FreeSurface(background);
	    SDL_FreeSurface(start);
	    SDL_FreeSurface(options);
	    SDL_FreeSurface(credits);
	    SDL_FreeSurface(quit);
	    creditsMenu();
	  }
	  else if( (x > qX && x < qX + 109) && (y > qY && y < qY + 23) ){
	    SDL_FreeSurface(background);
	    SDL_FreeSurface(start);
	    SDL_FreeSurface(options);
	    SDL_FreeSurface(credits);
	    SDL_FreeSurface(quit);
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
