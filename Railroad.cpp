#include "Railroad.h"
using namespace std;

Railroad::Railroad(string title, int player, int money, int take, int amount) : Tile(title, player, money, take)
{
	cost = amount;
}

void Railroad::interact(Player* current)
{
	cout << current->getName() << ", you landed on " << title << endl;
	if(owner == -1)
	{
		cout << "No one owns this location. Would you like to buy for $200?" << endl;
	}
}
