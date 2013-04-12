all: monopoly

monopoly: main.o basics.o
	g++ main.o basics.o -lSDL -o monopoly

main.o: main.cpp
	g++ -c main.cpp

basics.o: basics.cpp
	g++ -c basics.cpp

make clean:
	rm -f *.o monopoly
