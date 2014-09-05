#ifndef MAPENGINE_HEADER
#define MAPENGINE_HEADER
#include <map>
struct Room
{
	int posx;
	int posy;
	int width;
	int height;
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
