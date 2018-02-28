#include "Map.h"


C_Map::C_Map()
{

	mapSizeX = 100;
	mapSizeY = 100;

	C_Sprite t(m1::E_SpriteType::Floor);
	

	for (int i = 0; i < mapSizeY; ++i)
	{
		for (int o = 0; o < mapSizeX; ++o)
		{
			mapTiles.push_back( *new C_Sprite( m1::E_SpriteType::Floor, o * int(t.GetRect().w), i* int(t.GetRect().h) ) );
		}
	}
	
	std::cout << "Number of maptiles: " << mapTiles.size() << std::endl;

}