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
	private:
		vector<Tile> spaces;	//should end up stored as a cdl list, so player can travel around board
};
#endif
