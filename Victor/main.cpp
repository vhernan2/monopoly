#include <iostream>
#include <string>
#include "functions.h"
#include "menu.h"
#include "audio.h"
using namespace std;

// global variables


int main (int argc, char* argv[]){
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();
  mainMenu();

}
