#include "Board.h"
#include "Tile.h"
#include "Property.h"
#include "Railroad.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

Board::Board()
{
	//blank for now, will be used to fill spaces as they should be, with spaces[0] being GO
	spaces.push_back(Tile("GO", -1, 0, 0));
	spaces.push_back(Property("Pasquerilla East", -1, 0, 0, 60, 0, 0));
	spaces.push_back(Tile("S.A.O.", -1, 0, 2));
	spaces.push_back(Property("Pasquerilla West", -1, 0, 0, 60, 0, 0));
	spaces.push_back(Tile("Hall Tax", -1, -75, 0));
	spaces.push_back(Railroad("Coleman Morris Center", -1, 0, 0, 200));	
	spaces.push_back(Property("Seigfried Hall", -1, 0, 0, 100, 0, 0));
	spaces.push_back(Tile("S.U.B.", -1, 0, 1));				//might need a new class, some way of calling cards				
	spaces.push_back(Property("Lewis Hall", -1, 0, 0, 100, 0, 0));
	spaces.push_back(Property("Carrol Hall", -1, 0, 0, 120, 0, 0));
	spaces.push_back(Tile("Res Life", -1, 0, 0));				//need a new class for this likely
	spaces.push_back(Property("Fisher Hall", -1, 0, 0, 140, 0, 0));
	spaces.push_back(Tile("North Dining Hall", -1, 0, 0));			//this likely needs a new class, as does south. Utilities
	spaces.push_back(Property("Dillon Hall", -1, 0, 0, 140, 0, 0));
	spaces.push_back(Property("Alumni Hall", -1, 0, 0, 160, 0, 0));
	spaces.push_back(Railroad("DeBartolo Hall", -1, 0, 0, 200));	//need a different moneyEffect function for railroads
	spaces.push_back(Property("Badin Hall", -1, 0, 0, 180, 0, 0));
	spaces.push_back(Tile("S.A.O.", -1, 0, 2));
	spaces.push_back(Property("Howard Hall", -1, 0, 0, 180, 0, 0));
	spaces.push_back(Property("Lyons Hall", -1, 0, 0, 200, 0, 0));
	spaces.push_back(Tile("D6 Parking", -1, 0, 0));
	spaces.push_back(Property("Ryan Hall", -1, 0, 0, 220, 0, 0));
	spaces.push_back(Tile("S.U.B.", -1, 0, 1));
	spaces.push_back(Property("McGlinn Hall", -1, 0, 0, 220, 0, 0));
	spaces.push_back(Property("Welsh Family Hall", -1, 0, 0, 240, 0, 0));
	spaces.push_back(Railroad("Lafortune Student Center", -1, 0, 0, 200));
	spaces.push_back(Property("O'Neill Hall", -1, 0, 0, 260, 0, 0));
	spaces.push_back(Property("Keough Hall", -1, 0, 0, 260, 0, 0));
	spaces.push_back(Tile("South Dining Hall", -1, 0, 0));
	spaces.push_back(Property("Duncan Hall", -1, 0, 0, 280, 0, 0));
	spaces.push_back(Tile("Go to Res Life", -1, 0, 0));			//almost definitely need a new class, need a way of moving player
	spaces.push_back(Property("Compton Ice Arena", -1, 0, 0, 300, 0, 0));
	spaces.push_back(Property("J.A.C.C.", -1, 0, 0, 300, 0, 0));
	spaces.push_back(Tile("S.A.O.", -1, 0, 2));
	spaces.push_back(Property("Notre Dame Stadium", -1, 0, 0, 320, 0, 0));
	spaces.push_back(Railroad("Hesburgh Library", -1, 0, 0, 200));
	spaces.push_back(Tile("S.U.B.", -1, 0, 1));
	spaces.push_back(Property("Main Building", -1, 0, 0, 350, 0, 0));
	spaces.push_back(Tile("Luxury Tax", -1, -75, 0));
	spaces.push_back(Property("The Grotto", -1, 0, 0, 400, 0, 0));
}

Board::~Board()
{
}
