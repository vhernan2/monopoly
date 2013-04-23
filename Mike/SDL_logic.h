#ifndef SDL_LOGIC_H
#define SDL_LOGIC_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

using namespace std;

class SDL_logic
{
public:
	SDL_logic();
	~SDL_logic();
	char getResponse();

private:
	SDL_Event event;
	SDL_Surface *destination;

};
#endif
