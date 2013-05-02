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
#include <deque>
#include <cstdlib>
#include <ctime>
using namespace std;

Board::Board()
{
	spaces.push_back(new Bland(0, "GO", -1, 0, 0, 0));
	spaces.push_back(new Property(1, "Pasquerilla East", -1, 0, 0, 0, 60, 0, 0, 2, 10, 30, 90, 160, 250, 0, 0));
	spaces.push_back(new CardSpaces(0, "S.A.O.", -1, 0, 2, 0));
	spaces.push_back(new Property(1, "Pasquerilla West", -1, 0, 0, 0, 60, 0, 0, 4, 20, 60, 180, 320, 450, 0, 0));
	spaces.push_back(new Tax(0, "Hall Tax", -1, -75, 0, 0));
	spaces.push_back(new Railroad(9, "Coleman Morris Center", -1, 0, 0, 0, 200, 25, 0));	
	spaces.push_back(new Property(2, "Seigfried Hall", -1, 0, 0, 0, 100, 0, 0, 6, 30, 90, 270, 400, 550, 0, 0));
	spaces.push_back(new CardSpaces(0, "S.U.B.", -1, 0, 1, 0));				//might need a new class, some way of calling cards				
	spaces.push_back(new Property(2, "Lewis Hall", -1, 0, 0, 0, 100, 0, 0, 6, 30, 90, 270, 400, 550, 0, 0));
	spaces.push_back(new Property(2, "Carrol Hall", -1, 0, 0, 0, 120, 0, 0, 8, 40, 100, 300, 450, 600, 0, 0));
	spaces.push_back(new Jail(0, "Res Life", -1, 0, 0, 0));				//need a new class for this likely
	spaces.push_back(new Property(3, "Fisher Hall", -1, 0, 0, 0, 140, 0, 0, 10, 50, 150, 450, 625, 750, 0, 0));
	spaces.push_back(new Utility(10, "North Dining Hall", -1, 0, 0, 0, 150, 10, 0, 0));			//this likely needs a new class, as does south. Utilities
	spaces.push_back(new Property(3, "Dillon Hall", -1, 0, 0, 0, 140, 0, 0, 10, 50, 150, 450, 625, 750, 0, 0));
	spaces.push_back(new Property(3, "Alumni Hall", -1, 0, 0, 0, 160, 0, 0, 12, 60, 180, 500, 700, 900, 0, 0));
	spaces.push_back(new Railroad(9, "DeBartolo Hall", -1, 0, 0, 0, 200, 25, 0));	//need a different moneyEffect function for railroads
	spaces.push_back(new Property(4, "Badin Hall", -1, 0, 0, 0, 180, 0, 0, 14, 70, 200, 550, 750, 950, 0, 0));
	spaces.push_back(new CardSpaces(0, "S.A.O.", -1, 0, 2, 0));
	spaces.push_back(new Property(4, "Howard Hall", -1, 0, 0, 0, 180, 0, 0, 14, 70, 200, 550, 750, 950, 0, 0));
	spaces.push_back(new Property(4, "Lyons Hall", -1, 0, 0, 0, 200, 0, 0, 16, 80, 220, 600, 800, 1000, 0, 0));
	spaces.push_back(new Bland(0, "D6 Parking", -1, 0, 0, 0));
	spaces.push_back(new Property(5, "Ryan Hall", -1, 0, 0, 0, 220, 0, 0, 18, 90, 250, 700, 875, 1050, 0, 0));
	spaces.push_back(new CardSpaces(0, "S.U.B.", -1, 0, 1, 0));
	spaces.push_back(new Property(5, "McGlinn Hall", -1, 0, 0, 0, 220, 0, 0, 18, 90, 250, 700, 875, 1050, 0, 0));
	spaces.push_back(new Property(5, "Welsh Family Hall", -1, 0, 0, 0, 240, 0, 0, 20, 100, 300, 750, 925, 1100, 0, 0));
	spaces.push_back(new Railroad(9, "Lafortune Student Center", -1, 0, 0, 0, 200, 25, 0));
	spaces.push_back(new Property(6, "O'Neill Hall", -1, 0, 0, 0, 260, 0, 0, 22, 110, 330, 800, 975, 1150, 0, 0));
	spaces.push_back(new Property(6, "Keough Hall", -1, 0, 0, 0, 260, 0, 0, 22, 110, 330, 800, 975, 1150, 0, 0));
	spaces.push_back(new Utility(10, "South Dining Hall", -1, 0, 0, 0, 150, 10, 0, 0));
	spaces.push_back(new Property(6, "Duncan Hall", -1, 0, 0, 0, 280, 0, 0, 24, 120, 360, 850, 1025, 1200, 0, 0));
	spaces.push_back(new Jail(0, "Go to Res Life", -1, 0, 0, 0));			//almost definitely need a new class, need a way of moving player
	spaces.push_back(new Property(7, "Compton Ice Arena", -1, 0, 0, 0, 300, 0, 0, 26, 130, 390, 900, 1100, 1275, 0, 0));
	spaces.push_back(new Property(7, "J.A.C.C.", -1, 0, 0, 0, 300, 0, 0, 26, 130, 390, 900, 1100, 1275, 0, 0));
	spaces.push_back(new CardSpaces(0, "S.A.O.", -1, 0, 2, 0));
	spaces.push_back(new Property(7, "Notre Dame Stadium", -1, 0, 0, 0, 320, 0, 0, 28, 150, 450, 1000, 1200, 1400, 0, 0));
	spaces.push_back(new Railroad(9, "Hesburgh Library", -1, 0, 0, 0, 200, 25, 0));
	spaces.push_back(new CardSpaces(0, "S.U.B.", -1, 0, 1, 0));
	spaces.push_back(new Property(8, "Main Building", -1, 0, 0, 0, 350, 0, 0, 35, 175, 500, 1100, 1300, 1500, 0, 0));
	spaces.push_back(new Tax(0, "Luxury Tax", -1, -75, 0, 0));
	spaces.push_back(new Property(8, "The Grotto", -1, 0, 0, 0, 400, 0, 0, 50, 200, 600, 1400, 1700, 2000, 0, 0));

	//fill in the SUB and SAO decks of cards

	buildSUB();
	buildSAO();

}

