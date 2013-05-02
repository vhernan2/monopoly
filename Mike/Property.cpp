#include "Property.h"
#include "Game.h"
#include <iostream>

#include "SDL_logic.h"

using namespace std;

Property::Property(int indicate, string title, int player, int money, int take, bool refresh, int amount, int houses, int hotels, int value, int one, int two, int three, int four, int hotel, bool group, bool status) : Tile(indicate, title, player, money, take, refresh)
{
	cost = amount;
	numHouses = houses;
	numHotels = hotels;
	rent = value;
	H1 = one;
	H2 = two;
	H3 = three;
	H4 = four;
	HOTEL = hotel;
	groupOwned = group;
	mortgaged = status;
}

void Property::addHotels(int num)
{
	numHotels += num;		//number of hotels increased
}

void Property::addHouses(int num)
{
	numHouses += num;		//number of houses increased
}	

void Property::implosion()
{
	numHouses = 0;
	numHotels = 0;
}

void Property::setGroupOwned(bool value)
{
	groupOwned = value;
}

bool Property::getGroupOwned()
{
	return groupOwned;
}

int Property::buy(Player* current) {
	char response;
	if(getOwner() == -1)
	{
		if(current->getMoney() <= cost)
		{
			cout << "This tile is unowned, but you can't afford it!" << endl;
			return owner;
		}
		else
		{

			cout << "You bought " << title << " for $" << cost << "!" << endl;
			current->changeInMoney(-cost);
			cout << "Your total money is now: $" << current->getMoney() << endl;
			owner = current->getIndex();
			current->addTile(title);
			return owner;

		}
	} else {
		cout << "This tile is owned already" << endl;
	}
	return owner;
}

int Property::interact(Player* current)
{
	char response;
	int toBeStored;	//integer value associated with player
	cout << current->getName() << ", you landed on " << title << endl;

	if (getOwner() == -1){
		cout << "This tile is unowned, and can be bought for $" << cost << endl;
		return owner;
	}
	else if(getOwner() != current->getIndex() && mortgaged == 0)
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
		return owner;
	}
	else if(getOwner() != current->getIndex() && mortgaged == 1)
	{
		cout << "This tile is owned, but it is mortgaged! You lose no money!" << endl;
		return owner;
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
		switch(numHouses)
		{
			case 0: 
				if(numHotels == 0)
				{
					moneyEffect = (rent*2);
				}
				else if(numHotels == 1)
				{
					moneyEffect = HOTEL;
				}
				break;
			case 1:
				moneyEffect = H1;
				break;
			case 2:
				moneyEffect = H2;
				break;
			case 3:
				moneyEffect = H3;
				break;
			case 4:
				moneyEffect = H4;
				break;
			default:
				moneyEffect = rent;
				break;
		}
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

int Property::getCost()
{
	return cost;
}

void Property::setMortgage(bool status)
{
	mortgaged = status;
}

bool Property::getMortgage()
{
	return mortgaged;
}
