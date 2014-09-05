#include "TextureMgr.h"
#include <iostream>
#include "Log.h"

TextureMgr* TextureMgr::m_Instance = 0;

TextureMgr::TextureMgr()
{
}

TextureMgr::~TextureMgr()
{
}

TextureMgr* TextureMgr::Instance()
{
	if( m_Instance == 0) {
		m_Instance = new TextureMgr();
	}
	return m_Instance;
}

void TextureMgr::Init(SDL_Renderer* ren)
{
	m_mainRenderer = ren;
}

void TextureMgr::LoadImage(const char* filename, std::string ImageID)
{
	if(m_mapTexture.find(ImageID) != m_mapTexture.end()) {
		return ;
	}
	SDL_Surface* surf = 0;
	SDL_Texture* tex = 0;

	surf = IMG_Load(filename);
	if( surf == 0) {
		return ;
	}
	
	tex = SDL_CreateTextureFromSurface(m_mainRenderer, surf);
	if (tex == 0 ) {
		return ;
	}

	m_mapTexture.insert(std::pair<std::string, SDL_Texture*>(ImageID, tex));
	Log outlog("output.log");
	outlog.write("GFD", "Insert 1");
}
