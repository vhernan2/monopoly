#include <iostream>
#include "SDL/SDL.h"

class mainMenu{
 public:
  mainMenu(); // default constructor that will set buttons and background
  void loadButtons(); // loads buttons for the main menu
  void eventHandle(); // will handle events occurring on main menu screen
  
 private:
  int xOffset;
  int yOffset;


};
