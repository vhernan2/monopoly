#ifndef PROPERTY_H
#define PROPERTY_H
#include <iostream>
#include <string>
#include "Tile.h"
using namespace std;

class Property : public Tile
{
	public:
		Property(string, int, int, int, int, int, int);
		void addHouses(int);	//should these functions be in Player? Or be called from Player using a buyHouse and buyHotel function?
		void addHotels(int);

	private:
		int cost;
		int numHotels;
		int numHouses;

};
#endif
