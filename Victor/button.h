/*****************************************************
 * The button class will be used to handle button    *
 * selection events throughout the game.             *
 ****************************************************/
#ifndef BUTTON_H

#include <iostream>
class button{
 public:
  // Variable initialization
  button(int, int, int, int);
  void handle();
  void show();
  void setClips(); // will be different for each menu
 private:
  SDL_Rect box;
  SDL_Rect* clip;  

};

#endif
