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
	TextureMgr::Instance()->GetTextureDimension("pic", &w, &h);
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0; 
	rect.w = w;
	rect.h = h;
	TextureMgr::Instance()->Draw("pic", 0, &rect);
	SDL_RenderPresent(GetMainRenderer());
}
void Gameobj::LoadResource()
{
	TextureMgr::Instance()->Init(GetMainRenderer());
	TextureMgr::Instance()->LoadImage("pic.png", "pic");
}
