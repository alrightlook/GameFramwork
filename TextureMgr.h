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
		void Draw(std::string ImageId, SDL_Rect* srsRect, SDL_Rect* desRect, bool isScaled = false);
		static TextureMgr* Instance();
		void Init(SDL_Renderer* ren);
		void GetTextureDimension(std::string ImageID, int* w, int* h);
		~TextureMgr();
		void LoadImage(const char* filename, std::string ImageID);
};
#endif
