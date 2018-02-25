#pragma once
#include "Sprite.h"

class C_Map
{
public:
	C_Map();
	~C_Map() = default;

	void RenderMap();
	void MoveMap(const float& xChange, const float& yChange);

private:
	std::vector<C_Sprite> mapTiles;
};

inline void C_Map::RenderMap()
{
	//std::cout << "First tile coor X: " << int(mapTiles[0].GetRect().x )<< " Y: " << int( mapTiles[0].GetRect().y) << std::endl;

	for (int i = 0; i < mapTiles.size(); ++i)
	{
		mapTiles.at(i).Render();
	}
	
}

inline void C_Map::MoveMap(const float& xChange, const float& yChange)
{
	for (int i = 0; i < mapTiles.size(); ++i)
	{
		mapTiles.at(i).Move(xChange, yChange);
	}
}