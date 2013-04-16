#include "Tile.h"
#include <iostream>
#include "Player.h"
using namespace std;

Tile::Tile()
{
	group = 0;
	title = "";
	owner = -1;
	moneyEffect = 0;
	takeCard = 0;
	update = 0;
}

Tile::Tile(int indicate, string text, int ownedBy, int money, int take, bool value)
{
	group = indicate;
	title = text;
	owner = ownedBy;
	moneyEffect = money;
	takeCard = take;
	update = value;
}

Tile::~Tile()
{
}

int Tile::getGroup()
{
	return group;
}

string Tile::getTitle()
{
	return title;
}

void Tile::setOwner(int player)
{
	owner = player;
}

int Tile::getOwner()
{
	return owner;
}

int Tile::interact(Player* current)
{
	cout << "IN HERE" << endl;
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

void Tile::payBack(Player* current)
{
}

void Tile::updateEffect(int count)
{
}

void Tile::setGroupOwned(bool value)
{
}

bool Tile::getGroupOwned()
{
}

int Tile::getHouses()
{
}

int Tile::getHotels()
{
}

void Tile::addHouses(int num)
{
}

void Tile::addHotels(int num)
{
}
