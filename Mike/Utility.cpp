#include "Utility.h"
using namespace std;

Utility::Utility() : Tile()
{
	cost = 150;
	rent = 10;
}

Utility::Utility(int indicate, string words, int player, int amount, int take, bool value, int money, int number, int owned, bool status) : Tile(indicate, words, player, amount, take, value)
{
	cost = money;
	rent = number;
	numOwned = owned;
	mortgaged = status;
}

int Utility::buy(Player* current) {
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
			setGroupOwned(1);
                        return owner;

                }
        } else {
                cout << "This tile is owned already" << endl;
        }
        return owner;
}


int Utility::interact(Player* current)
{
	char response;
	cout << current->getName() << ", you landed on " << title << ". ";
	if(owner == -1)
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
	if(numOwned == 0){
		moneyEffect = roll * 0;
	}
	else if(numOwned == 1)
	{
		moneyEffect = roll * 4;
	}
	else if(numOwned == 2)
	{
		moneyEffect = roll * 10;
	}
	else 
	{
		moneyEffect = roll * 10;
	}

}

void Utility::setGroupOwned(int update)
{
	numOwned += update;
}

int Utility::getCost()
{
	return cost;
}

void Utility::setMortgage(bool status)
{
	mortgaged = status;
}

bool Utility::getMortgage()
{
	return mortgaged;
}
