#ifndef TILE_H
#define TILE_H
#include <iostream>
#include <string>
using namespace std;

class Tile
{
	public:
		Tile();
		Tile(string, int, int, int);
		~Tile();
		void setOwner(int);	//sets an owner for the tile

	protected:
		string title;	 //label used for tile
		int owner;	 //int representing index in vector of players as to which player owns tile. If unowned, equals -1
		int moneyEffect; //positive, negative, or zero money effect based on nature and ownership of tile
		int takeCard;	 //0 gets player no card, 1 gets sub card, 2 gets sao card
				//coordinates may be added at a later date
		
};
#endif