Board::~Board()
{
}

void Board::buildSUB()
{
	int i;
	int j;
//	srand(time(NULL));

	subDeck.push_back(SUB("You won a student raffle! Collect $50!", 0, 0, 50, -1, 0, 0));
	subDeck.push_back(SUB("Pay for a SUB movie for a friend! You lose $25!", 1, 0, -25, -1, 0, 0));
	subDeck.push_back(SUB("Went to see a movie at DPAC! Spent $25!", 2, 0, -25, -1, 0, 0));
	subDeck.push_back(SUB("Picked up at Legends by NDSP! Go to Res Life!", 3, 0, 0, -1, 0, 1));
	subDeck.push_back(SUB("Got to Reckers at 2:01 a.m. on the weekend... Move back 3 spaces", 4, 0, 0, -1, -3, 0));
	subDeck.push_back(SUB("Dorm trip to the Grotto.", 5, 0, 0, 39, 0, 0));
	subDeck.push_back(SUB("Your RA lost their paperwork. You can get out of Res Life early next time!", 6, 1, 0, -1, 0, 0));
	subDeck.push_back(SUB("Weekend trip to Chicago! Spent $250", 7, 0, -250, -1, 0, 0));
	subDeck.push_back(SUB("You picked up the tab at Brothers. You lose $100!", 8, 0, -100, -1, 0, 0));
	subDeck.push_back(SUB("Band stipend! Gained $200!", 9, 0, 200, -1, 0, 0));
	subDeck.push_back(SUB("Forgot to get a parking pass, your car got towed! Lost $50!", 10, 0, -50, -1, 0, 0));
	subDeck.push_back(SUB("Waste free Wednesday! And you won! Collect $50", 11, 0, 50, -1, 0, 0));
	subDeck.push_back(SUB("Got bitten trying to feed a squirrel! $40 for a vaccination", 12, 0, -40, -1, 0, 0));
	subDeck.push_back(SUB("Assisting a prospective student, go to Main Building", 13, 0, 0, 37, 0, 0));

	for(i = subDeck.size() -1; i > -1; i--)
	{
		j = rand() % (i+1);
		if(i != j)
		{
			swap(subDeck[j], subDeck[i]);
		}
	}	

}

