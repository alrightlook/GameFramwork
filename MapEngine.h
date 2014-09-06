#ifndef MAPENGINE_HEADER
#define MAPENGINE_HEADER
#include <map>
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
