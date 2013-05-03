#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Tile.h"
//#include "menu.h"
//#include "prompts.h"
#include "Board.h"
#include "Property.h"
#include "SDL_logic.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

using namespace std;

class Game
{
	public:
		Game(int);
		~Game();
		int turn();
		int playerTurn(Player*);
		int playerPostRoll(Player *);
		int rollDie(Player*);
		void buildCheck(Player*);
		void applyHouses(int, int);
		void build(Player*);
		int getPlayers();
		int getCurrentPlayer();
		int getPlayerLocation(int);
		int view_zoom(Player*);
		void view(Player*);
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

		SDL_Surface *sdlText;
		TTF_Font *font;

		SDL_Surface *endOfGame;

		SDL_Surface *preRollImage;
		SDL_Surface *postRollImage;
		SDL_Surface *sprites;
		SDL_Surface *whitespace;

		SDL_Surface *acceptTrade;
        	SDL_Surface *cleanBackground;
	        SDL_Surface *closeButton;
        	SDL_Surface *noButton;
	        SDL_Surface *tradeForThis;
        	SDL_Surface *tradeThis;
	        SDL_Surface *yesButton;

	        SDL_Surface *mortgageHere;
	        SDL_Surface *mortgageText;
	        SDL_Surface *unmortgageText;
	        SDL_Surface *buildHere;
		SDL_Surface *payJail;
		SDL_Surface *pickBuild;
		SDL_Surface *buildRooms;
		SDL_Surface *buildSM;
        
	        SDL_Surface *oneButton;
        	SDL_Surface *twoButton;
	        SDL_Surface *threeButton;
        	SDL_Surface *fourButton;
	        SDL_Surface *hotelButton;



		SDL_Surface *houseImage[6];
		SDL_Surface *tile[40];
		SDL_Surface *backTile[40];
		SDL_Surface *SAOcard[14];
		SDL_Surface *SUBcard[14];
		SDL_Surface *tradeScreen[7];
		SDL_Surface *FS[401];


};
#endif
