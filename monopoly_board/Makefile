SUBDIRS=Mike/ Victor/

MONOPOLY_BOARD_FILES=driver.o Monopoly_Board.o PlayerPiece.o

MIKE_FILES=./Mike/Bland.o ./Mike/Board.o ./Mike/CardSpaces.o ./Mike/Game.o ./Mike/Jail.o ./Mike/Player.o ./Mike/Property.o ./Mike/Railroad.o ./Mike/SAO.o ./Mike/SUB.o ./Mike/Tax.o ./Mike/Tile.o ./Mike/Utility.o ./Mike/SDL_logic.o

FLAGS=-lSDL -lSDL_image

main: ${MONOPOLY_BOARD_FILES} ${MIKE_FILES}
	g++ ${MONOPOLY_BOARD_FILES} ${MIKE_FILES} -o monopoly ${FLAGS}

all test install clean:
	@for s in $(SUBDIRS); do cd $$s && $(MAKE) $@ && cd ..; done
	rm -f *.o monopoly

