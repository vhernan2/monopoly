#include "Tile.h"
#include <iostream>
using namespace std;

Tile::Tile()
{
	title = "";
	owner = -1;
	moneyEffect = 0;
	takeCard = 0;
}

Tile::Tile(string text, int ownedBy, int money, int take)
{
	title = text;
	owner = ownedBy;
	moneyEffect = money;
	takeCard = take;
}

Tile::~Tile()
{
}

void Tile::setOwner(int player)
{
	owner = player;
}
