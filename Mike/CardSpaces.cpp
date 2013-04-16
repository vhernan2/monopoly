#include "CardSpaces.h"
using namespace std;

CardSpaces::CardSpaces()
{
	Tile();
}

CardSpaces::CardSpaces(int indicate, string word, int player, int amount, int effect, bool value) : Tile(indicate, word, player, amount, effect, value)
{
}

int CardSpaces::interact(Player* current)
{
//	cout << current->getName() << ", you landed on an " << title << ". You get a card" << endl;
	return owner;
}	

void CardSpaces::manDeck(Player* current, Board* board)
{
	int startPos;
	int endPos;
	int distance;

	cout << current->getName() << ", you landed on a " << title << " Here is your card: " << endl;
	cout << title << endl;
	board->printDescription(takeCard);

	current->changeInMoney(board->accessMoney(takeCard));
	current->advance(board->accessMove(takeCard));
	if(board->accessPos(takeCard) != -1)
	{
		current->setPosition(board->accessPos(takeCard));
	}
	if(board->accessGOOJ(takeCard) != 0)
	{
		current->changeGOOJ(1);
	}
	if(board->accessGTJ(takeCard) != 0)
	{
		current->goToJail();
	}
	if(board->accessRR(takeCard) != 0)
	{
		startPos = current->getPosition();
		endPos = startPos;
		for(endPos; board->accessSpace(endPos)->getGroup() != 9; endPos++)
		{
			if(endPos == 39) endPos = -1;
		}
		distance = endPos - startPos;
		if(distance > 0)
		{
			current->advance(distance);
		}
		else if(distance < 0)
		{
			distance = (40 + distance);
			current->advance(distance);
		}
	}
	if(board->accessDH(takeCard) != 0)
	{
		startPos = current->getPosition();
		endPos = startPos;
		for(endPos; board->accessSpace(endPos)->getGroup() != 10; endPos++)
		{
			if(endPos == 39) endPos = -1;
		}
		distance = endPos - startPos;
		if(distance > 0)
		{
			current->advance(distance);
		}
		else if(distance < 0)
		{
			distance = (40 + distance);
			current->advance(distance);
		}
	}


	board->alterDeck(takeCard);

	return;

}
