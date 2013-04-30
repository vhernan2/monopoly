#include "Monopoly_Board.h"
#include "Mike/Game.h"
#include "Mike/SDL_logic.h"
#include "Victor/menu.h"

using namespace std;

int main (){

	Game playMonopoly;
	cout << "playMonopoly success \n";
	int players = playMonopoly.getPlayers();
	int current, location;
	cout << "getPlayers() success\n";
	Monopoly_Board showMonopoly(players);
	cout << "showMonopoly() success\n";

	//this gets the screen that we display on
	SDL_Surface *screen = showMonopoly.getScreen();

	//Victor(screen)
	mainMenu();

	//passses screen into Game
	playMonopoly.addScreen(screen);
	cout << "playMonopoly() success\n";
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
