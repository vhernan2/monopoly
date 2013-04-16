#ifndef CARDSPACES_H
#define CARDSPACES_H
#include "Tile.h"
#include "Player.h"
#include "Board.h"
using namespace std;

class CardSpaces : public Tile
{
	public:
		CardSpaces();
		CardSpaces(int, string, int, int, int, bool);
		virtual int interact(Player* );
		virtual void manDeck(Player*, Board*);

};
#endif
