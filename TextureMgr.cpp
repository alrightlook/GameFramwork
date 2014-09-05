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

void TextureMgr::GetTextureDimension(std::string ImageId, int* w, int* h)
{
	if( m_mapTexture.find(ImageId) == m_mapTexture.end()) {
		return ;
	}
	Texture tex;
	tex =m_mapTexture.find(ImageId)->second;
	Uint32 format = 0;
	int access = 0;

	SDL_QueryTexture(tex.tex, &format, &access, w, h); 
}

void TextureMgr::Draw(std::string ImageID, SDL_Rect* srcRect, SDL_Rect* desRect)
{
	if( m_mapTexture.find(ImageID) == m_mapTexture.end()) {
		return ;
	}
	Texture tex = m_mapTexture.find(ImageID)->second;
	SDL_RenderCopy(m_mainRenderer, tex.tex, srcRect, desRect);
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

	Texture texture;
	texture.tex = tex;
	Uint32 format = 0;
	int access = 0;
	SDL_QueryTexture(tex, &format, &access, &texture.width, &texture.height); 

	m_mapTexture.insert(std::pair<std::string, Texture>(ImageID, texture));
	Log outlog("output.log");
	outlog.write("GFD", "Insert 1");
	SDL_FreeSurface(surf);
}

void TextureMgr::Draw(std::string ImageId, int x, int y)
{
	if(m_mapTexture.find(ImageId) == m_mapTexture.end()) {
		return ;
	}
	Texture texture;
	texture = m_mapTexture.find(ImageId)->second;
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = texture.width;
	rect.h = texture.height;
	Draw(ImageId, 0, &rect);
}
