#ifndef GAMEOBJ_HEADER
#define GAMEOBJ_HEADER

#include "Game.h"

class Gameobj :public Game
{
	public:
		Gameobj();
		~Gameobj();
	public:
		virtual void Init(const char * title, int x, int y , int w, int h, Uint32 flags);
		void Frame();
		void KeyDown(SDL_Event* event);
		void LoadResource();
};
#endif
