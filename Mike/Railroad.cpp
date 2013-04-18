#include "Railroad.h"
using namespace std;

Railroad::Railroad(int indicate, string title, int player, int money, int take, bool value, int amount, int number) : Tile(indicate, title, player, money, take, value)
{
	cost = amount;
	rent = number;
}

int Railroad::interact(Player* current)
{
	char response;
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

		cout << "No one owns this location. Would you like to buy for $200? (y/n)";
		cin >> response;
		if(response == 'y')
		{
			current->changeInMoney(-cost);
			cout << "You bought " << title << " for $" << cost << endl;
			cout << "You now have $" << current->getMoney() << endl;
			owner = current->getIndex();
			current->addTile(title);			
			return owner;
		}

		}
	}
	else if(getOwner() != current->getIndex())
	{
		cout << "This location is owned. You lose $" << moneyEffect << endl;
		current->changeInMoney(-moneyEffect);
		cout << "You now have $" << current->getMoney() << endl;
		update = 1;
		return owner;
	}
	else if(getOwner() == current->getIndex())
	{
		cout << "You own this tile" << endl;
	}
	
}

void Railroad::payBack(Player* current)
{
	if(update == 1)
	{
		current->changeInMoney(moneyEffect);
		cout << current->getName() << " gains $" << moneyEffect << endl;
		cout << current->getName() << " now has $" << current->getMoney();
	}
	update = 0;
}

void Railroad::updateEffect(int count)
{
	moneyEffect = (rent*count);
}
