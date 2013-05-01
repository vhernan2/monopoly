#include <iostream>
#include <string>
#include "menu.h"
#include "audio.h"
#include "prompts.h"
using namespace std;

// global variables


int main (int argc, char* argv[]){
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();
  font = TTF_OpenFont("/usr/share/fonts/sil-padauk/Padauk.ttf", 28);
  if (TTF_Init() == -1 || font == NULL)
    cout << "FONT ERROR" << endl;

  SDL_Surface *test = TTF_RenderText_Shaded(font, "Name FOOBAR: ", textColor,bColor);
  int players;
  if(mainMenu() == -1)
    players = startMenu();
  
  if (players != 0 ){
  blit(10,10,test,display);
  SDL_Flip(display);


  string append(decipher(display));
  string name;
    
  for (int i = 0 ; i < players ; i++){
   
    while (append != "0"){
      name = name+append;
      append = decipher(display);
    }
    cout << "Name: " << name << endl;
    SDL_FillRect(display,NULL,0x000000);
    SDL_Flip(display);

    blit(10,10,test,display);
    SDL_Flip(display);

  }
  }

}
