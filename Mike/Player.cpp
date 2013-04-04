#include "Player.h"
using namespace std;

Player::Player()
{
	totalMoney = 1000;
	inJail = 0;
	int xLoc = 0;
	int yLoc = 0;
	int ZLoc = 0;
	position = 0;
}

Player::~Player()
{
}

int Player::getMoney()
{
	return totalMoney;
}

int Player::getJail()
{
	return inJail;
}

void Player::goToJail()
{
	xLoc = 0;	//this location liable to change based on the jails board location to be determined later
	yLoc = 0;
	zLoc = 0;

	inJail = 1;
}

void Player::setName(string playerName)
{
	name = playerName;
}

string Player::getName()
{
	return name;
}

void Player::setGamePiece(int choice)
{
	piece = choice;
}

void Player::changeInMoney(int amount)
{
	totalMoney += amount;	//any loss of money can be applied as a negative amount
}

void Player::advance(int spaces)
{
	int newPos;
	newPos = position;
	newPos += spaces;
	if(newPos > 35)
	{
		position = newPos - 36;
		changeInMoney(200);
	}
	else 
	{
		if(newPos < 0)
		{
			position = 36 + newPos;
		}
		else position += spaces;
	}
}

int Player::getPosition()
{
	return position;
}
