all: main
main: test.o Player.o Board.o Tile.o Property.o Railroad.o CardSpaces.o Bland.o Tax.o Jail.o Utility.o SUB.o SAO.o SDL_logic.o Game.o
	g++ test.o Player.o Board.o Tile.o Property.o Railroad.o CardSpaces.o Bland.o Tax.o Jail.o Utility.o SUB.o SAO.o SDL_logic.o Game.o -o main -lSDL -lSDL_image

Player.o: Player.cpp
	g++ -c Player.cpp

Board.o: Board.cpp
	g++ -c Board.cpp

Tile.o: Tile.cpp
	g++ -c Tile.cpp

Property.o: Property.cpp
	g++ -c Property.cpp

Game.o: Game.cpp
	g++ -c Game.cpp

Railroad.o: Railroad.cpp
	g++ -c Railroad.cpp

CardSpaces.o: CardSpaces.cpp
	g++ -c CardSpaces.cpp

Bland.o: Bland.cpp
	g++ -c Bland.cpp

Tax.o: Tax.cpp
	g++ -c Tax.cpp

Jail.o: Jail.cpp
	g++ -c Jail.cpp

Utility.o: Utility.cpp
	g++ -c Utility.cpp

SUB.o: SUB.cpp
	g++ -c SUB.cpp

SAO.o: SAO.cpp
	g++ -c SAO.cpp

SDL_logic.o: SDL_logic.cpp
	g++ -c SDL_logic.cpp

test.o: test.cpp
	g++ -c test.cpp

make clean:
	rm -f *.o main
