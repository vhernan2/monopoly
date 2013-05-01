#include "Monopoly_Board.h"
#include "Mike/Game.h"
#include "Mike/SDL_logic.h"
#include "Victor/menu.h"
#include "Victor/audio.h"

using namespace std;

int main (){

	int players = 2;
	Game playMonopoly(players);

	int current, location;
	Monopoly_Board showMonopoly(players);
	//this gets the screen that we display on
	SDL_Surface *screen = showMonopoly.getScreen();

	playMonopoly.addScreen(screen);
//	while not quit
//		Victor
		while (showMonopoly.keep_playing()){
			playMonopoly.turn();
			current = playMonopoly.getCurrentPlayer();
			location = playMonopoly.getPlayerLocation(current);
			showMonopoly.turn(current, location);
		}
//		should we quit
//	end loop
	showMonopoly.clean_up();

}
