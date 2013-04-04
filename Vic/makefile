all: main
main: test.o Player.o Board.o Tile.o Property.o
	g++ test.o Player.o Board.o Tile.o Property.o -o main

Player.o: Player.cpp
	g++ -c Player.cpp

Board.o: Board.cpp
	g++ -c Board.cpp

Tile.o: Tile.cpp
	g++ -c Tile.cpp

Property.o: Property.cpp
	g++ -c Property.cpp

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm -f *.o main
