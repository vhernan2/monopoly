#include "Tile.h"
#include <iostream>
#include "Player.h"
using namespace std;

Tile::Tile()
{
	title = "";
	owner = -1;
	moneyEffect = 0;
	takeCard = 0;
}

Tile::Tile(string text, int ownedBy, int money, int take)
{
	title = text;
	owner = ownedBy;
	moneyEffect = money;
	takeCard = take;
}

Tile::~Tile()
{
}

void Tile::setOwner(int player)
{
	owner = player;
}

void Tile::interact(Player* current)
{
	cout << current->getName() << ", you landed on " << title << endl;
	if(title == "GO")
	{
		cout << "You collect $200!" << endl;
	}
	if(title == "D6 Parking")
	{
		cout << "Free parking!" << endl;
	}
} 
