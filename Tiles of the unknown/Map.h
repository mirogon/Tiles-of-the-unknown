#pragma once
#include "Sprite.h"

class C_Map
{
public:
	C_Map();
	~C_Map() = default;

	void RenderMap();

private:
	std::vector<C_Sprite> mapTiles;
};

inline void C_Map::RenderMap()
{
	for (int i = 0; i < mapTiles.size(); ++i)
	{
		mapTiles.at(i).Render();
		//std::cout << "RenderTile" << std::endl;
	}
	
}