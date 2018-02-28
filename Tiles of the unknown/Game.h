#pragma once
#include "Camera.h"

class C_Game
{
public:

	C_Game();
	~C_Game() = default;

	m1::E_GameState Game_Play();

private:

	C_Camera gameCamera;
	m1::C_Timer gameTimer;

	C_Player player;

	C_Map map;

	void MoveCamera(const uint64_t& deltaTime);

};

inline m1::E_GameState C_Game::Game_Play()
{
	static m1::C_DeltaTimer_Microseconds moveMapTimer;

	MoveCamera(moveMapTimer.GetDeltaTime());

	map.RenderMap(gameCamera.GetRect().x, gameCamera.GetRect().y);

	player.Handle();
	player.Render();

	return m1::E_GameState::GS_Game_Play;
}
inline void C_Game::MoveCamera(const uint64_t& deltaTime)
{
	
	if (m1::KeyIsPressed(SDL_SCANCODE_W))
	{
		gameCamera.Move(0, MOVESPEED_H * deltaTime);
	}

	if (m1::KeyIsPressed(SDL_SCANCODE_S))
	{
		gameCamera.Move(0, -MOVESPEED_H * deltaTime);
	}

	if (m1::KeyIsPressed(SDL_SCANCODE_A))
	{
		gameCamera.Move(MOVESPEED_W * deltaTime, 0);
	}

	if (m1::KeyIsPressed(SDL_SCANCODE_D))
	{
		gameCamera.Move(-MOVESPEED_W * deltaTime, 0);
	}

}