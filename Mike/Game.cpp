#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <vector>

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

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

	curPlayer=100; //really big to ensure it resets on first call
	gameBoard;

}

Game::~Game()
{
}

int Game::rollDie(Player* current)
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
	return move;
}

void Game::turn(SDL_Event &event)
{
	//while(1)
	//{
	//	for(int i = 0; i < numPlayers; i++)
	//	{
	//		playerTurn(&players[i]);
	//		cout << endl << endl;
	//	}
	//}
//	while(1){
		curPlayer = curPlayer++;
		if (curPlayer >= players.size()) curPlayer = 0;
		playerTurn(&players[curPlayer], event);
		cout << endl << endl;
//	}
}

//add logic to know which responses are valid??
char Game::getResponse(SDL_Event &event){

        bool quit = false;
        char c;

        while (quit == false) {
                while( SDL_PollEvent( &event ) ){
                        if (event.type == SDL_KEYDOWN){
                                cout << "Key down" << endl;
                                switch (event.key.keysym.sym){
                                case SDLK_b:
                                        c = 'b';
                                        quit = true;
                                        break;
                                case SDLK_n:
                                        c = 'n';
                                        quit = true;
                                        break;
                                case SDLK_r:
                                        c = 'r';
                                        quit = true;
                                        break;
                                case SDLK_t:
                                        c= 't';
                                        quit = true;
                                        break;
                                case SDLK_v:
                                        c='v';
                                        quit = true;
                                        break;
                                case SDLK_y:
                                        c='y';
                                        quit = true;
                                        break;
                                }
                        }
                }
        }
        return c;

}

void Game::playerTurn(Player* current, SDL_Event &event)
{
	char response;
	char pay;
	int output;	//stores index value from interact function
	int playerRoll;		//stores value of player's roll

	gameBoard.checkDecks();			//checks SAO and SUB decks to make sure they aren't empty. If so rebuilds the deck
	gameBoard.checkGroupsProp();		//checks the properties to see if an entire group is owned by a player
	gameBoard.updateRentRR();		//updates the rent of the railroads based on how many a player owns
	gameBoard.updateEffects(0);		//rolls through entire board and updates effects of properties
	buildCheck(current);			//updates the deque of property titles player can build a house on


	if(current->getJail() == 1)
	{
			current->addTimeJail();
			if(current->getTimeJail() != 0)
			{
				cout << current->getName() << ", you are stuck at res life!" << endl;
				if(current->getMoney() > 50)
				{
					cout << "Would you like to pay off the service hours? (y/n)";
					cin >> pay;
					if(pay == 'y')
					{
						current->payOffResLife();
					}
					else
					{
						cout << "You lose a turn!" << endl;
						return;
					}
				}
				else
				{
					cout << "You lose a turn!" << endl;
					return;
				}
			}
			else if(current->getTimeJail() == 0)
			{
				cout << current->getName() << ", you're out of res life!" << endl;
				current->addTimeJail();
			}
	}

	cout << current->getName() << " it is your turn" << endl;
	cout << "Your current money is: $" << current->getMoney() << endl;
	current->printTiles();

	cout << "What would you like to do? (R)oll, (B)uild, (T)rade: \n";	//all 3 options presented, although trade currently does not function properly

	response = getResponse(event);

	switch(response)
	{
		case 'r':
			playerRoll = rollDie(current);
			gameBoard.updateEffects(playerRoll);
			if(gameBoard.accessSpace(current->getPosition())->getTitle() == "S.U.B." || gameBoard.accessSpace(current->getPosition())->getTitle() == "S.A.O.")
			{
				gameBoard.accessSpace(current->getPosition())->manDeck(current, &gameBoard);
			}
				output = gameBoard.accessSpace(current->getPosition())->interact(current);	//this vomit is supposed to print out the information from the tile
				if(output != -1)
				{
					gameBoard.accessSpace(current->getPosition())->payBack(&players[output]);	//this vomit awards a player money if someone lands on their property
				}
			gameOver();
			break;

		case 'b':
			build(current);
			playerRoll = rollDie(current);
			gameBoard.updateEffects(playerRoll);
			if(gameBoard.accessSpace(current->getPosition())->getTitle() == "S.U.B." || gameBoard.accessSpace(current->getPosition())->getTitle() == "S.A.O.")
			{
				gameBoard.accessSpace(current->getPosition())->manDeck(current, &gameBoard);
			}
				output = gameBoard.accessSpace(current->getPosition())->interact(current);	//this vomit is supposed to print out the information from the tile
				if(output != -1)
				{
					gameBoard.accessSpace(current->getPosition())->payBack(&players[output]);	//this vomit awards a player money if someone lands on their property
				}
			gameOver();
			break;

		case 't':
			trade(current);
			playerRoll = rollDie(current);
			gameBoard.updateEffects(playerRoll);
			if(gameBoard.accessSpace(current->getPosition())->getTitle() == "S.U.B." || gameBoard.accessSpace(current->getPosition())->getTitle() == "S.A.O.")
			{
				gameBoard.accessSpace(current->getPosition())->manDeck(current, &gameBoard);
			}
				output = gameBoard.accessSpace(current->getPosition())->interact(current);	//this vomit is supposed to print out the information from the tile
				if(output != -1)
				{
					gameBoard.accessSpace(current->getPosition())->payBack(&players[output]);	//this vomit awards a player money if someone lands on their property
				}
			gameOver();
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

void Game::build(Player* current)		//pretty sure getline is causing a weird print error in this function somewhere as well
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
									if(current->getMoney() <= 50*housesAdded)
									{
										cout << "You can't afford that many houses!" << endl;
										houseLoop = 0;
										break;
									}
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
									if(current->getMoney() <= 100*hotelsAdded)
									{
										cout << "You can't afford to buy a hotel!" << endl;
										hotelLoop = 0;
										break;
									}
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

void Game::trade(Player* current)		//this function was thrown together somewhat carelessly, I'm having problems with getline
{
	string recipient;
	int recipIndex;
	string offer;
	string request;
	char answer;

	cout << current->getName() << " here is what everyone owns: " << endl;
	
	for(int i = 0; i < players.size()-1; i++)
	{
		cout << players[i].getName() << ": ";
		players[i].printTiles();
		cout << endl;
	}

	cout << "Who would you like to trade with? (Name please) ";
	cin >> recipient;

	for(int i = 0; i < players.size()-1; i++)
	{
		if(players[i].getName() == recipient) 
		recipIndex = players[i].getIndex();
		break;
	}

	cout << "What would you like to offer? ";
	getline(cin, offer);

	cout << "And what would you like in return? ";
	getline(cin, request);

	cout << recipient << ", do you accept this trade? " << offer << " for " << request << "? (y/n)";
	cin >> answer;

	if(answer == 'n') return;
	else if(answer == 'y')
	{
		for(int i = 0; i < 40; i++)
		{
			if(gameBoard.accessSpace(i)->getTitle() == request)
			{
				gameBoard.accessSpace(i)->setOwner(current->getIndex());
			}
			if(gameBoard.accessSpace(i)->getTitle() == offer)
			{
				gameBoard.accessSpace(i)->setOwner(recipIndex);
			}
		}
	}
}

void Game::gameOver()
{
	for(int i = 0; i < players.size(); i++)
	{
		if(players[i].getMoney() <= 0)
		{
			cout << players[i].getName() << ", you have run out of money! You are eliminated from the game! Thanks for playing!" << endl;
			players.erase(players.begin()+5);
		}
	}
}
