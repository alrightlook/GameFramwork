#include "MapEngine.h"
#include "memory.h"
#include <fstream>
using namespace std;
MapEngine* MapEngine::m_Instance = 0;

void MapEngine::GenerateMap(int w, int h)
{
	m_nWidth = w;
	m_nHeight = h;
	m_theMap = new int*[h];
	for (int i = 0; i< h; i++) 
	{
		m_theMap[i] = new int[w];
		memset(m_theMap[i], 0, w * sizeof(int));
	}

}

void MapEngine::DumpToDisk(const char* filename)
{
	fstream fs;
	fs.open(filename, ios::out);
	for (int i = 0; i < m_nHeight ; i++ )
	{
		for( int j = 0; j< m_nWidth ; j++)
		{
			fs<<m_theMap[i][j]<<"  ";
		}
		fs<<std::endl;
	}
}

MapEngine::MapEngine()
{
	m_theMap = 0;
	m_nWidth = 0;
	m_nHeight = 0;
}

MapEngine::~MapEngine()
{
}

MapEngine* MapEngine::Instance()
{
	if( m_Instance == 0) {
		m_Instance = new MapEngine();
	}
	return m_Instance;
}
