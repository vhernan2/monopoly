/*****************************************************
 * The button class will be used to handle button    *
 * selection events throughout the game.             *
 ****************************************************/
#ifndef BUTTON_H
#include "functions.h"
#include <iostream>

class button{
 public:
  // Variable initialization
  button(int, int, int, int);
  void handle();
  void show();
  void setClips(); // will be different for each menu
 private:
  SDL_Rect box; // location of button
  SDL_Surface * clip;  // image for button
  SDL_Event event; // handles events 
};

#endif
