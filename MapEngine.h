#ifndef MAPENGINE_HEADER
#define MAPENGINE_HEADER

class MapEngine
{
	public:
		~MapEngine();
		static MapEngine* Instance();
		void GenerateMap(int w, int h);
		void DumpToDisk(const char* filename);
		void GenerateRoom(int maxWidth, int maxHeight, int minWidth, int minHeight, int count);
	private:
		int** m_theMap;
		int m_nWidth;
		int m_nHeight;
		static MapEngine* m_Instance;
		MapEngine();
};
#endif
