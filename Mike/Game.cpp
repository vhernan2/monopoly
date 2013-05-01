#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include "audio.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <sstream>
using namespace std;

Game::Game(int numPlayers)
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
/*

  initializeText();
  //SDL_Surface *prompt = SDL_SetVideoMode(840,840,32,SDL_SWSURFACE);
  SDL_Surface *sdlText = NULL;
  font = TTF_OpenFont("/usr/share/fonts/sil-padauk/Padauk.ttf",28);
  if (font == NULL)
    cout << "ERROR LOADING FONT!" << endl;
  //SDL_Color textColor = {255,255,255};
  //  SDL_Color bColor = {0,0,0};
  stringstream buffer;
  sdlText= TTF_RenderText_Shaded(font,"Welcome to Monopoly",textColor,bColor);
  sdl.apply_surface(100,100,sdlText,display);
  SDL_Flip(display);

        for(int j = 0; j < numPlayers; j++)
	  {
	  players.push_back(Player(j));
	  }

        string name;
	string append(decipher(display));
        for (int i = 0 ; i < numPlayers ; i++ )
        {
          SDL_FreeSurface(sdlText);
          SDL_FillRect(display,NULL,0x000000);
          SDL_Flip(display);
          buffer << "Player " << (i+1) << " what is your name? ";
          const char* output = buffer.str().c_str();
          sdlText= TTF_RenderText_Shaded(font,output,textColor,bColor);
          sdl.apply_surface(10,10,sdlText,display);
          SDL_Flip(display);

          while (append != "0" ){
	    name = name+append;
	    append = decipher(display);
	  }
	  players[i].setName(name);
	}	
*/
	curPlayer=100; //really big to ensure it resets on first call
	gameBoard;
	sdl;
	screen = NULL;

	preRollImage = sdl.load_files( "JLo/preRoll.png" );
	postRollImage = sdl.load_files( "JLo/postRoll.png" );

	sprites = sdl.load_files("JLo/Properties/SpritsofProperty.png");
	whitespace = sdl.load_files("JLo/Properties/whitespace.png");
		
	houseImage[1] = sdl.load_files("JLo/Rooms/Single.png");
	houseImage[2] = sdl.load_files("JLo/Rooms/Double.png");
	houseImage[3] = sdl.load_files("JLo/Rooms/Triple.png");
	houseImage[4] = sdl.load_files("JLo/Rooms/Quad.png");
	houseImage[5] = sdl.load_files("JLo/Rooms/SixMan.png");

	tile[0] = sdl.load_files("JLo/Properties/GO.png");	
	tile[1] = sdl.load_files("JLo/Properties/PasquerillaEast.png");
	tile[3] = sdl.load_files("JLo/Properties/PasquerillaWest.png");
	tile[4] = sdl.load_files("JLo/Properties/HallTax.png");
	tile[5] = sdl.load_files("JLo/Properties/ColemanMorseCenter.png");
	tile[6] = sdl.load_files("JLo/Properties/SeigfriedHall.png");
	tile[8] = sdl.load_files("JLo/Properties/LewisHall.png");
	tile[9] = sdl.load_files("JLo/Properties/CarrolHall.png");
	tile[10] = sdl.load_files("JLo/Properties/JustVisitingResLife.png");
	tile[11] = sdl.load_files("JLo/Properties/FisherHall.png");
	tile[12] = sdl.load_files("JLo/Properties/NorthDiningHall.png");
	tile[13] = sdl.load_files("JLo/Properties/DillonHall.png");
	tile[14] = sdl.load_files("JLo/Properties/AlumniHall.png");
	tile[15] = sdl.load_files("JLo/Properties/Debartolo.png");
	tile[16] = sdl.load_files("JLo/Properties/BadinHall.png");
	tile[18] = sdl.load_files("JLo/Properties/HowardHall.png");
	tile[19] = sdl.load_files("JLo/Properties/LyonsHall.png");
	tile[20] = sdl.load_files("JLo/Properties/Parking.png");
	tile[21] = sdl.load_files("JLo/Properties/RyanHall.png");
	tile[23] = sdl.load_files("JLo/Properties/McGlinnHall.png");
	tile[24] = sdl.load_files("JLo/Properties/WelshFamily.png");
	tile[25] = sdl.load_files("JLo/Properties/Lafortune.png");
	tile[26] = sdl.load_files("JLo/Properties/ONeillHall.png");
	tile[27] = sdl.load_files("JLo/Properties/KeoughHall.png");
	tile[28] = sdl.load_files("JLo/Properties/SouthDiningHall.png");
	tile[29] = sdl.load_files("JLo/Properties/DuncanHall.png");
	tile[30] = sdl.load_files("JLo/Properties/GoToResLife.png");
	tile[31] = sdl.load_files("JLo/Properties/ComptonIceArena.png");
	tile[32] = sdl.load_files("JLo/Properties/JACC.png");
	tile[34] = sdl.load_files("JLo/Properties/NotreDameStadium.png");
	tile[35] = sdl.load_files("JLo/Properties/Hesburgh.png");
	tile[37] = sdl.load_files("JLo/Properties/MainBuilding.png");
	tile[38] = sdl.load_files("JLo/Properties/LuxuryTax.png");
	tile[39] = sdl.load_files("JLo/Properties/TheGrotto.png");

        backTile[1] = sdl.load_files("JLo/PropertiesBack/PasquerillaEast.png");
        backTile[3] = sdl.load_files("JLo/PropertiesBack/PasquerillaWest.png");
        backTile[5] = sdl.load_files("JLo/PropertiesBack/ColemanMorseCenter.png");
        backTile[6] = sdl.load_files("JLo/PropertiesBack/SeigfriedHall.png");
        backTile[8] = sdl.load_files("JLo/PropertiesBack/LewisHall.png");
        backTile[9] = sdl.load_files("JLo/PropertiesBack/CarrolHall.png");
        backTile[11] = sdl.load_files("JLo/PropertiesBack/FisherHall.png");
        backTile[12] = sdl.load_files("JLo/PropertiesBack/NorthDiningHall.png");
        backTile[13] = sdl.load_files("JLo/PropertiesBack/DillonHall.png");
        backTile[14] = sdl.load_files("JLo/PropertiesBack/AlumniHall.png");
        backTile[15] = sdl.load_files("JLo/PropertiesBack/Debartolo.png");
        backTile[16] = sdl.load_files("JLo/PropertiesBack/BadinHall.png");
        backTile[18] = sdl.load_files("JLo/PropertiesBack/HowardHall.png");
        backTile[19] = sdl.load_files("JLo/PropertiesBack/LyonsHall.png");
        backTile[21] = sdl.load_files("JLo/PropertiesBack/RyanHall.png");
        backTile[23] = sdl.load_files("JLo/PropertiesBack/McGlinnHall.png");
        backTile[24] = sdl.load_files("JLo/PropertiesBack/WelshFamily.png");
        backTile[25] = sdl.load_files("JLo/PropertiesBack/Lafortune.png");
        backTile[26] = sdl.load_files("JLo/PropertiesBack/ONeillHall.png");
        backTile[27] = sdl.load_files("JLo/PropertiesBack/KeoughHall.png");
        backTile[28] = sdl.load_files("JLo/PropertiesBack/SouthDiningHall.png");
        backTile[29] = sdl.load_files("JLo/PropertiesBack/DuncanHall.png");
        backTile[31] = sdl.load_files("JLo/PropertiesBack/ComptonIceArena.png");
        backTile[32] = sdl.load_files("JLo/PropertiesBack/JACC.png");
        backTile[34] = sdl.load_files("JLo/PropertiesBack/NotreDameStadium.png");
        backTile[35] = sdl.load_files("JLo/PropertiesBack/Hesburgh.png");
        backTile[37] = sdl.load_files("JLo/PropertiesBack/MainBuilding.png");
        backTile[39] = sdl.load_files("JLo/PropertiesBack/TheGrotto.png");


	SAOcard[0] = sdl.load_files("JLo/SAO/BengalBouts.png");
	SAOcard[1] = sdl.load_files("JLo/SAO/BarakaBouts.png");
        SAOcard[2] = sdl.load_files("JLo/SAO/MBBall.png");
        SAOcard[3] = sdl.load_files("JLo/SAO/DomeDate.png");
        SAOcard[4] = sdl.load_files("JLo/SAO/Football.png");
        SAOcard[5] = sdl.load_files("JLo/SAO/RectorGotYourBack.png");
        SAOcard[6] = sdl.load_files("JLo/SAO/BedBugs.png");
        SAOcard[7] = sdl.load_files("JLo/SAO/TaxiFare.png");
        SAOcard[8] = sdl.load_files("JLo/SAO/EddyStreet.png");
        SAOcard[9] = sdl.load_files("JLo/SAO/PayDay.png");
	SAOcard[10] = sdl.load_files("JLo/SAO/FootballSeasonPass.png");
        SAOcard[11] = sdl.load_files("JLo/SAO/ClubDues.png");
        SAOcard[12] = sdl.load_files("JLo/SAO/TriviaNight.png");

	SUBcard[0] = sdl.load_files("JLo/SUB/Raffle.png");
	SUBcard[1] = sdl.load_files("JLo/SUB/SUBMovie.png");
	SUBcard[2] = sdl.load_files("JLo/SUB/DPAC.png");
	SUBcard[3] = sdl.load_files("JLo/SUB/Legends.png");
	SUBcard[4] = sdl.load_files("JLo/SUB/Reckers.png");
	SUBcard[5] = sdl.load_files("JLo/SUB/Grotto.png");
	SUBcard[6] = sdl.load_files("JLo/SUB/GetOutofJail.png");
	SUBcard[7] = sdl.load_files("JLo/SUB/Chicago.png");
	SUBcard[8] = sdl.load_files("JLo/SUB/BarTab.png");
	SUBcard[9] = sdl.load_files("JLo/SUB/BandStipend.png");
	SUBcard[10] = sdl.load_files("JLo/SUB/Tow.png");
	SUBcard[11] = sdl.load_files("JLo/SUB/WasteFreeWednesday.png");
	SUBcard[12] = sdl.load_files("JLo/SUB/Squirrel.png");
	SUBcard[13] = sdl.load_files("JLo/SUB/Prospy.png");

	tradeScreen[2] = sdl.load_files("JLo/Trade/Trade_2player.png");
	tradeScreen[3] = sdl.load_files("JLo/Trade/Trade_3player.png");
	tradeScreen[4] = sdl.load_files("JLo/Trade/Trade_4player.png");
	tradeScreen[5] = sdl.load_files("JLo/Trade/Trade_5player.png");
	tradeScreen[6] = sdl.load_files("JLo/Trade/Trade_6player.png");


	FS[60] = sdl.load_files("JLo/FS/FS60.png");
	FS[100] = sdl.load_files("JLo/FS/FS100.png");
	FS[120] = sdl.load_files("JLo/FS/FS120.png");
	FS[140] = sdl.load_files("JLo/FS/FS140.png");
	FS[150] = sdl.load_files("JLo/FS/FS150.png");
	FS[160] = sdl.load_files("JLo/FS/FS160.png");
	FS[180] = sdl.load_files("JLo/FS/FS180.png");
	FS[200] = sdl.load_files("JLo/FS/FS200.png");
	FS[220] = sdl.load_files("JLo/FS/FS220.png");
	FS[240] = sdl.load_files("JLo/FS/FS240.png");
	FS[260] = sdl.load_files("JLo/FS/FS260.png");
	FS[280] = sdl.load_files("JLo/FS/FS280.png");
	FS[300] = sdl.load_files("JLo/FS/FS300.png");
	FS[320] = sdl.load_files("JLo/FS/FS320.png");
	FS[350] = sdl.load_files("JLo/FS/FS350.png");
	FS[400] = sdl.load_files("JLo/FS/FS400.png");
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

