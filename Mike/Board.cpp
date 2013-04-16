#include "Board.h"
#include "Tile.h"
#include "Property.h"
#include "Railroad.h"
#include "CardSpaces.h"
#include "Bland.h"
#include "Tax.h"
#include "Jail.h"
#include "Utility.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

Board::Board()
{
	spaces.push_back(new Bland(0, "GO", -1, 0, 0, 0));
	spaces.push_back(new Property(1, "Pasquerilla East", -1, 0, 0, 0, 60, 0, 0, 2, 0));
	spaces.push_back(new CardSpaces(0, "S.A.O.", -1, 0, 2, 0));
	spaces.push_back(new Property(1, "Pasquerilla West", -1, 0, 0, 0, 60, 0, 0, 4, 0));
	spaces.push_back(new Tax(0, "Hall Tax", -1, -75, 0, 0));
	spaces.push_back(new Railroad(9, "Coleman Morris Center", -1, 0, 0, 0, 200, 25));	
	spaces.push_back(new Property(2, "Seigfried Hall", -1, 0, 0, 0, 100, 0, 0, 6, 0));
	spaces.push_back(new CardSpaces(0, "S.U.B.", -1, 0, 1, 0));				//might need a new class, some way of calling cards				
	spaces.push_back(new Property(2, "Lewis Hall", -1, 0, 0, 0, 100, 0, 0, 6, 0));
	spaces.push_back(new Property(2, "Carrol Hall", -1, 0, 0, 0, 120, 0, 0, 8, 0));
	spaces.push_back(new Jail(0, "Res Life", -1, 0, 0, 0));				//need a new class for this likely
	spaces.push_back(new Property(3, "Fisher Hall", -1, 0, 0, 0, 140, 0, 0, 10, 0));
	spaces.push_back(new Utility(10, "North Dining Hall", -1, 0, 0, 0, 150, 10, 0));			//this likely needs a new class, as does south. Utilities
	spaces.push_back(new Property(3, "Dillon Hall", -1, 0, 0, 0, 140, 0, 0, 10, 0));
	spaces.push_back(new Property(3, "Alumni Hall", -1, 0, 0, 0, 160, 0, 0, 12, 0));
	spaces.push_back(new Railroad(9, "DeBartolo Hall", -1, 0, 0, 0, 200, 25));	//need a different moneyEffect function for railroads
	spaces.push_back(new Property(4, "Badin Hall", -1, 0, 0, 0, 180, 0, 0, 14, 0));
	spaces.push_back(new CardSpaces(0, "S.A.O.", -1, 0, 2, 0));
	spaces.push_back(new Property(4, "Howard Hall", -1, 0, 0, 0, 180, 0, 0, 14, 0));
	spaces.push_back(new Property(4, "Lyons Hall", -1, 0, 0, 0, 200, 0, 0, 16, 0));
	spaces.push_back(new Bland(0, "D6 Parking", -1, 0, 0, 0));
	spaces.push_back(new Property(5, "Ryan Hall", -1, 0, 0, 0, 220, 0, 0, 18, 0));
	spaces.push_back(new CardSpaces(0, "S.U.B.", -1, 0, 1, 0));
	spaces.push_back(new Property(5, "McGlinn Hall", -1, 0, 0, 0, 220, 0, 0, 18, 0));
	spaces.push_back(new Property(5, "Welsh Family Hall", -1, 0, 0, 0, 240, 0, 0, 20, 0));
	spaces.push_back(new Railroad(9, "Lafortune Student Center", -1, 0, 0, 0, 200, 25));
	spaces.push_back(new Property(6, "O'Neill Hall", -1, 0, 0, 0, 260, 0, 0, 22, 0));
	spaces.push_back(new Property(6, "Keough Hall", -1, 0, 0, 0, 260, 0, 0, 22, 0));
	spaces.push_back(new Utility(10, "South Dining Hall", -1, 0, 0, 0, 150, 10, 0));
	spaces.push_back(new Property(6, "Duncan Hall", -1, 0, 0, 0, 280, 0, 0, 24, 0));
	spaces.push_back(new Jail(0, "Go to Res Life", -1, 0, 0, 0));			//almost definitely need a new class, need a way of moving player
	spaces.push_back(new Property(7, "Compton Ice Arena", -1, 0, 0, 0, 300, 0, 0, 26, 0));
	spaces.push_back(new Property(7, "J.A.C.C.", -1, 0, 0, 0, 300, 0, 0, 26, 0));
	spaces.push_back(new CardSpaces(0, "S.A.O.", -1, 0, 2, 0));
	spaces.push_back(new Property(7, "Notre Dame Stadium", -1, 0, 0, 0, 320, 0, 0, 28, 0));
	spaces.push_back(new Railroad(9, "Hesburgh Library", -1, 0, 0, 0, 200, 25));
	spaces.push_back(new CardSpaces(0, "S.U.B.", -1, 0, 1, 0));
	spaces.push_back(new Property(8, "Main Building", -1, 0, 0, 0, 350, 0, 0, 35, 0));
	spaces.push_back(new Tax(0, "Luxury Tax", -1, -75, 0, 0));
	spaces.push_back(new Property(8, "The Grotto", -1, 0, 0, 0, 400, 0, 0, 50, 0));
}

