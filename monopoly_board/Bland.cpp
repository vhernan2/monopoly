#include "Bland.h"
using namespace std;

Bland::Bland() : Tile()
{
}

Bland::Bland(int indicate, string words, int player, int amount, int take, int value) : Tile(indicate, words, player, amount, take, value)
{
}

int Bland::interact(Player* current)
{
	cout << current->getName() << ", you landed on " << title << ". ";
	if(title == "GO")
	{
		cout << "Once you pass, you will collect $200!" << endl;
	}
	else if(title == "D6 Parking")
	{
		cout << "Free Parking!" << endl;
	}
	return owner;
}
