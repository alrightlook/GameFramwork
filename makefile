GameFrameWorkDemo:main.o Player.o Thread.o Game.o TextureMgr.o log.o MapEngine.o Gameobj.o
	g++ -g -o GameFrameWorkDemo log.o Thread.o Player.o MapEngine.o Game.o Gameobj.o TextureMgr.o main.o `pkg-config --libs sdl2` `pkg-config --libs SDL2_image`
	rm -fr *.o
Thread.o:Thread.cpp
	g++ -g -c Thread.cpp `pkg-config --cflags sdl2`
Player.o:Player.cpp
	g++ -g -c Player.cpp `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image`
log.o:log.cpp
	g++ -g -c log.cpp `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image`
main.o:main.cpp
	g++ -g -c main.cpp `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image`
MapEngine.o:MapEngine.cpp
	g++ -g -c MapEngine.cpp `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image`
Gameobj.o:Gameobj.cpp
	g++ -g -c Gameobj.cpp `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image`
Game.o:Game.cpp
	g++ -g -c Game.cpp `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image`
TextureMgr.o:TextureMgr.cpp
	g++ -g -c TextureMgr.cpp `pkg-config --cflags sdl2` `pkg-config --cflags SDL2_image`
clean:
	rm -fr *.o GameFrameWorkDemo 

