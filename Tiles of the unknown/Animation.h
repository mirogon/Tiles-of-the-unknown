#pragma once
#include "Sprite.h"

class C_Animation
{

public:

	C_Animation() = delete;
	C_Animation(m1::E_AnimationType type);
	~C_Animation() = default;


	void Render(const int x, const int y);
	void NextFrame();
	void SetFrame(uint8_t frame);

	m1::E_AnimationType GetAnimationType()
	{
		return animationType;
	}

	static void InitStaticAnimations();
	static void DeallocateStaticAnimations();


private:
	m1::E_AnimationType animationType;
	int frameWidth;
	int frameHeight;
	void(C_Animation::*renderFunction)(int x, int y);
	static SDL_Texture* playerAnimation;
	uint8_t animationLength;
	uint8_t currentFrame;

	//FUNCTIONS
	void RenderPlayer(int x, int y);

};

inline void C_Animation::Render(const int x, const int y)
{
	(this->*renderFunction)(x, y);
}

inline void C_Animation::NextFrame()
{
	++currentFrame;
	if (currentFrame >= animationLength)
	{
		currentFrame = 0;
	}
}

inline void C_Animation::SetFrame(uint8_t frame)
{
	currentFrame = frame;
	if (currentFrame >= animationLength)
	{
		std::cout << "Frame was set further than possible!" << std::endl;
		currentFrame = 0;
	}
}

inline void C_Animation::RenderPlayer(int x, int y)
{
	static SDL_Rect srcRect;
	static SDL_Rect dstRect;

	srcRect = { currentFrame * 16 ,0, 16, 16 };
	dstRect = { x, y, frameWidth, frameHeight };

	SDL_RenderCopy(_GetRenderer, playerAnimation, &srcRect, &dstRect);
}
