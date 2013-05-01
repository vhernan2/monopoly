#ifndef PROPERTY_H
#define PROPERTY_H
#include <iostream>
#include <string>
#include "Tile.h"
#include "Player.h"
#include "Game.h"
#include "SDL_logic.h"
using namespace std;

class Property : public Tile
{
	public:
		Property(int, string, int, int, int, bool, int, int, int, int, int, int, int, int, int, bool, bool);

		virtual void addHouses(int);	//should these functions be in Player? Or be called from Player using a buyHouse and buyHotel function?
		virtual void addHotels(int);	//ignore the above comment. This is good, and I prefer typing to deleting
		virtual void setGroupOwned(bool); 	//function will modify groupOwned private data member
		virtual bool getGroupOwned();		//function gets groupOwned bool
	
		int buy(Player*);
		virtual int interact(Player*);
		virtual void payBack(Player*);
		virtual void updateEffect(int);

		virtual int getHouses();
		virtual int getHotels();

		virtual int getCost();
		virtual void setMortgage(bool);
		virtual bool getMortgage();

	private:
		int cost;
		int numHotels;
		int numHouses;
		int rent;
		int H1;
		int H2;
		int H3;
		int H4;
		int HOTEL;
		bool groupOwned;
		bool mortgaged;
		SDL_logic sdl;

};
#endif
