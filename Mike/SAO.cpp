#include "SAO.h"
using namespace std;

SAO::SAO()
{
}

SAO::SAO(string entry, bool jail, int cash, int relocate, int advance, bool trouble, bool study, bool dining)
{
	description = entry;
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
