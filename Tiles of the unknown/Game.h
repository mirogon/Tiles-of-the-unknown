#pragma once
#include "Map.h"

class C_Game
{
public:

	C_Game();
	~C_Game() = default;

	m1::E_GameState Game_Play();

private:

	C_Map testMap;
	C_Sprite testSprite;
};

inline m1::E_GameState C_Game::Game_Play()
{
	testMap.RenderMap();
	//testSprite.Render();
	return m1::E_GameState::GS_Game_Play;
}