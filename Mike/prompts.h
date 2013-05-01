#ifndef PROMPTS_H
#define PROMPTS_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "functions.h"
#include "menu.h"
#include <iostream>
#include <string>

SDL_Event event; // detects key press statuses
TTF_Font *font = NULL;
SDL_Color textColor = {255,255,255};
SDL_Color bColor = {0,0,0};
int textX = 20, textY=100;

inline void initializeText(){
  TTF_Init();
  if (TTF_Init()==-1){
    cout << "TTF_Init Error: " << TTF_GetError() << endl;
    exit(2);
  }
}

inline const char * decipher(SDL_Surface *displaySurface){
SDL_Surface *text = NULL; // text to be added to display
bool done = false;
  font = TTF_OpenFont("/usr/share/fonts/sil-padauk/Padauk.ttf",28);
  while(done == false){
    while (SDL_PollEvent( &event )){
      if (event.type == SDL_QUIT){
	done = true;
      }
      else if(event.type == SDL_KEYDOWN){
	  switch (event.key.keysym.sym){
	  case SDLK_SPACE:
	    textX += 15;
	    return " ";
	    break;
	  case SDLK_a:
	    text = TTF_RenderText_Shaded(font,"a",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "a";
	    break;
	  case SDLK_b:
	    text = TTF_RenderText_Shaded(font,"b",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "b";
	    break;
	  case SDLK_c:
	    text = TTF_RenderText_Shaded(font,"c",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "c";
	    break;
	  case SDLK_d:
	    text = TTF_RenderText_Shaded(font,"d",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "d";
	    break;
	  case SDLK_e:
	    text = TTF_RenderText_Shaded(font,"e",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "e";
	    break;
	  case SDLK_f:
	    text = TTF_RenderText_Shaded(font,"f",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "f";
	    break;
	  case SDLK_g:
	    text = TTF_RenderText_Shaded(font,"g",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "g";
	    break;
	  case SDLK_h:
	    text = TTF_RenderText_Shaded(font,"h",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "h";
	    break;
	  case SDLK_i:
	    text = TTF_RenderText_Shaded(font,"i",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "i";
	    break;
	  case SDLK_j:
	    text = TTF_RenderText_Shaded(font,"j",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "j";
	    break;
	  case SDLK_k:
	    text = TTF_RenderText_Shaded(font,"k",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "k";
	    break;
	  case SDLK_l:
	    text = TTF_RenderText_Shaded(font,"l",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "l";
	    break;
	  case SDLK_m:
	    text = TTF_RenderText_Shaded(font,"m",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "m";
	    break;
	  case SDLK_n:
	    text = TTF_RenderText_Shaded(font,"n",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "n";
	    break;
	  case SDLK_o:
	    text = TTF_RenderText_Shaded(font,"o",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "o";
	    break;
	  case SDLK_p:
	    text = TTF_RenderText_Shaded(font,"p",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "p";
	    break;
	  case SDLK_q:
	    text = TTF_RenderText_Shaded(font,"q",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "q";
	    break;
	  case SDLK_r:
	    text = TTF_RenderText_Shaded(font,"r",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "r";
	    break;
	  case SDLK_s:
	    text = TTF_RenderText_Shaded(font,"s",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "s";
	    break;
	  case SDLK_t:
	    text = TTF_RenderText_Shaded(font,"t",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "t";
	    break;
	  case SDLK_u:
	    text = TTF_RenderText_Shaded(font,"u",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "u";
	    break;
	  case SDLK_v:
	    text = TTF_RenderText_Shaded(font,"v",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "v";
	    break;
	  case SDLK_w:
	    text = TTF_RenderText_Shaded(font,"w",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "w";
	    break;
	  case SDLK_x:
	    text = TTF_RenderText_Shaded(font,"x",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "x";
	    break;
	  case SDLK_y:
	    text = TTF_RenderText_Shaded(font,"y",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "y";
	    break;
	  case SDLK_z:
	    text = TTF_RenderText_Shaded(font,"z",textColor,bColor);
	    blit(textX,textY,text,displaySurface);
	    SDL_Flip(displaySurface);
	    textX+=15;
	    return "z";
	    break;
	  case SDLK_RETURN:
	    done = true;
	    return "done";
	    break;
	  }
	}
      }
  }
}

void closeText(){
  // will close text
}

#endif
