/**********************************************
 * This header contains various function      *
 * definitions that will be used throughout   *
 * the game.                                  *
 *********************************************/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

// loadImage function will be used to load any image used for the game
inline SDL_Surface *loadImage( std::string fileName ){

  SDL_Surface* loaded = NULL;   // temp storage for laoded image
  SDL_Surface* optimized = NULL;
  loaded = SDL_LoadBMP( fileName.c_str() );   // load

  // verify loaded and continue
  if( loaded != NULL ){
    optimized = SDL_DisplayFormat(loaded);     // optimize
    SDL_FreeSurface( loaded );     // Free old 
    if ( optimized != NULL ){
      Uint32 colorkey = SDL_MapRGB( optimized->format, 0, 0xFF, 0xFF );
      SDL_SetColorKey( optimized, SDL_SRCCOLORKEY, colorkey);
    }
  }
  return optimized;
}

// Surface Blitting Function
inline void blit(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL){

  SDL_Rect offset;

  offset.x = x;
  offset.y = y;

  SDL_BlitSurface( source, clip, destination, &offset);

}

inline int keyDetect(){
  extern SDL_Event keyPress;
  while (SDL_PollEvent(&keyPress)){
      switch (keyPress.type){
      case SDLK_0:
	continue;
	break;
      case SDLK_1:
	return 1;
	break;
      case SDLK_2:
	return 2;
	break;
      case SDLK_3:
	return 3;
	break;
      case SDLK_4:
	return 4;
	break;
      case SDLK_5:
	return 5;
	break;
      case SDLK_6:
	return 6;
	break;
      default:
	continue;
	break;
      }

    }
}


#endif
