#include "Map.h"


C_Map::C_Map()
{

	int testSizeX = 60;
	int testSizeY = 34;

	C_Sprite t(m1::E_SpriteType::Floor);
	

	for (int i = 0; i < testSizeX; ++i)
	{
		for (int o = 0; o < testSizeY; ++o)
		{
			mapTiles.push_back( *new C_Sprite( m1::E_SpriteType::Floor, i * int(t.GetRect().w), o* int(t.GetRect().h) ) );
		}
	}
	
	std::cout << "Number of maptiles: " << mapTiles.size() << std::endl;

}