void Board::buildSAO()
{
	int i;
	int j;
//	srand(time(NULL));

	saoDeck.push_back(SAO("Attended Bengal Bouts. Donated $20", 0, 0, -20, -1, 0, 0, 0, 0));
	saoDeck.push_back(SAO("Attended Baraka Bouts. Donated $20", 1, 0, -20, -1, 0, 0, 0, 0));
	saoDeck.push_back(SAO("The basketball team scored 88 points! You collect $30!", 2, 0, 30, -1, 0, 0, 0, 0));
	saoDeck.push_back(SAO("Got lunch with your dome date", 3, 0, 0, -1, 0, 0, 0, 1));
	saoDeck.push_back(SAO("Football season! Get to the stadium!", 4, 0, 0, 34, 0, 0, 0, 0));
	saoDeck.push_back(SAO("Rector's got your back! Get out of Res Life early next time", 5, 1, 0, -1, 0, 0, 0, 0));
	saoDeck.push_back(SAO("Bed bugs! Your room has to be fumigated! Move to next study location", 6, 0, 0, -1, 0, 0, 1, 0));
	saoDeck.push_back(SAO("Headed off campus! You picked up the cab fare, spent $30", 7, 0, -30, -1, 0, 0, 0, 0));
	saoDeck.push_back(SAO("Dinner at Eddy Street! You spent $25", 8, 0, -25, -1, 0, 0, 0, 0));
	saoDeck.push_back(SAO("Pay day! Proceed to GO", 9, 0, 0, 0, 0, 0, 0, 0));
	saoDeck.push_back(SAO("Purchased football season tickets. Cost $220", 10, 0, -220, -1, 0, 0, 0, 0));
	saoDeck.push_back(SAO("Paid club dues. Lost $40", 11, 0, -40, -1, 0, 0, 0, 0));
	saoDeck.push_back(SAO("Won trivia night at Legends! $300 prize!", 12, 0, 300, -1, 0, 0, 0, 0));

	for(i = subDeck.size() - 1; i > -1; i--)
	{
		j = rand() % (i+1);
		if(i != j)
		{
			swap(saoDeck[j], saoDeck[i]);
		}
	}

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
		//		if(makeChange != 0)
		//		{
					for(int m = 0; m < 40; m++)
					{
						if(spaces[m]->getGroup() == j)
						{
							spaces[m]->setGroupOwned(makeChange);
						}
					}
		//		}
			}
		}
	}
	for(int i = 0; i < 40; i++)
	{
		for(int j = 1; j < 9; j++)
		{
			if(spaces[i]->getGroup() == j)
			{
				if(spaces[i]->getGroupOwned() == 0)
				{
					spaces[i]->implosion();
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


void Board::checkDecks()
{
	if(saoDeck.size() == 0)
	{
		buildSAO();
	}
	if(subDeck.size() == 0)
	{
		buildSUB();
	}
}
	
int Board::accessMoney(int choice)
{
	if(choice == 1)	return subDeck[0].getEffect();
	if(choice == 2) return saoDeck[0].getEffect();
}

bool Board::accessGOOJ(int choice)
{
	if(choice == 1) return subDeck[0].getGOOJ();
	if(choice == 2) return saoDeck[0].getGOOJ();
}

int Board::accessMove(int choice)
{
	if(choice == 1) return subDeck[0].getMove();
	if(choice == 2) return saoDeck[0].getMove();
}

void Board::printDescription(int choice)
{
	string temp;
	if(choice == 1) 
	{
		temp = subDeck[0].getDescription();
		cout << temp << endl;
	}
	if(choice == 2)
	{
		temp = saoDeck[0].getDescription();
		cout << temp << endl;
	}
}

int Board::getCardNum(int choice)
{
	if (choice == 1)
	{
		return subDeck[0].getCardNum();
	}
	if (choice == 2){
		return saoDeck[0].getCardNum();
	}
}

int Board::accessPos(int choice)
{
	if(choice == 1) return subDeck[0].getPos();
	if(choice == 2) return saoDeck[0].getPos();
}


bool Board::accessGTJ(int choice)
{
	if(choice == 1) return subDeck[0].getGTJ();
	if(choice == 2) return saoDeck[0].getGTJ();
}

bool Board::accessRR(int choice)
{
	if(choice == 2) return saoDeck[0].getRR();
	else return 0;
}

bool Board::accessDH(int choice)
{
	if(choice == 2) return saoDeck[0].getDH();
	else return 0;
}
	
void Board::alterDeck(int choice)
{
	if(choice == 1) subDeck.pop_front();
	if(choice == 2) saoDeck.pop_front();
}
