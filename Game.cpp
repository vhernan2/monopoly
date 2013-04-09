#include "Game.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Game::Game()
{
	cout << "Welcome to Monopoly! How many players do you have? (1-4) ";
	cin >> numPlayers;

	for(int j = 0; j < numPlayers; j++)
	{
		players.push_back(Player());
	}

	int i = 0;
	string temp;

	while(i < numPlayers)
	{
		cout << "Player " << (i+1) << " what is your name? ";
		cin >> temp;
	
		players[i].setName(temp);

		i++;
	}

	gameBoard;

}

Game::~Game()
{
}

int Game::rollDie(Player current)
{
	int firstRoll;
	int secondRoll;
	int move;
	
	srand(time(NULL));
	firstRoll = rand()%6 + 1;
	secondRoll = rand()%6 + 1;

	move = firstRoll + secondRoll;

	cout << current.getName() << ", you rolled a " << move << endl;

	current.advance(move);

	return move;
}

void Game::turn()
{
	for(int i = 0; i < numPlayers; i++)
	{
		playerTurn(players[i]);
	}
}

void Game::playerTurn(Player current)
{
	rollDie(current);		
}
