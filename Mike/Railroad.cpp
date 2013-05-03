#include "Railroad.h"
using namespace std;

Railroad::Railroad(int indicate, string title, int player, int money, int take, bool value, int amount, int number, bool status) : Tile(indicate, title, player, money, take, value)
{
	cost = amount;
	rent = number;
	mortgaged = status;
}

int Railroad::buy(Player* current) {
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


int Railroad::interact(Player* current)
{
	char response;
	cout << current->getName() << ", you landed on " << title << endl;
	if(getOwner() == -1)
	{
		cout << "This tile is unowned, and can be bought for $" << cost << endl;
                return -1;
	}
	else if(getOwner() != current->getIndex() && mortgaged == 0)
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
		return -1;
	}
	else if(getOwner() != current->getIndex() && mortgaged == 1)
	{
		cout << "This location is owned, but it is mortgaged! You don't lose any money!" << endl;
		return -1;
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
	if (count == 1) moneyEffect = rent * 1;
        else if (count == 2) moneyEffect = rent * 2;
        else if (count == 3) moneyEffect = rent * 4;
        else if (count == 4) moneyEffect = rent * 8;
	else moneyEffect = rent * 8;
}

int Railroad::getCost()
{
	return cost;
}

void Railroad::setMortgage(bool status)
{
	mortgaged = status;
}

bool Railroad::getMortgage()
{
	return mortgaged;
}
