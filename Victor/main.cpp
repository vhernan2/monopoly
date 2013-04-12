#include <iostream>
#include "SDL/SDL.h"
using namespace std;

// global variables
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

  // load Images function
SDL_Surface *load_image( string fileName ){
    // temp storage for laoded image
    SDL_Surface *loaded = NULL;
    // optimized
    SDL_Surface *optimized = NULL;
    // load image
    loaded = SDL_LoadBMP(fileName.c_str());

    // continue if no errors
    if (loaded != NULL){
      optimized = SDL_DisplayFormat( loaded );
      SDL_FreeSurface(loaded);
    }
    return optimized;
}

// Apply Images to surface function
void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination){
  SDL_Rect offset;

  offset.x = x;
  offset.y = y;

  SDL_BlitSurface( source , NULL, destination, &offset);
}

int main (int argc, char* argv[]){

  // ensure that SDL subsystems are up and running
  if ( SDL_Init (SDL_INIT_EVERYTHING ) == -1 )
    return 1;

  // intialize the screen

  SDL_Surface *background = NULL;
  SDL_Surface *start = NULL;
  SDL_Surface *options = NULL;
  SDL_Surface *credits = NULL;
  SDL_Surface *quit = NULL;
  SDL_Surface *screen = NULL;

  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
  // ERROR CATCHING FOR SCREEN INITIALIZATION
  if (screen == NULL )
    return 1;

  // set window caption
  SDL_WM_SetCaption("Monopoly - Main Menu", NULL);
  // Load Images



}
