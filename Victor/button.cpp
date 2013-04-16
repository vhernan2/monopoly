#include "button.h"

button::button( int x, int y, int w, int h){
  // set the button attribuets
  box.x = x;
  box.y = y;
  box.w = w;
  box.h = h;

  //default sprite
  clip = &clips[ CLIP_MOUSEOUT ];


}

void button::handle(){
  // mouse offsets
  int x = 0, y = 0;

  // If the mouse moves
  if( event.type == SDL_MOUSEMOTION ){
    // get offsets
    x = event.motion.x;
    y = event.motion.y;

    // if mouse is over a button
    if (( x > box.x ) && (x < box.x + box.w ) && (y > box.y ) && (y < box.y + box.h )){
    // set button sprite
    clip = &clips[ CLIP_MOUSEOVER ];
    }
    // if not
    else{
      // set button sprite
      clip = &clips[ CLIP_MOUSEOUT];
    }
  }

  // if mouse button pressed
  if (event.type == SDL_MOUSEBUTTONDOWN ){
    // If left mouse button
    if (event.button.button == SDL_BUTTON_LEFT ){
    // get offsets
    x = event.button.x;
    y = event.button.y;

    // If the mouse is over the button
    if (( x > box.x ) && (x < box.x + box.w ) && (y > box.y ) && (y < box.y + box.h )){
       // set button sprite
       clip = &clips [CLIP_MOUSEDOWN];
    }
    }
  }

  // If a mouse button was realeased 
  if (event.type == SDL _MOUSEBUTTONUP ){
    // If left mouse button released
    if (event.button.button == SDL_BUTTON_LEFT ){
      // Get mouse offsets
      x = event.button.x;
      y = event.button.y;
      
      // If mouse was over button
       if (( x > box.x ) && (x < box.x + box.w ) && (y > box.y ) && (y < box.y + box.h )){
	 // Set button sprite
	 clip = &clip[ CLIP_MOUSEUP ];
       }
    }
  }
}

void button::show(){
  // show button
  blit(box.x, box.y, buttonSheet, screen, clip);
}
