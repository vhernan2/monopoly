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
	if(title == "Res Life")
	{
		if(current->getJail() == 1)
		{
			cout << "You are stuck at Res Life! Pay $50 to leave? (y/n)";
			response = sdl.getResponse();
			if(response == 'y')
			{
				cout << "You're free to go!" << endl;
				current->changeInMoney(-50);
			}
		}
		else
		{
			cout << "You landed on Res Life! Just passing through..." << endl;
		}
	}
	return owner;
}
