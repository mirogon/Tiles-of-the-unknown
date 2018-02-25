#pragma once
#include "Map.h"

class C_Game
{
public:

	C_Game();
	~C_Game() = default;

	m1::E_GameState Game_Play();

private:

	m1::C_Timer gameTimer;

	C_Map map;

	void MoveMap();

};

inline m1::E_GameState C_Game::Game_Play()
{

	MoveMap();
	map.RenderMap();

	return m1::E_GameState::GS_Game_Play;
}
inline void C_Game::MoveMap()
{
	static uint64_t lastTime = gameTimer.GetTimeSinceStart_microseconds();
	
	if (m1::KeyIsPressed(SDL_SCANCODE_W))
	{
		map.MoveMap(0, -MOVESPEED * ( gameTimer.GetTimeSinceStart_microseconds() - lastTime ) );
	}

	if (m1::KeyIsPressed(SDL_SCANCODE_S))
	{
		map.MoveMap(0, MOVESPEED * ( gameTimer.GetTimeSinceStart_microseconds() - lastTime) );
	}

	if (m1::KeyIsPressed(SDL_SCANCODE_A))
	{
		map.MoveMap(-MOVESPEED * (gameTimer.GetTimeSinceStart_microseconds() - lastTime), 0);
	}

	if (m1::KeyIsPressed(SDL_SCANCODE_D))
	{
		map.MoveMap(MOVESPEED * (gameTimer.GetTimeSinceStart_microseconds() - lastTime), 0);
	}

	lastTime = gameTimer.GetTimeSinceStart_microseconds();

}