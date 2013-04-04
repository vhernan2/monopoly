#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <deque>
#include <string>
#include "Tile.h"
using namespace std;

class Player
{
	public: 
		Player();			//constructor
		~Player();
		int getMoney();			//gets player's money total
		int getJail();			//gets player's jail status
		void setGamePiece(int);		//sets players piece value
		void setName(string);		//sets player's name
		string getName();		//gets player's name
		int getPosition();		//gets player's position
		void goToJail();		//sends player's piece to jail location and changes inJail
		void changeInMoney(int);	//can be used to add or subtract money from totalMoney		
		void advance(int);		//will change piece's position

	private:
		int totalMoney;	//players total money
		string name;	//player may have option to provide name in future
		int piece;	//integer value representing game piece
		bool inJail;	//bool for player being in jail or not in jail
		int xLoc;	//x location on board
		int yLoc;	//y location on board
		int zLoc;	//z location on board
			
		int position; 	//used for index as to player's location on board

		deque<Tile> tilesOwned;
};
#endif


//need method of implementing positions on board
