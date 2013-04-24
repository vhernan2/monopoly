#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Tile.h"
#include "Board.h"
#include "Property.h"
#include "SDL_logic.h"

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

using namespace std;

class Game
{
	public:
		Game();
		~Game();
		void turn();
		void playerTurn(Player*);
		int rollDie(Player*);
		void buildCheck(Player*);
		void build(Player*);
		int getPlayers();
		int getCurrentPlayer();
		int getPlayerLocation(int);
		void trade(Player*);
		int gameOver();
		void jailTime(Player*);
		void mortgage(Player*);

	private:
		int numPlayers;
		int curPlayer;
		vector<Player> players;
		Board gameBoard;
		SDL_logic sdl;
};
#endif
