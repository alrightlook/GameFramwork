#ifndef GAMEOBJ_HEADER
#define GAMEOBJ_HEADER

#include "Game.h"

class Gameobj :public Game
{
	public:
		Gameobj();
		~Gameobj();
	public:
		void Frame();
		void KeyDown(SDL_Event* event);
		void LoadResource();
};
#endif
