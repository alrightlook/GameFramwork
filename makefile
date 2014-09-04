GameFrameWorkDemo:main.o Game.o TextureMgr.o
	g++ -g -o GameFrameWorkDemo Game.o TextureMgr.o main.o -lmingw32 -lSDL2main -lSDL2
main.o:main.cpp
	g++ -g -c main.cpp
Game.o:Game.cpp
	g++ -g -c Game.cpp
TextureMgr.o:TextureMgr.cpp
	g++ -g -c TextureMgr.cpp
clean:
	rm -fr *.o *.exe *~

