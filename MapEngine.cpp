#include "MapEngine.h"
#include "memory.h"
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;
MapEngine* MapEngine::m_Instance = 0;

void MapEngine::GenerateMap(int w, int h)
{
	//--------------------------------------------> x width
	//| (0,0)
	//|
	//|
	//|
	//|
	//|
	//|
	//|
	//|
	//|
	//|
	//|
	//|
	//|
	//|
	//|
	//J y  height

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

void MapEngine::GenerateRoom(int maxWidth, int maxHeight, int minWidth, int minHeight, int count)
{
	if(minWidth < 3 || minHeight <3) {
		return ;
	}
	if(maxWidth > m_nWidth || maxHeight > m_nHeight) {
		return ;
	}
	srand(time(0));
	int posx = 0;
	int posy = 0;
	int width = 0;
	int height = 0;
	int dw = maxWidth - minWidth;
	int dh = maxHeight - minHeight;
	while( count != 0) 
	{
		posx = rand() % m_nWidth;
		posy = rand() % m_nHeight;
		width = rand() % dw + minWidth;
		height = rand() % dh + minHeight;
		if ( posx + width < m_nWidth && posy + height < m_nHeight) {
			for(int i = posy; i < posy + height; i++)
			{
				if ( rand() % height == 0) {
					m_theMap[i][posx] = 2;
				}
				else {
					m_theMap[i][posx] = 1;
				}
				if ( rand() % height == 0) {
					m_theMap[i][posx+width] = 2;
				}
				else {
					m_theMap[i][posx+width] = 1;
				}
			}
			for(int i = posx; i < posx + width; i++)
			{
				if( rand() % width == 0) {
					m_theMap[posy][i] = 2;
				}
				else {
					m_theMap[posy][i] = 1;
				}

				if( rand() % width == 0) {
					m_theMap[posy+ height][i] = 2;
				}
				else {
					m_theMap[posy+ height][i] = 1;
				}
			}
			m_theMap[posy + height][ posx + width] = 1;
			count--;
		}
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
