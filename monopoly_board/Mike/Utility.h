#ifndef UTILITY_H
#define UTILITY_H
#include "Tile.h"
#include "Player.h"
using namespace std;

class Utility : public Tile
{
	public:
		Utility();
		Utility(int, string, int, int, int, bool, int, int);
		virtual int interact(Player*);
		virtual void payBack(Player*);
		virtual void updateEffect(int);

	private:
		int cost;
		int rent;
};
#endif
