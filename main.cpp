#include <iostream>
#include <SDL.h>
#include "Game.h"

int main(int argc, char* argv[])
{
	Game game;
	game.Init("Hello GameFrameWork Demo", 100,100, 640,480, SDL_RENDERER_ACCELERATED);
	game.Run();
	return 0;
}