void Game::turn()
{
	curPlayer = curPlayer++;
	if (curPlayer >= players.size()) curPlayer = 0;
	playerTurn(&players[curPlayer]);
	cout << endl << endl;
}

void Game::playerTurn(Player* current)
{
	char response;

	int keepView;

	gameBoard.checkDecks();			//checks SAO and SUB decks to make sure they aren't empty. If so rebuilds the deck
	gameBoard.checkGroupsProp();		//checks the properties to see if an entire group is owned by a player
	gameBoard.updateRentRR();		//updates the rent of the railroads based on how many a player owns
	gameBoard.updateEffects(0);		//rolls through entire board and updates effects of properties
	buildCheck(current);			//updates the deque of property titles player can build a house on
	jailTime(current);			//checks for any behavior involving jail

	response = 'z'; //random initialize

	while (response != 'r'){

		for (int i = 0; i < players.size(); i++){
			players[i].buildTiles(gameBoard);
		}

		sdl.apply_surface(150, 150, preRollImage, screen);

		cout << current->getName() << " it is your turn" << endl;
		cout << "Your current money is: $" << current->getMoney() << endl;
		current->printTiles();

		cout << "What would you like to do? (R)oll, (P)lay, (T)rade: \n";	//all 3 options presented, although trade currently does not function properly

		response = sdl.getResponse(0);
		
		switch(response)
		{
			case 'r':
				playerPostRoll(current);
				break;

			case 'b':
				build(current);
				break;
			case 'm':
				mortgage(current);
				break;
			case 't':
				trade(current);
				break;
			case 'q':
				return;
			case 'v':
				keepView = 1;
                                while(keepView){
                                        keepView = view(current);
					if (!keepView) break;
                                        sdl.getResponse(99);
                                }

			break;

		}
	}

}

