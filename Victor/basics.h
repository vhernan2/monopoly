/****************************************
 * The basics class contains functions  *
 * that will be used throughout the     *
 * program for various purposes. Such   *
 * functions include the image loading  *
 * and screen application.              *
 ***************************************/

#include "SDL/SDL.h"
#include <iostream>

class basics{
 public:
  SDL_Surface loadImage(std::string);
  void applySurface(int,int,SDL_Surface*,SDL_Surface*); 
  void handle(SDL_Event);
};
