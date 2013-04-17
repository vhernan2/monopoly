#include <iostream>
#include <string>
#include "functions.h"
#include "menu.h"
using namespace std;

// global variables



int main (int argc, char* argv[]){
 SDL_Init(SDL_INIT_EVERYTHING);

  // ensure that SDL subsystems are up and running
  if ( SDL_Init (SDL_INIT_EVERYTHING ) ==1 ){
    cout << "ERROR INITIALIZING SDL" << endl;
  }


  mainMenu();

  
}
