#include "Map.h"


C_Map::C_Map()
{

	int testSizeX = int( SCREEN_RESOLUTION_W / (16 * FLOOR_SCALE)) + 1;
	int testSizeY = int(SCREEN_RESOLUTION_H / (16 * FLOOR_SCALE)) + 1;
	for (int i = 0; i < testSizeX; ++i)
	{
		for (int o = 0; o < testSizeY; ++o)
		{
			mapTiles.push_back(*new C_Sprite(m1::E_SpriteType::floor, i * 16 * FLOOR_SCALE, o * 16 * FLOOR_SCALE));
		}
	}
	
	std::cout << "Number of maptiles: " << mapTiles.size() << std::endl;

}