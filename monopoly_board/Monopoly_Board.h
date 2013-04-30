#ifndef MONOPOLY_BOARD_H
#define MONOPOLY_BOARD_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <fstream>

#include "Mike/Player.h"
#include "Mike/Tile.h"
#include "Mike/Board.h"
#include "Mike/Property.h"
#include "Mike/Game.h"
#include "Mike/CardSpaces.h"
#include "Mike/Bland.h"
#include "Mike/Tax.h"
#include "Mike/Jail.h"
#include "Mike/Utility.h"
#include "Mike/SDL_logic.h"
#include "Mike/SDL_logic.h"
#include "PlayerPiece.h"


using namespace std;

class Monopoly_Board{
public:

	Monopoly_Board(int);
	~Monopoly_Board();
	SDL_Surface *load_image( string );
	void apply_surface (int, int, SDL_Surface *, SDL_Surface *);
	bool init();
	bool load_files(int);
	void clean_up();
	bool keep_playing();
	void turn(int, int);

	SDL_Surface *getScreen();

private:

	int players;

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	int SCREEN_BPP; 

	SDL_Surface *background;
	SDL_Surface *piece[8];
	SDL_Surface *screen;
	SDL_Event event;

	PlayerPiece unique_piece[4];

	SDL_logic sdl;
};
#endif	
