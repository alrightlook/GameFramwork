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
		void LoadResource();
};
#endif
