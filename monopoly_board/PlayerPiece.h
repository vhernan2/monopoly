#ifndef PLAYER_PIECE
#define PLAYER_PIECE

#include "Mike/Game.h"

using namespace std;

class PlayerPiece{

	public:
	PlayerPiece();
	void move(int);
        int getX();
        int getY();

        private:
        int x, y;

};
#endif
