#ifndef UTILITY_H
#define UTILITY_H
#include "Tile.h"
#include "Player.h"
#include "SDL_logic.h"
using namespace std;

class Utility : public Tile
{
	public:
		Utility();
		Utility(int, string, int, int, int, bool, int, int, int);
		virtual int interact(Player*);
		virtual void payBack(Player*);
		virtual void updateEffect(int);
		virtual void setGroupOwned(int);

	private:
		SDL_logic sdl;
		int cost;
		int rent;
		int numOwned;
};
#endif
