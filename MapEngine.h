#ifndef MAPENGINE_HEADER
#define MAPENGINE_HEADER
#include <map>

#define ROAD 0
#define WALL 1
#define DOOR 2
#define PLAYER 3
struct Door
{
	int posx;
	int posy;
};
struct Room
{
	int posx;
	int posy;
	int width;
	int height;
	int doors;
	std::map<int, Door> mapDoor;
};

class MapEngine
{
	public:
		~MapEngine();
		static MapEngine* Instance();
		void GenerateMap(int w, int h);
		void DumpToDisk(const char* filename);
		void GenerateRoom(int maxWidth, int maxHeight, int minWidth, int minHeight, int count);
		void GetTile(int x, int y, int* tile);
		void SetTile(int x, int y, int tile);
		void QuerySpace(int* x, int* y);
	private:
		void CreateDoors();
		void AddRoom(int index,int posx, int posy, int width, int height);
		bool CheckOverlap(int posx, int posy,int width, int height);
		std::map<int, Room> m_mapRoom;	
		int** m_theMap;
		int m_nWidth;
		int m_nHeight;
		static MapEngine* m_Instance;
		MapEngine();
};
#endif
