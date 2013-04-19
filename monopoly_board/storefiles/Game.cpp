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
		players.push_back(Player(j));
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

	curPlayer=0;
	gameBoard;

}

Game::~Game()
{
}

void Game::rollDie(Player* current)
{
	int firstRoll;
	int secondRoll;
	int move;
	
	srand(time(NULL));
	firstRoll = rand()%6 + 1;
	secondRoll = rand()%6 + 1;

	move = firstRoll + secondRoll;

	cout << current->getName() << ", you rolled a " << move << endl;

	current->advance(move);
}

void Game::turn()
{
	//while(1)
	//{
	//	for(int i = 0; i < numPlayers; i++)
	//	{
	//		playerTurn(&players[i]);
	//		cout << endl << endl;
	//	}
	//}

		curPlayer = curPlayer++;
		if (curPlayer >= numPlayers) curPlayer = 0;
		playerTurn(&players[curPlayer]);
		cout << endl << endl;

}

void Game::playerTurn(Player* current)
{
	char response;
	int output;	//stores index value from interact function


	gameBoard.checkGroupsProp();		//checks the properties to see if an entire group is owned by a player
	gameBoard.updateRentRR();		//updates the rent of the railroads based on how many a player owns
	gameBoard.updateEffects();		//rolls through entire board and updates effects of properties
	buildCheck(current);			//updates the deque of property titles player can build a house on



	cout << current->getName() << " it is your turn" << endl;
	cout << "Your current money is: $" << current->getMoney() << endl;
	current->printTiles();

	cout << "What would you like to do? (R)oll, (B)uild";
	cin >> response;
	switch(response)
	{
		case 'r':
			rollDie(current);
			output = gameBoard.accessSpace(current->getPosition())->interact(current);	//this vomit is supposed to print out the information from the tile
			if(output != -1)
			{
				gameBoard.accessSpace(current->getPosition())->payBack(&players[output]);	//this vomit awards a player money if someone lands on their property
			}
			break;

		case 'b':
			build(current);
			rollDie(current);
			output = gameBoard.accessSpace(current->getPosition())->interact(current);	//this vomit is supposed to print out the information from the tile
			if(output != -1)
			{
				gameBoard.accessSpace(current->getPosition())->payBack(&players[output]);	//this vomit awards a player money if someone lands on their property
			}
			break;
	}

}

void Game::buildCheck(Player* current)
{
	deque<string> props;
	props = current->getTiles();
	current->clearDeques();
	
	for(int i = 0; i < props.size(); i++)
	{
		for(int j = 0; j < 40; j++)
		{
			if(props[i] == gameBoard.accessSpace(j)->getTitle())
			{
				if(gameBoard.accessSpace(j)->getGroup() > 0 && gameBoard.accessSpace(j)->getGroup() <= 8)
				{
					if(gameBoard.accessSpace(j)->getGroupOwned() == 1)
					{
						if(gameBoard.accessSpace(j)->getHouses() < 4 && gameBoard.accessSpace(j)->getHotels() == 0)
						{
							current->addHouseTiles(props[i]);
						}
						if(gameBoard.accessSpace(j)->getHouses() == 4)
						{
							current->addHotelTiles(props[i]);
						}
					}
				}
			}
		}
	}
}	

void Game::build(Player* current)
{

	int select;		//player selects building choice
	int loop = 1;		//controls while loop
	int houseLoop = 1;	//controls house building loop
	int hotelLoop = 1;
	int housesAdded;
	int hotelsAdded;
	string location;	//where the user wants to build

	deque<string> houseOptions;
	deque<string> hotelOptions;

	while(loop)
	{
		houseOptions = current->getHouseTiles();
		hotelOptions = current->getHotelTiles();
		houseLoop = 1;
		hotelLoop = 1;
	
		cout << "What would you like to build? 1 for houses ($50 each), 2 for hotels ($100 each), 3 to exit";
		cin >> select;
		if(select == 1)
		{
			if(houseOptions.empty() != 1)
			{
				while(houseLoop)
				{	
					cout << "Where would you like to build a house? ";
					for(int i = 0; i < houseOptions.size(); i++)
					{
						cout << houseOptions[i] << ", ";
					}
					cout << endl;
					getline(cin, location);

					for(int i = 0; i < houseOptions.size(); i++)
					{
						if(location == houseOptions[i])
						{
							for(int j = 0; j < 40; j++)
							{
								if(location == gameBoard.accessSpace(j)->getTitle())
								{
									cout << "There are " << gameBoard.accessSpace(j)->getHouses() << " houses here. How many would you like to add? (Max 4)";
									cin >> housesAdded;
									gameBoard.accessSpace(j)->addHouses(housesAdded);
									current->changeInMoney((-50) * housesAdded);
									houseLoop = 0;
								}
							}
						}
					}
					if(houseLoop != 0)
					{
						cout << "That is not somewhere you can build a house" << endl;
					}
				}
			}
			else
			{
				cout << "You can't build houses anywhere" << endl;
			}	
		}
		if(select == 2)
		{
			if(hotelOptions.empty() != 1)
			{
				while(hotelLoop)
				{	
					cout << "Where would you like to build a hotel? ";
					for(int i = 0; i < hotelOptions.size(); i++)
					{
						cout << hotelOptions[i] << ", ";
					}
					cout << endl;
					getline(cin, location);

					for(int i = 0; i < hotelOptions.size(); i++)
					{
						if(location == hotelOptions[i])
						{
							for(int j = 0; j < 40; j++)
							{
								if(location == gameBoard.accessSpace(j)->getTitle())
								{
									cout << "There are " << gameBoard.accessSpace(j)->getHotels() << " hotels here. How many would you like to add? (Max 1)";
									cin >> hotelsAdded;
									gameBoard.accessSpace(j)->addHotels(hotelsAdded);
									gameBoard.accessSpace(j)->addHouses(-4);
									current->changeInMoney(-100);
									hotelLoop = 0;
								}
							}
						}
					}
					if(hotelLoop != 0)
					{
						cout << "That is not somewhere you can build a hotel" << endl;
					}
				}
			}
			else
			{
				cout << "You can't build hotels anywhere" << endl;
			}	
		}
		if(select == 3)
		{
			return;
		}
	}
}

int Game::getPlayers(){
	return numPlayers;
}

int Game::getCurrentPlayer(){
	return curPlayer;
}

int Game::getPlayerLocation(int player){
	return ((&players[curPlayer])->getPosition());
}
