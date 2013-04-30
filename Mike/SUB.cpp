#include "SUB.h"
using namespace std;

SUB::SUB()
{
}

SUB::SUB(string entry, int card, bool jail, int cash, int relocate, int advance, bool trouble)
{
	description = entry;
	cardNum = card;
	GOOJ = jail;
	moneyEffect = cash;
	newLocation = relocate;
	move = advance;
	GTJ = trouble;
}

string SUB::getDescription()
{
	return description;
}

int SUB::getCardNum()
{
	return cardNum;
}

bool SUB::getGOOJ()
{
	return GOOJ;
}

int SUB::getEffect()
{
	return moneyEffect;
}

int SUB::getMove()
{
	return move;
}

int SUB::getPos()
{
	return newLocation;
}

bool SUB::getGTJ()
{
	return GTJ;
}
