#pragma once
#include "Animation.h"

class C_Player
{

public:

	C_Player();
	~C_Player() = default;

	void Handle();
	void Render();

private:

	m1::double_Rect rect;

	C_Animation currentAnimation;

};

inline void C_Player::Handle()
{
	static Uint32 lastTime = SDL_GetTicks();

	if (m1::KeyIsPressed(SDL_SCANCODE_S) == true)
	{
		if (currentAnimation.GetAnimationType() != m1::E_AnimationType::PlayerWalkDown)
		{
			currentAnimation = *new C_Animation(m1::E_AnimationType::PlayerWalkDown);
		}
		
		if (SDL_GetTicks() - lastTime >= ANIMATIONSPEED_PLAYERWALK)
		{
			currentAnimation.NextFrame();
			lastTime = SDL_GetTicks();
		}
	}
}

inline void C_Player::Render()
{
	currentAnimation.Render(rect.x, rect.y);
}