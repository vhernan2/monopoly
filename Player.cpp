#include "Player.h"
using namespace std;

Player::Player()
{
	totalMoney = 1000;
	inJail = 0;
	int xLoc = 0;
	int yLoc = 0;
	int ZLoc = 0;
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
	//still a little unclear how movement will be implemented, will involve a cdl list of board locations player can be
	//in and moving around in that structure
}
