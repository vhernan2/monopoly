#include "Monopoly_Board.h"
#include "Mike/Game.h"
#include "Mike/SDL_logic.h"

using namespace std;

int main (){

	Game playMonopoly;
	int players = playMonopoly.getPlayers();
	int current, location;
	Monopoly_Board showMonopoly(players);

	while (showMonopoly.keep_playing()){
		playMonopoly.turn();
		current = playMonopoly.getCurrentPlayer();
		location = playMonopoly.getPlayerLocation(current);
		showMonopoly.turn(current, location);
	}

	showMonopoly.clean_up();

}
