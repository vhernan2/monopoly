#ifndef SDL_LOGIC_H
#define SDL_LOGIC_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

using namespace std;

class SDL_logic
{
public:
	SDL_logic();
	~SDL_logic();
	void apply_surface(int, int, SDL_Surface*, SDL_Surface*);
	SDL_Surface* load_files(string);
	void clean_up();
	char getResponse();

private:
	SDL_Event event;
	SDL_Surface *destination;

};
#endif
