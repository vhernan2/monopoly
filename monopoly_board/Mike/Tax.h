#ifndef TAX_H
#define TAX_H
#include "Tile.h"
#include "Player.h"
using namespace std;

class Tax : public Tile
{
	public:
		Tax();
		Tax(int, string, int, int, int, bool);
		virtual int interact(Player*);
};
#endif
