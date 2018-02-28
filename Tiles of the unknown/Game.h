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

	C_Player player;
	C_Map map;

	void MoveMap(const uint64_t& deltaTime);

};

inline m1::E_GameState C_Game::Game_Play()
{
	static uint64_t lastTime = gameTimer.GetTimeSinceStart_microseconds();

	MoveMap(gameTimer.GetTimeSinceStart_microseconds() - lastTime);
	map.RenderMap();

	player.Handle();
	player.Render();

	lastTime = gameTimer.GetTimeSinceStart_microseconds();

	return m1::E_GameState::GS_Game_Play;
}
inline void C_Game::MoveMap(const uint64_t& deltaTime)
{
	
	if (m1::KeyIsPressed(SDL_SCANCODE_W))
	{
		map.MoveMap(0, MOVESPEED_H * deltaTime  );
	}

	if (m1::KeyIsPressed(SDL_SCANCODE_S))
	{
		map.MoveMap(0, -MOVESPEED_H * deltaTime );
	}

	if (m1::KeyIsPressed(SDL_SCANCODE_A))
	{
		map.MoveMap(MOVESPEED_W * deltaTime, 0);
	}

	if (m1::KeyIsPressed(SDL_SCANCODE_D))
	{
		map.MoveMap(-MOVESPEED_W * deltaTime, 0);
	}

}