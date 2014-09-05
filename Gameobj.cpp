#include "Gameobj.h"
#include <iostream>
#include "TextureMgr.h"

Gameobj::Gameobj()
{
}

Gameobj::~Gameobj()
{
}

void Gameobj::Frame()
{
	SDL_SetRenderDrawColor(GetMainRenderer(), 123,32,11, 255);
	SDL_RenderClear(GetMainRenderer());
	int w = 0;
	int h = 0;
	TextureMgr::Instance()->Draw("pic", 10,10 );
	SDL_RenderPresent(GetMainRenderer());
}
void Gameobj::LoadResource()
{
	TextureMgr::Instance()->Init(GetMainRenderer());
	TextureMgr::Instance()->LoadImage("pic.png", "pic");
}

void Gameobj::KeyDown(SDL_Event* event)
{
	if( event == 0) {
		return ;
	}
	if( event->key.keysym.sym == SDLK_ESCAPE) {
		QuitGame();
	}
}
