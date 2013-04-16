#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Tile.h"
#include "Board.h"
#include "Property.h"
using namespace std;

class Game
{
	public:
		Game();
		~Game();
		void turn();
		void playerTurn(Player*);
		void rollDie(Player*);
		void buildCheck(Player*);
		void build(Player*);
		int getPlayers();
		int getCurrentPlayer();
		int getPlayerLocation(int);

	private:
		int numPlayers;
		int curPlayer;
		vector<Player> players;
		Board gameBoard;
};
#endif
