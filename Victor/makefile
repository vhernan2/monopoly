all: monopoly

monopoly: main.o
	g++ main.o -lSDL -lSDL_ttf -lSDL_mixer -Wall -o monopoly

main.o: main.cpp
	g++ -c main.cpp

make clean:
	rm -f *.o monopoly
