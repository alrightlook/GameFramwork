#include "Game.h"
#include <iostream>
#include <SDL.h>

Game::Game()
{
	m_bQuit = false;
	m_MainWindow = 0;
	m_MainRender = 0;
}

Game::~Game()
{
	SDL_DestroyRenderer(m_MainRender);
	SDL_DestroyWindow(m_MainWindow);
	SDL_Quit();
}

SDL_Renderer* Game::GetMainRenderer()
{
	return m_MainRender;
}

void Game::Init(const char* title, int x, int y, int w, int h, Uint32 flags)
{
	if( SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout<<"Game Init error"<<std::endl;
		return ;
	}
	m_MainWindow = SDL_CreateWindow(title, x, y, w, h, flags);
	if( m_MainWindow == 0) {
		std::cout<<"Can not create sdl window"<<std::endl;
	}
	m_MainRender = SDL_CreateRenderer(m_MainWindow, -1, SDL_RENDERER_ACCELERATED);
	if( m_MainRender == 0) {
		std::cout<<"Can not create sdl renderer"<<std::endl;
	}
}

void Game::LoadResource()
{

}

void Game::Frame()
{
	SDL_SetRenderDrawColor(m_MainRender, 0,0,0,255);
	SDL_RenderClear(m_MainRender);
	SDL_RenderPresent(m_MainRender);

}
void Game::Run()
{
	SDL_Event e;
	while(!m_bQuit)
	{
		if(SDL_PollEvent(&e)) {
			if( e.type == SDL_QUIT) {
				m_bQuit = true;
			}
		}
		else {
			Frame();
		}
	}
}
