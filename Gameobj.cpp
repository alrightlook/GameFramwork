#include "Gameobj.h"
#include <iostream>
#include "TextureMgr.h"
#include "MapEngine.h"
#include "Player.h"

Gameobj::Gameobj()
{
}

Gameobj::~Gameobj()
{

}
void Gameobj::Init(const char* title, int x, int y, int w, int h, Uint32 flags)
{
	Game::Init(title, x, y, w, h, flags);
	MapEngine::Instance()->GenerateMap(70,70);
	MapEngine::Instance()->GenerateRoom(15, 15, 4, 4, 50);
	Player::Instance()->GeneratePlayer();
	
	MapEngine::Instance()->DumpToDisk("Map.txt");
}

void Gameobj::Frame()
{
	SDL_SetRenderDrawColor(GetMainRenderer(), 123,32,11, 255);
	ClearRenderer();
	TextureMgr::Instance()->Draw("pic", 15,10 );
	SDL_RenderPresent(GetMainRenderer());
	PostRepaint(false);
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
