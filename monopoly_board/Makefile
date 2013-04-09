TARGET=monopoly_board
FLAGS=-lSDL -lSDL_image


all: ${TARGET}

${TARGET}: ${TARGET}.o
	g++ ${TARGET}.o -o ${TARGET} ${FLAGS}

${TARGET}.o: ${TARGET}.cpp
	g++ -c ${TARGET}.cpp

clean:
	rm -f *.o ${TARGET} main	

