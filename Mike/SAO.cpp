#include "SAO.h"
using namespace std;

SAO::SAO()
{
}

SAO::SAO(string entry, int c, bool jail, int cash, int relocate, int advance, bool trouble, bool study, bool dining)
{
	description = entry;
	cardNum = c;
	GOOJ = jail;
	moneyEffect = cash;
	newLocation = relocate;
	move = advance;
	GTJ = trouble;
	RR = study;
	DH = dining;
}

string SAO::getDescription()
{
	return description;
}

int SAO::getCardNum()
{
	return cardNum;
}

bool SAO::getGOOJ()
{
	return GOOJ;
}

int SAO::getEffect()
{
	return moneyEffect;
}

int SAO::getMove()
{
	return move;
}

int SAO::getPos()
{
	return newLocation;
}

bool SAO::getGTJ()
{
	return GTJ;
}

bool SAO::getRR()
{
	return RR;
}

bool SAO::getDH()
{
	return DH;
}
