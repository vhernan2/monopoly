#include "Board.h"
#include "Tile.h"
#include "Property.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

Board::Board()
{
	//blank for now, will be used to fill spaces as they should be, with spaces[0] being GO
	spaces.push_back(Tile("GO", -1, 200, 0));
	spaces.push_back(Property("Lewis Hall", -1, 0, 0, 100, 0, 0));
}

Board::~Board()
{
}
