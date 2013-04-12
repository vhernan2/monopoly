#include <iostream>
#include "basics.h"
using namespace std;

// global variables
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 920;
const int SCREEN_BPP = 32;
bool xOut = false;


int main (int argc, char* argv[]){

  // ensure that SDL subsystems are up and running
  if ( SDL_Init (SDL_INIT_EVERYTHING ) == -1 )
    return 1;
SDL_Event click;
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
  start = new basics;
  options = new basics;
  credits = new basics;
  quit = new basics;
  start.load_image("data/START.bmp");
  options.load_image("data/OPTIONS.bmp");
  credits.load_image("data/CREDITS.bmp");
  quit.load_image("data/QUIT.bmp");

  while (xOut == false){
  while (SDL_PollEvent(&click)){
  // set images on screen
  applySurface(640,400, start, screen);
  applySurface(640,450, options, screen);
  applySurface(640,500, credits, screen);
  applySurface(640,550, quit, screen);
  SDL_Flip(screen);
 
  // SDL_Delay (3000);
  if(click.type == SDL_QUIT){
  xOut = true;

  }
  }
  }
  return 0;
}
