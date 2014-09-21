GameFrameWorkDemo:main.o Player.o Game.o TextureMgr.o log.o MapEngine.o Gameobj.o
	g++ -g -o GameFrameWorkDemo log.o Player.o MapEngine.o Game.o Gameobj.o TextureMgr.o main.o -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
	rm -fr *.o
Player.o:Player.cpp
	g++ -g -c Player.cpp
log.o:log.cpp
	g++ -g -c log.cpp
main.o:main.cpp
	g++ -g -c main.cpp
MapEngine.o:MapEngine.cpp
	g++ -g -c MapEngine.cpp
Gameobj.o:Gameobj.cpp
	g++ -g -c Gameobj.cpp
Game.o:Game.cpp
	g++ -g -c Game.cpp
TextureMgr.o:TextureMgr.cpp
	g++ -g -c TextureMgr.cpp
clean:
	rm -fr *.o *.exe *~

