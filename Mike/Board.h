#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include "Tile.h"
#include "SUB.h"
#include "SAO.h"

class Board
{
	public:
		Board();
		~Board();
		Tile* accessSpace(int);	//used to access private data members of board		
		void updateRent();
		void checkDecks();
		void checkGroupsProp();	//checks groups of tiles to see if they have the same owner throughout
		void updateRentRR();	//updates the rent penalty for railroad type locations
		void updateEffects(int);	//updates the rent of all properties
		void updateUtilityEffect();	//updates money effects of all utilities (north and south dh)
		void buildSUB();		//builds SUB deck of cards
		void buildSAO();		//builds SAO deck of cards

		//group used to access cards

		int accessMoney(int);
		int accessPos(int);
		bool accessGOOJ(int);
		int accessMove(int);
		bool accessRR(int);
		bool accessDH(int);
		void printDescription(int);
		bool accessGTJ(int);
		void alterDeck(int);


	private:
		vector<Tile*> spaces;
		deque<SUB> subDeck;
		deque<SAO> saoDeck;
};
#endif
