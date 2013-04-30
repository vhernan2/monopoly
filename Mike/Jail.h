#ifndef JAIL_H
#define JAIL_H
#include "Tile.h"
#include "Player.h"
#include "SDL_logic.h"
using namespace std;

class Jail : public Tile
{
	public:
		Jail();
		Jail(int, string, int, int, int, bool);
		virtual int interact(Player*);

	private:
		SDL_logic sdl;
};
#endif
