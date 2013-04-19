#ifndef RAILROAD_H
#define RAILROAD_H
#include "Tile.h"
#include "Player.h"
using namespace std;

class Railroad : public Tile
{
	public:
		Railroad(int, string, int, int, int, bool, int, int);
		virtual int interact(Player*);
		virtual void payBack(Player*);
		virtual void updateEffect(int);

	private:
		int cost;
		int rent;
};
#endif
