#include "Property.h"
#include <iostream>
using namespace std;

Property::Property(string title, int player, int money, int take, int amount, int houses, int hotels) : Tile(title, player, money, take)
{
	cost = amount;
	numHouses = houses;
	numHotels = hotels;
}

void Property::addHotels(int num)
{
	numHotels += num;		//number of hotels increased
	moneyEffect = (cost*numHotels*2);	//money effect of property is updated with purchase
}

void Property::addHouses(int num)
{
	numHouses += num;		//number of houses increased
	moneyEffect = (cost*numHouses);		//money effect of property is updated with purchase
}	
