#pragma once
#include "Player.h"

class C_Map
{
public:
	C_Map();
	~C_Map() = default;

	void RenderMap(const float& cameraPosX = 0, const float& cameraPosY = 0);
	void MoveMap(const float& xChange, const float& yChange) = delete;

private:
	std::vector<C_Sprite> mapTiles;
	uint16_t mapSizeX;
	uint16_t mapSizeY;
};

inline void C_Map::RenderMap(const float& cameraPosX, const float& cameraPosY)
{
	//std::cout << "First tile coor X: " << int(mapTiles[0].GetRect().x )<< " Y: " << int( mapTiles[0].GetRect().y) << std::endl;
	static int mapOffsetX;
	static int mapOffsetY;
	static int mapOffsetXTiles;
	static int mapOffsetYTiles;
	static int upperLeftRenderTileIndex;

	mapOffsetX = -cameraPosX;
	mapOffsetY = -cameraPosY;
	mapOffsetXTiles = mapOffsetX / mapTiles.at(0).GetRect().w;
	mapOffsetYTiles = mapOffsetY / mapTiles.at(0).GetRect().h;
	upperLeftRenderTileIndex = mapSizeX * mapOffsetYTiles + mapOffsetXTiles;

	for (int i = upperLeftRenderTileIndex; i < upperLeftRenderTileIndex + (SCREEN_RESOLUTION_W / mapTiles.at(0).GetRect().w) + 1; ++i)
	{
		for (int o = i; o < i + mapSizeX * ( (SCREEN_RESOLUTION_H / mapTiles.at(0).GetRect().h) +2 ); o += mapSizeX)
		{
			if (o < mapTiles.size())
			{
				mapTiles.at(o).Render(cameraPosX, cameraPosY);
			}
			
		}
	}

}

/*
inline void C_Map::MoveMap(const float& xChange, const float& yChange)
{
	for (int i = 0; i < mapTiles.size(); ++i)
	{
		mapTiles.at(i).Move(xChange, yChange);
	}
}
*/