Board::~Board()
{
}

Tile* Board::accessSpace(int location)
{
	return spaces[location];
}

void Board::checkGroupsProp()
{
	bool makeChange = 0;
	for(int i = 0; i < 40; i++)
	{
		for(int j = 1; j < 9; j++)
		{
			makeChange = 1;
			if(j == spaces[i]->getGroup() && spaces[i]->getOwner() != -1)
			{
				for(int k = 0; k < 40; k++)
				{
					if(spaces[k]->getGroup() == j)
					{
						if(spaces[k]->getOwner() != spaces[i]->getOwner())
						{
							makeChange = 0;
						}
					}
				}
				if(makeChange != 0)
				{
					for(int m = 0; m < 40; m++)
					{
						if(spaces[m]->getGroup() == j)
						{
							spaces[m]->setGroupOwned(makeChange);
						}
					}
				}
			}
		}
	}
}

void Board::updateRentRR()
{
	int count;
	int tempOwner;

	for(int i = 5; i <= 35; i++)
	{
		count = 0;
		tempOwner = spaces[i]->getOwner();
		if(tempOwner != -1)
		{
			for(int j = 5; j <= 35; j++)
			{
				if(spaces[j]->getOwner() == tempOwner)
				{
					++count;
				}
			}
			for(int k = 5; k <= 35; k++)
			{
				if(spaces[k]->getOwner() == tempOwner)
				{
					spaces[k]->updateEffect(count);
				}
			}
		}
	}
}

void Board::updateEffects(int roll)
{
	for(int i = 0; i < 40; i++)
	{
		if(spaces[i]->getGroup() > 0 && spaces[i]->getGroup() < 9)
		{
			spaces[i]->updateEffect(0);
		}
		if(spaces[i]->getGroup() == 10)
		{
			spaces[i]->updateEffect(roll);
		}
	}
}

void Board::updateUtilityEffect()
{
	if(spaces[12]->getOwner() == spaces[28]->getOwner() && spaces[12]->getOwner() != -1)
	{
		spaces[12]->setGroupOwned(2);
		spaces[28]->setGroupOwned(2);
		return;
	}
	else if(spaces[12]->getOwner() != -1 && spaces[28]->getOwner() != -1 && spaces[12]->getOwner() != spaces[28]->getOwner())
	{
		spaces[12]->setGroupOwned(1);
		spaces[28]->setGroupOwned(1);
		return;
	}
	else
	{
		if(spaces[12]->getOwner() != -1)
		{
			spaces[12]->setGroupOwned(1);
			return;
		}
		if(spaces[28]->getOwner() != -1)
		{
			spaces[28]->setGroupOwned(1);
			return;
		}
	}
}
	
			