void Game::playerPostRoll(Player* current){

	int output;	//stores index value from interact function
	int playerRoll;		//stores value of player's roll

	Tile *t;
	int group;
	int isProperty = 0;
	int isColorProperty = 0;

	int keepView;

	char response;
	
	if (!(current->getJail())){	
		playerRoll = rollDie(current);
		gameBoard.updateEffects(playerRoll);
	}

	SDL_Surface *disp;

	if(gameBoard.accessSpace(current->getPosition())->getTitle() == "S.U.B.")
	{
		gameBoard.accessSpace(current->getPosition())->manDeck(current, &gameBoard);
		disp = SUBcard[gameBoard.getCardNum(1)];
		gameBoard.alterDeck(1);
		cout << gameBoard.getCardNum(1) << endl;
	}
	else if (gameBoard.accessSpace(current->getPosition())->getTitle() == "S.A.O."){
		gameBoard.accessSpace(current->getPosition())->manDeck(current, &gameBoard);
                disp = SAOcard[gameBoard.getCardNum(2)];
		gameBoard.alterDeck(2);
		cout << gameBoard.getCardNum(2) << endl;
	} else {
		disp = tile[current->getPosition()];
		t = gameBoard.accessSpace(current->getPosition());
		group = t->getGroup();
		if ((group > 0) && (group <= 8)) isColorProperty = 1;
		if ((group > 0) && (group <= 10)) isProperty = 1;
		if (isProperty){
			if (gameBoard.accessSpace(current->getPosition())->getMortgage()) disp = backTile[current->getPosition()];
		}
	}
	cout << "right before postRollImage" << endl;	
	output = gameBoard.accessSpace(current->getPosition())->interact(current);	//this vomit is supposed to print out the information from the tile
	if(output != -1)
	{
		gameBoard.accessSpace(current->getPosition())->payBack(&players[output]);	//this vomit awards a player money if someone lands on their property
	}

	response = 'z';
	if(current->getJail())
	{
		response = 'r';
	}

	while (response != 'r'){
	
       		sdl.apply_surface(150, 150, postRollImage, screen);
        	sdl.apply_surface(175, 180, disp, screen);

		if (isProperty){
			if (t->getOwner() == -1){
				sdl.apply_surface(500, 180, FS[t->getCost()], screen);
			}
		}

		if (isColorProperty) applyHouses(t->getHouses(), t->getHotels());

		response = sdl.getResponse(0);
		switch (response){
			case 'b':
				gameBoard.accessSpace(current->getPosition())->buy(current);
				break;
			case 'v':
				keepView = 1;
				while(keepView){
					keepView = view(current);
					if (!keepView);
					sdl.getResponse(99);
				}
				break;
			case 'm':
				mortgage(current);
				break;
			case 'o':
				response = 'r';
				break;
			case 'q':
				return;
			case 't':
				trade(current);
				break;
		}
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

void Game::applyHouses(int numHouses, int numHotels){

	int x = 155;
	int y = 155;

	if (numHouses > 0) sdl.apply_surface(x, y, houseImage[numHouses], screen);

	if (numHotels > 0) {
		sdl.apply_surface(620, 155, houseImage[5], screen);
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
	int currentHouses;
	int currentHotels;
	int groupNum;
	int housePrice;
	int location;	//where the user wants to build

	deque<string> houseOptions;
	deque<string> hotelOptions;

	while(loop)
	{
		houseOptions = current->getHouseTiles();
		hotelOptions = current->getHotelTiles();
		houseLoop = 1;
		hotelLoop = 1;

		view(current);
	
		cout << "What would you like to build? 1 for houses ($50 each), 2 for hotels ($100 each), 3 to exit";
		cout << endl;
		select = sdl.getResponse(2);
		if (select == 'q') return;
		select -= 48;
		if(select == 1)
		{
			if(houseOptions.empty() != 1)
			{
				while(houseLoop)
				{	
					cout << "Where would you like to build a house? ";
					for(int i = 0; i < houseOptions.size(); i++)
					{
						cout << houseOptions[i] << ": " << i << endl;
					}
					cout << endl;
			
					location = sdl.getResponse(2);
					if (location == 'q') return;
					location -= 48;

				//	for(int i = 0; i < houseOptions.size(); i++)
				//	{
				//		if(location == houseOptions[i])
				//		{
							for(int j = 0; j < 40; j++)
							{
								if(houseOptions[location] == gameBoard.accessSpace(j)->getTitle())
								{
									groupNum = gameBoard.accessSpace(j)->getGroup();
									housePrice = ((groupNum-1)/2)*50 + 50;
									currentHouses = gameBoard.accessSpace(j)->getHouses();
									cout << "There are " << currentHouses << " houses here. How many houses would you like to add (max 4) at cost of $" << housePrice << " per house?" << endl;
									cout << endl;
									if (currentHouses == 4) {
										houseLoop = 0;
										break;
									}
									housesAdded = sdl.getResponse(2);
									if (housesAdded == 'q') return;
									housesAdded -= 48;
									if(current->getMoney() <= housePrice*housesAdded)
									{
										cout << "You can't afford that many houses!" << endl;
										houseLoop = 0;
										break;
									}
									if((currentHouses + housesAdded) > 4) housesAdded = 4 - currentHouses;
									gameBoard.accessSpace(j)->addHouses(housesAdded);
									current->changeInMoney((-housePrice) * housesAdded);
									houseLoop = 0;
								}
							}
				//		}
				//	}
					if(houseLoop != 0)
					{
						cout << "That is not somewhere you can build a house" << endl;
						return;
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
						cout << hotelOptions[i] << ": " << i << endl;
					}
					cout << endl;
					location = sdl.getResponse(2);
					if (location == 'q') return;
					location -= 48;

				//	for(int i = 0; i < hotelOptions.size(); i++)
				//	{
				//		if(location == hotelOptions[i])
				//		{
							for(int j = 0; j < 40; j++)
							{
								if(hotelOptions[location] == gameBoard.accessSpace(j)->getTitle())
								{
									if (gameBoard.accessSpace(j)->getHouses() != 4){
										cout << "Need four houses to build hotel" << endl;
										hotelLoop = 0;
										break;
									}
 									groupNum = gameBoard.accessSpace(j)->getGroup();
                                                                        housePrice = ((groupNum-1)/2)*50 + 50;
                                                                        currentHotels = gameBoard.accessSpace(j)->getHotels();
                                                                        cout << "There are " << currentHotels << " hotels here. How many hotels would you like to add (max 4) at cost of $" << housePrice << " per house?" << endl;

									cout << endl;
									if (currentHotels == 1) break;
									hotelsAdded = sdl.getResponse(2);
									if (hotelsAdded == 'q') return;
									hotelsAdded -= 48;
									if(current->getMoney() <= 100*hotelsAdded)
									{
										cout << "You can't afford to buy a hotel!" << endl;
										hotelLoop = 0;
										break;
									}
									if (hotelsAdded != 1) hotelsAdded = 1;
									gameBoard.accessSpace(j)->addHotels(hotelsAdded);
									gameBoard.accessSpace(j)->addHouses(-4);
									current->changeInMoney(-100);
									hotelLoop = 0;
								}
							}
				//		}
				//	}
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

void Game::mortgage(Player* current)
{
	int place;
	deque<string> owned;
	int moveOn;	//is set to 1 if the player picks a valid tile
	int mortgageReturn;	//amount player receives for mortgaging
	char mortgageYN;	//players final decision	
	int j;
	bool status;		//bool representing mortgaged status of selected location

	owned = current->getTiles();
	
	view(current);

//	current->printTiles();
	cout << "What would you like to mortgage or unmortgage?";
		
	for(int i = 0; i < owned.size(); i++)
	{
		cout << owned[i] << ": " << i << endl;
	}


	place = sdl.getResponse(4);
	if (place == 'q') return;
	place -= 48;
/*
	for(int i = 0; i < owned.size(); i++)
	{
		if(place == owned[i])
		{
			moveOn = 1;
		}
	}

	if(moveOn == 0)
	{
		cout << "Sorry! That's not a tile you own!" << endl;
		return;
	}
	else if(moveOn == 1)
	{*/
		for(j = 0; j < 40; j++)
		{
			if(gameBoard.accessSpace(j)->getTitle() == owned[place])
			{
				mortgageReturn = (gameBoard.accessSpace(j)->getCost())/2;
				status = gameBoard.accessSpace(j)->getMortgage();
				break;
			}
		}
		
		if(status == 0)
		{
			cout << "Would you like to mortgage " << owned[place] << " and gain " << mortgageReturn << "? (y/n)";
			cout << endl;
			mortgageYN = sdl.getResponse(4);
	
			if(mortgageYN == 'y')
			{
				cout << "Entered changeInMoney" << endl;
				current->changeInMoney(mortgageReturn);
				cout << "Attepmting to setMortgage" << endl;
				gameBoard.accessSpace(j)->setMortgage(true);
				cout << "setMortgage successful" << endl;
			}
		}
		else if(status == 1 && current->getMoney() > mortgageReturn)
		{
			cout << "Would you like to unmortgage " << owned[place] << "? It will cost you " << mortgageReturn << ". (y/n)";
			cout << endl;
			mortgageYN = sdl.getResponse(4);

			if(mortgageYN == 'y')
			{
				current->changeInMoney(-mortgageReturn);
				gameBoard.accessSpace(j)->setMortgage(false);
			}
		}
		else if(status == 1 && current->getMoney() <= mortgageReturn)
		{
			cout << "This location is mortgaged, and you can't afford to unmortgage it!" << endl;
		}

	return;

//	}
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

int Game::view(Player* current){

	char response;

	int sprite_x = 150;
	int sprite_y = 150;

	SDL_Surface *disp;

//	sdl.apply_surface(150,150, postRollImage, screen);
	sdl.apply_surface(sprite_x, sprite_y, sprites, screen);

	if (current->notOwnTile("Welsh Family Hall")) sdl.apply_surface(sprite_x+15, sprite_y+45, whitespace, screen);
        if (current->notOwnTile("Ryan Hall")) sdl.apply_surface(sprite_x+97, sprite_y+45, whitespace, screen);
        if (current->notOwnTile("McGlinn Hall")) sdl.apply_surface(sprite_x+185, sprite_y+45, whitespace, screen);
        if (current->notOwnTile("The Grotto")) sdl.apply_surface(sprite_x+16, sprite_y+122, whitespace, screen);
        if (current->notOwnTile("Main Building")) sdl.apply_surface(sprite_x+101, sprite_y+123, whitespace, screen);
        if (current->notOwnTile("Seigfried Hall")) sdl.apply_surface(sprite_x+20, sprite_y+203, whitespace, screen);
        if (current->notOwnTile("Lewis Hall")) sdl.apply_surface(sprite_x+105, sprite_y+205, whitespace, screen);
        if (current->notOwnTile("Carrol Hall")) sdl.apply_surface(sprite_x+197, sprite_y+207, whitespace, screen);
        if (current->notOwnTile("Pasquerilla West")) sdl.apply_surface(sprite_x+21, sprite_y+275, whitespace, screen);
        if (current->notOwnTile("Pasquerilla East")) sdl.apply_surface(sprite_x+106, sprite_y+276, whitespace, screen);
        if (current->notOwnTile("O'Neill Hall")) sdl.apply_surface(sprite_x+27, sprite_y+351, whitespace, screen);
        if (current->notOwnTile("Keough Hall")) sdl.apply_surface(sprite_x+105, sprite_y+351, whitespace, screen);
        if (current->notOwnTile("Duncan Hall")) sdl.apply_surface(sprite_x+186, sprite_y+353, whitespace, screen);
        if (current->notOwnTile("Notre Dame Stadium")) sdl.apply_surface(sprite_x+32, sprite_y+426, whitespace, screen);
        if (current->notOwnTile("J.A.C.C.")) sdl.apply_surface(sprite_x+110, sprite_y+427, whitespace, screen);
        if (current->notOwnTile("Compton Ice Arena")) sdl.apply_surface(sprite_x+188, sprite_y+426, whitespace, screen);
        if (current->notOwnTile("Badin Hall")) sdl.apply_surface(sprite_x+309, sprite_y+55, whitespace, screen);
        if (current->notOwnTile("Howard Hall")) sdl.apply_surface(sprite_x+392, sprite_y+53, whitespace, screen);
        if (current->notOwnTile("Lyons Hall")) sdl.apply_surface(sprite_x+464, sprite_y+52, whitespace, screen);
        if (current->notOwnTile("Alumni Hall")) sdl.apply_surface(sprite_x+313, sprite_y+125, whitespace, screen);
        if (current->notOwnTile("Dillon Hall")) sdl.apply_surface(sprite_x+392, sprite_y+126, whitespace, screen);
        if (current->notOwnTile("Fisher Hall")) sdl.apply_surface(sprite_x+469, sprite_y+127, whitespace, screen);
        if (current->notOwnTile("Hesburgh Library")) sdl.apply_surface(sprite_x+391, sprite_y+211, whitespace, screen);
        if (current->notOwnTile("Lafortune Student Center")) sdl.apply_surface(sprite_x+467, sprite_y+211, whitespace, screen);
        if (current->notOwnTile("Coleman Morris Center")) sdl.apply_surface(sprite_x+393, sprite_y+282, whitespace, screen);
        if (current->notOwnTile("DeBartolo Hall")) sdl.apply_surface(sprite_x+471, sprite_y+280, whitespace, screen);
        if (current->notOwnTile("North Dining Hall")) sdl.apply_surface(sprite_x+393, sprite_y+352, whitespace, screen);
        if (current->notOwnTile("South Dining Hall")) sdl.apply_surface(sprite_x+471, sprite_y+351, whitespace, screen);

	response = sdl.getResponse(1);
	if (response == 'q') return 0;

	if (gameBoard.accessSpace(response)->getOwner() == current->getIndex()){	
		disp = tile[response];
		if (gameBoard.accessSpace(response)->getMortgage()) disp = backTile[response];
	}
	
	sdl.apply_surface(175, 180, disp, screen);	

	return 1;

}

void Game::trade(Player* current)		//this function was thrown together somewhat carelessly, I'm having problems with getline
{
	string recipient;
	int recipIndex;
	int offer = -1;
	int request = -1;
	char answer;
	deque<string> options;
	deque<string> playerOwns;
	SDL_Surface *disp;

	cout << "Entered trade" << endl;

	disp = tradeScreen[players.size()];

	sdl.apply_surface(150, 150, disp, screen);
	cout << "Applied surface" << endl;
	cout << current->getName() << ", who would you like to trade with? Please input their number" << endl;
	
	for(int i = 0; i < players.size(); i++)
	{
		if (players[i].getIndex() != current->getIndex()) cout << players[i].getName() << ": (" << players[i].getIndex() << ")" << endl;
	}

	recipIndex = sdl.getResponse(3);
	if (recipIndex == 'c') {
		cout << "return from trade" << endl;	
		return;
	}
	recipIndex -= 48;
	if (recipIndex >= current->getIndex()) recipIndex++;
	cout << "Here is what " << players[recipIndex].getName() << " owns: " << endl;
	options = players[recipIndex].getTiles();
	playerOwns = current->getTiles();


	for(int i = 0; i < options.size(); i++)
	{
		cout << options[i] << ": " << i << endl;
	}
	
	while (request < 0){

		view(&players[recipIndex]);

		cout << "What would you like to trade for? Please enter the number associated with the name";
		cout << endl;
		request = sdl.getResponse(1);
		if (request == 'c') return;
		request -= 48;
//		gameBoard.accessSpace(request)->
	}

	cout << "Here is what you can offer. Enter the number of the location you'd like to offer in return" << endl;

	for(int i = 0; i < playerOwns.size(); i++)
	{
		cout << playerOwns[i] << ": " << i << endl;
	}

	view(current);
	cout << "Your offer: ";
	cout << endl;
	offer = sdl.getResponse(3); 
	if (offer == 'c') return;
	offer -= 48;

	cout << players[recipIndex].getName() << ", do you accept this trade? " << playerOwns[offer] << " for " << options[request] << "? (y/n)" << endl;
	answer = sdl.getResponse(3);

	if(answer == 'n') return;
	else if(answer == 'y')
	{
		cout << "Congratulations! Trade completed!" << endl;
		for(int i = 0; i < 40; i++)
		{
			if(gameBoard.accessSpace(i)->getTitle() == options[request])
			{
				gameBoard.accessSpace(i)->setOwner(current->getIndex());
			}
			if(gameBoard.accessSpace(i)->getTitle() == playerOwns[offer])
			{
				gameBoard.accessSpace(i)->setOwner(recipIndex);
			}
		}
	}
}

int Game::gameOver()
{
	for(int i = 0; i < players.size(); i++)
	{
		if(players[i].getMoney() <= 0 && (players[i].getTiles()).empty())
		{
			cout << players[i].getName() << ", you have run out of money! You are eliminated from the game! Thanks for playing!" << endl;
			players.erase(players.begin()+i);
		}
		else if(players[i].getMoney() <= 0 && !((players[i].getTiles().empty())))
		{
			cout << players[i].getName() << ", you have no money, but you do have properties! You will be sent to the mortgaging screen. Not mortgaging will result in your elimination" << endl;
			mortgage(&players[i]);
			if(players[i].getMoney() <= 0)
			{
				cout << "You still have no money! You are eliminated from the game! Thanks for playing!" << endl;
				players.erase(players.begin()+i);
			}
		}
	}

	if(players.size() == 1)
	{
		cout << "Congratulations " << players[0].getName() << ", you are the only player remaining! You (and capitalism) win!" << endl;
		return 1;
	}
	else
	{
		return 0;
	}
	
}

void Game::jailTime(Player* current)
{
	char pay;

	if(current->getJail() == 1)
	{
			current->addTimeJail();
			if(current->getTimeJail() != 0)
			{
				cout << current->getName() << ", you are stuck at res life!" << endl;
				if(current->getGOOJ() == 1)
				{
					current->setJail(0);
					cout << "You got out of res life for free!" << endl;
					return;
				}
				if(current->getMoney() > 50)
				{
					cout << "Would you like to pay off the service hours? (y/n)";
					pay = sdl.getResponse(5);
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
	else if(current->getJail() == 0 && current->getPosition() == 10)
	{
		cout << "You landed on res life! Just passing through..." << endl;
		return;
	}
}

void Game::addScreen(SDL_Surface *point){
	screen = point;
}
