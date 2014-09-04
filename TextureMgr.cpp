#include "TextureMgr.h"

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

void TextureMgr::LoadImage(const char* filename, std::string ImageID)
{
}
