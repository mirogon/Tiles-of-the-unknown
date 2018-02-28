#include "Map.h"


C_Map::C_Map()
{

	C_Sprite t(m1::E_SpriteType::Floor);
	
	mapSizeX = 1000; //SCREEN_RESOLUTION_W / t.GetRect().w + 1;
	mapSizeY = 5000;//SCREEN_RESOLUTION_H / t.GetRect().h + 1;

	std::cout << "Max mapsize: " << mapTiles.max_size() << std::endl;

	for (int i = 0; i < mapSizeY; ++i)
	{
		for (int o = 0; o < mapSizeX; ++o)
		{
			mapTiles.push_back( *new C_Sprite( m1::E_SpriteType::Floor, o * int(t.GetRect().w), i* int(t.GetRect().h) ) );
		}
	}
	 
	std::cout << "Number of maptiles: " << mapTiles.size() << std::endl;

}