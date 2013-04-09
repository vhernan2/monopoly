#ifndef RAILROAD_H
#define RAILROAD_H
#include "Tile.h"
#include "Player.h"
using namespace std;

class Railroad : public Tile
{
	public:
		Railroad(string, int, int, int, int);
		virtual void interact(Player*);

	private:
		int cost;
};
#endif
