#include "players.h"

players::players(){
  cash = 1000;  

}

void players::printCash(){
  cout<<cash<<endl;
}

void players::addCash(int addon){
  cash+=addon;
}

void players::setName(string n){
  Name=n;
}

string player::getName(){
  return Name;
}

