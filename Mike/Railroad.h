#ifndef RAILROAD_H
#define RAILROAD_H
#include "Tile.h"
#include "Player.h"
#include "SDL_logic.h"
using namespace std;

class Railroad : public Tile
{
	public:
		Railroad(int, string, int, int, int, bool, int, int, bool);
		virtual int buy(Player*);
		virtual int interact(Player*);
		virtual void payBack(Player*);
		virtual void updateEffect(int);
		virtual int getCost();
		virtual void setMortgage(bool);
		virtual bool getMortgage();

	private:
		int cost;
		int rent;
		bool mortgaged;
		SDL_logic sdl;
};
#endif
