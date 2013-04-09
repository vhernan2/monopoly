#ifndef CARDSPACES_H
#define CARDSPACES_H
#include "Tile.h"
#include "Player.h"
using namespace std;

class CardSpaces : public Tile
{
	public:
		CardSpaces();
		CardSpaces(int, string, int, int, int, bool);
		virtual int interact(Player* );

};
#endif
