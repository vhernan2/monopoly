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
		Game(int);
		~Game();
		void turn();
		void playerTurn(Player*);
		void playerPostRoll(Player *);
		int rollDie(Player*);
		void buildCheck(Player*);
		void applyHouses(int, int);
		void build(Player*);
		int getPlayers();
		int getCurrentPlayer();
		int getPlayerLocation(int);
		int view(Player*);
		void trade(Player*);
		int gameOver();
		void jailTime(Player*);
		void mortgage(Player*);

		void addScreen(SDL_Surface *);

	private:
		int numPlayers;
		int curPlayer;
		vector<Player> players;
		Board gameBoard;
		SDL_logic sdl;
		SDL_Surface* screen;
		
		SDL_Surface *preRollImage;
		SDL_Surface *postRollImage;
		SDL_Surface *sprites;
		SDL_Surface *whitespace;

		SDL_Surface *houseImage[6];
		SDL_Surface *tile[40];
		SDL_Surface *backTile[40];
		SDL_Surface *SAOcard[13];
		SDL_Surface *SUBcard[14];
		SDL_Surface *tradeScreen[7];
		SDL_Surface *FS[401];
};
#endif
