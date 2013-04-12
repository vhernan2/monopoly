#include "basics.h"

SDL_Surface basics::loadImage(string fileName){
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
}

void basics::applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination){
  SDL_Rect offset;

  offset.x = x;
  offset.y = y;

  SDL_BlitSurface( source , NULL, destination, &offset);
}

void basics::handle(SDL_Event event){
int x = 0, y = 0;

  if( click.type == SDL_MOUSEMOTION){
    // determine mouse location
    x = event.motion.x;
    y = event.motion.y;

}
