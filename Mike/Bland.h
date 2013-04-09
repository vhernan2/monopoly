#ifndef BLAND_H
#define BLAND_H
#include "Tile.h"
#include "Player.h"
using namespace std;

class Bland : public Tile
{
	public:
		Bland();
		Bland(int, string, int, int, int, int);
		virtual int interact(Player*);
};
#endif

