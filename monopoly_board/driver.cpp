#include "Monopoly_Board.h"
#include "Mike/Game.h"
#include "Mike/SDL_logic.h"

using namespace std;

int main (){

	Game playMonopoly;
	cout << "playMonopoly success \n";
	int players = playMonopoly.getPlayers();
	int current, location;
	cout << "getPlayers() success\n";
	Monopoly_Board showMonopoly(players);
	cout << "showMonopoly() success\n";
	SDL_Surface *screen = showMonopoly.getScreen();
	playMonopoly.addScreen(screen);
	cout << "playMonopoly() success\n";

	while (showMonopoly.keep_playing()){
		playMonopoly.turn();
		current = playMonopoly.getCurrentPlayer();
		location = playMonopoly.getPlayerLocation(current);
		showMonopoly.turn(current, location);
	}

	showMonopoly.clean_up();

}
