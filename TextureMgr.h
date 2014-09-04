#ifndef TEXTUREMGR_HEADER
#define TEXTUREMGR_HEADER
#include <SDL.h>
#include <SDL_Image.h>
#include <string>

class TextureMgr
{
	private:
		static TextureMgr* m_Instance;
		TextureMgr();
	public:
		static TextureMgr* Instance();
		~TextureMgr();
		void LoadImage(const char* filename, std::string ImageID);
};
#endif
