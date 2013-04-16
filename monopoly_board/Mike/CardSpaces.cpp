#include "CardSpaces.h"
using namespace std;

CardSpaces::CardSpaces()
{
	Tile();
}

CardSpaces::CardSpaces(int indicate, string word, int player, int amount, int effect, bool value) : Tile(indicate, word, player, amount, effect, value)
{
}

int CardSpaces::interact(Player* current)
{
	cout << current->getName() << ", you landed on an " << title << ". You get a card" << endl;
	return owner;
}	
