all: test
test: test.o Player.o Board.o Tile.o Property.o Railroad.o Game.o
	g++ test.o Player.o Board.o Tile.o Property.o Railroad.o Game.o -o main

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

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm -f *.o test
