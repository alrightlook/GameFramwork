#ifndef TEXTUREMGR_HEADER
#define TEXTUREMGR_HEADER
#include <SDL.h>
#include <SDL_Image.h>
#include <string>
#include <map>

class TextureMgr
{
	private:
		static TextureMgr* m_Instance;
		TextureMgr();
		std::map<std::string, SDL_Texture*> m_mapTexture;

		SDL_Renderer* m_mainRenderer;
		
	public:
		static TextureMgr* Instance();
		void Init(SDL_Renderer* ren);
		~TextureMgr();
		void LoadImage(const char* filename, std::string ImageID);
};
#endif
