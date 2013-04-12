#include "mainMenu.h"

mainMenu::mainMenu(){


}

void mainMenu::loadButtons(){
  SDL_Surface *load(
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

void mainMenu::eventHandle(){

}
