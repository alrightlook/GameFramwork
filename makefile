GameFrameWorkDemo:main.o Game.o
	g++ -g -o GameFrameWorkDemo Game.o main.o -lSDL2main -lmingw32 -lSDL2
main.o:main.cpp
	g++ -g -c main.cpp
Game.o:Game.cpp
	g++ -g -c Game.cpp
clean:
	rm -fr *.o *.exe *~

