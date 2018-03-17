#include "Map.h"


C_Map::C_Map()
{

	C_Sprite t(m1::E_SpriteType::Floor1);
	
	mapSizeX = SCREEN_RESOLUTION_W / t.GetRect().w + 1;
	mapSizeY =  SCREEN_RESOLUTION_H / t.GetRect().h + 1;

	std::cout << "Max mapsize: " << mapTiles.max_size() << std::endl;

	for (int i = 0; i < mapSizeY; ++i)
	{
		for (int o = 0; o < mapSizeX; ++o)
		{
			mapTiles.push_back( *new C_Sprite( m1::E_SpriteType::Floor1, o * int(t.GetRect().w), i* int(t.GetRect().h) ) );
		}
	}
	 
	std::cout << "Number of maptiles: " << mapTiles.size() << std::endl;
	std::cout << "First tile x,y,w,h " << mapTiles[0].GetRect().x << " " << mapTiles[0].GetRect().y << " " << mapTiles[0].GetRect().w << " " << mapTiles[0].GetRect().h << std::endl;

}