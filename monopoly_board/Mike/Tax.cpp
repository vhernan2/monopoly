#include "Tax.h"
using namespace std;

Tax::Tax() : Tile()
{
}

Tax::Tax(int indicate, string words, int player, int amount, int take, bool value) : Tile(indicate, words, player, amount, take, value)
{
}

int Tax::interact(Player* current)
{
	cout << current->getName() << ", you landed on " << title << ". You lose $75!" << endl;
	current->changeInMoney(moneyEffect);
	cout << "You now have $" << current->getMoney() << endl;
	return owner;
}
