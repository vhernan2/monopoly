#include "Property.h"
#include "Game.h"
#include <iostream>

#include "SDL_logic.h"

using namespace std;

Property::Property(int indicate, string title, int player, int money, int take, bool refresh, int amount, int houses, int hotels, int value, bool group) : Tile(indicate, title, player, money, take, refresh)
{
	cost = amount;
	numHouses = houses;
	numHotels = hotels;
	rent = value;
	groupOwned = group;
}

void Property::addHotels(int num)
{
	numHotels += num;		//number of hotels increased
}

void Property::addHouses(int num)
{
	numHouses += num;		//number of houses increased
}	

void Property::setGroupOwned(bool value)
{
	groupOwned = value;
}

bool Property::getGroupOwned()
{
	return groupOwned;
}

int Property::interact(Player* current)
{
	char response;
	int toBeStored;	//integer value associated with player
	cout << current->getName() << ", you landed on " << title << endl;


	if(getOwner() == -1)
	{
		if(current->getMoney() <= cost)
		{
			cout << "This tile is unowned, but you can't afford it!" << endl;
			return owner;
		}
		else
		{


		cout << "No one owns this tile. Would you like to buy it for $" << cost << "? (y/n)";
		
		response = sdl.getResponse();
		if(response == 'y')
		{
			cout << "You bought " << title << " for $" << cost << "!" << endl;
			current->changeInMoney(-cost);
			cout << "Your total money is now: $" << current->getMoney() << endl;
			owner = current->getIndex();
			current->addTile(title);
			return owner;
		}

		}
	}
	else if(getOwner() != current->getIndex())
	{
		current->changeInMoney(-moneyEffect);
		cout << "This tile is owned. You lose $" << moneyEffect << endl;
		cout << "You now have $" << current->getMoney() << endl;
		update = 1;
		return owner;
	}
	else if(getOwner() == current->getIndex())
	{
		cout << "You own this tile" << endl;
	}
}

void Property::payBack(Player* current)
{
	if(update == 1)
	{
		current->changeInMoney(moneyEffect);
		cout << current->getName() << " gains $" << moneyEffect << endl;
		cout << current->getName() << " now has $" << current->getMoney() << endl;
	}
	update = 0;
}

void Property::updateEffect(int count)
{
	if(groupOwned == 1)
	{
		if(numHouses == 0 && numHotels == 0)
		{
			moneyEffect = (rent*2);
		}
		else
		{
			moneyEffect = rent + (75*numHouses) + (150*numHotels);
		}
	}
	else
	{
		moneyEffect = rent;
	}
}

int Property::getHouses()
{
	return numHouses;
}

int Property::getHotels()
{
	return numHotels;
}
