#ifndef THREAD_HEADER
#define THREAD_HEADER
#include <sdl.h>
class Thread
{
	public:
		Thread();
		virtual ~Thread();

		void CreateRunable(SDL_ThreadFunction pfunc);
		void Wait();
	private:
		SDL_ThreadFunction m_pfunc;
		SDL_Thread* m_thread;

};

#endif
