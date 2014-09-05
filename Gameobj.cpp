#include "Gameobj.h"
#include <iostream>
#include "TextureMgr.h"

Gameobj::Gameobj()
{
}

Gameobj::~Gameobj()
{
}

void Gameobj::LoadResource()
{
	TextureMgr::Instance()->Init(GetMainRenderer());
	TextureMgr::Instance()->LoadImage("pic.png", "pic");
}
