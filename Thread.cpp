#include "Thread.h"

Thread::Thread()
{
}

Thread::~Thread()
{
}

void Thread::CreateRunable(SDL_ThreadFunction pfunc)
{
	m_pfunc = pfunc;
	m_thread = SDL_CreateThread(m_pfunc, NULL, NULL);
}

void Thread::Wait()
{
	SDL_WaitThread(m_thread, NULL);
}
