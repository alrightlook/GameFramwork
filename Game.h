#ifndef GAME_CLASS_HEADER
#define GAME_CLASS_HEADER
#include <SDL.h>

class Game
{
	public:
		Game();
		~Game();

	public:
		void Init(const char* title, int x, int y, int w, int h, Uint32 flags);
		SDL_Renderer* GetMainRenderer();
		SDL_Window* GetMainWindow();
		void Run();
		void QuitGame();
		virtual void Frame();
		virtual void LoadResource();
		virtual void KeyDown(SDL_Event* event);
		
	private:
		bool m_bQuit;
		SDL_Window* m_MainWindow;
		SDL_Renderer* m_MainRender;
};
#endif
