#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <vector>
#include "Tile.h"

class Board
{
	public:
		Board();
		~Board();
		Tile* accessSpace(int);	//used to access private data members of board		
		void updateRent();
		void checkGroupsProp();	//checks groups of tiles to see if they have the same owner throughout
		void updateRentRR();	//updates the rent penalty for railroad type locations
		void updateEffects(int);	//updates the rent of all properties
		void updateUtilityEffect();	//updates money effects of all utilities (north and south dh)

	private:
		vector<Tile*> spaces;
};
#endif
