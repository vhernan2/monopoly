all: monopoly

monopoly: main.o button.o
	g++ main.o button.o -lSDL -o monopoly

main.o: main.cpp
	g++ -c main.cpp

button.o: button.cpp
	g++ -c button.cpp

make clean:
	rm -f *.o monopoly
