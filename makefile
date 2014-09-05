GameFrameWorkDemo:main.o Game.o Gameobj.o TextureMgr.o
	g++ -g -o GameFrameWorkDemo Gameobj.o Game.o TextureMgr.o main.o -lSDL2main -lmingw32 -lSDL2
main.o:main.cpp
	g++ -g -c main.cpp
Gameobj.o:Gameobj.cpp
	g++ -g -c Gameobj.cpp
Game.o:Game.cpp
	g++ -g -c Game.cpp
TextureMgr.o:TextureMgr.cpp
	g++ -g -c TextureMgr.cpp
clean:
	rm -fr *.o *.exe *~

