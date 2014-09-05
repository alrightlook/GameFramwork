#include "MapEngine.h"
#include "memory.h"
#include <fstream>
#include <iostream>
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
			fs<<m_theMap[i][j]<<" ";
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
	int index = 0;
	while( count != 0) 
	{
		posx = rand() % m_nWidth;
		posy = rand() % m_nHeight;
		width = rand() % dw + minWidth;
		height = rand() % dh + minHeight;
		if ( posx + width < m_nWidth && posy + height < m_nHeight && CheckOverlap(posx, posy, width, height)) {
			for(int i = posy; i < posy + height; i++)
			{
				m_theMap[i][posx] = 1;
				m_theMap[i][posx+width] = 1;
			}
			for(int i = posx; i < posx + width; i++)
			{
				m_theMap[posy][i] = 1;
				m_theMap[posy+ height][i] = 1;
			}
			m_theMap[posy + height][ posx + width] = 1;
			index++;
			AddRoom(index, posx, posy, width, height);
			count--;
		}
	}
}

bool MapEngine::CheckOverlap(int posx, int posy, int width, int height)
{
	if (m_mapRoom.size() == 0) {
		return true;
	}
	std::map<int, Room>::iterator it;
	int sum = 0;
	for (it  = m_mapRoom.begin(); it != m_mapRoom.end(); it++ )
	{
		Room room = it->second;

		if (posx >= room.posx + room.width) {
			sum++;
		}
		else if ( posx + width <= room.posx) {
			sum++;
		}
		else if (posy + height <= room.posy) {
			sum++;
		}
		else if( posy >= room.posy + room.height) 
		{
			sum++;
		}

	}
	if ( sum  ==  m_mapRoom.size()) {
		return true;
	}
	return false;

}
void MapEngine::AddRoom(int index,int posx, int posy, int width, int height)
{
	Room room;
	room.posx = posx;
	room.posy = posy;
	room.width = width;
	room.height = height;

	m_mapRoom.insert(std::pair<int, Room>(index, room));

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
