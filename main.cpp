#include <iostream>
#include <SDL.h>

#include "Gameobj.h"

int main(int argc, char* argv[])
{
	Gameobj game;
	game.Init("Hello GameFrameWork Demo", 100,100, 1024,768, SDL_RENDERER_ACCELERATED | SDL_WINDOW_FULLSCREEN);
	game.LoadResource();
	game.Run();
	return 0;
}
