#include "Utility.h"
using namespace std;

Utility::Utility() : Tile()
{
	cost = 150;
	rent = 10;
}

Utility::Utility(int indicate, string words, int player, int amount, int take, bool value, int money, int number, int owned) : Tile(indicate, words, player, amount, take, value)
{
	cost = money;
	rent = number;
	numOwned = owned;
}

int Utility::interact(Player* current)
{
	char response;
	cout << current->getName() << ", you landed on " << title << ". ";
	if(owner == -1)
	{
		if(current->getMoney() <= cost)
		{
			cout << "This tile is unowned, but you can't afford it!" << endl;
			return owner;
		}
		else
		{

		cout << "No one owns this location. Would you like to buy for " << cost << "? (y/n)";
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
		
void Utility::payBack(Player* current)
{
	if(update == 1)
	{
		current->changeInMoney(moneyEffect);
		cout << current->getName() << " gains $" << moneyEffect << endl;
		cout << current->getName() << " now has $" << current->getMoney() << endl;
	}
	update = 0;
}

void Utility::updateEffect(int roll)
{
	if(numOwned == 1)
	{
		moneyEffect = roll * 4;
	}
	if(numOwned = 2)
	{
		moneyEffect = roll * 10;
	}
}

void Utility::setGroupOwned(int update)
{
	numOwned = update;
}
