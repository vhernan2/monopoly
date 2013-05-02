#include "Jail.h"
using namespace std;

Jail::Jail() : Tile()
{
	sdl;
}

Jail::Jail(int indicate, string words, int player, int amount, int take, bool value) : Tile(indicate, words, player, amount, take, value)
{
}

int Jail::interact(Player* current)
{
	char response;
	if(title == "Go to Res Life")
	{
		cout << current->getName() << ", you landed on " << title << ", you are stuck at Res Life!" << endl; 
		current->goToJail();
	}
	return owner;
}
