#pragma once
#include "Base.h"

class C_Sprite
{

public:

	C_Sprite() = delete;
	C_Sprite(m1::E_SpriteType, int x = 0, int y = 0);
	virtual ~C_Sprite();

	void InitSprite(m1::E_SpriteType spriteType, int x = 0, int y = 0);

	virtual void Render( );
	virtual void Move(const float& xChange, const float& yChange);

	const m1::double_Rect GetRect()
	{
		return rect;
	}

	static void InitStaticTextures();
	static void DeallocateStaticTextures();
	
private:
	static SDL_Texture* mapSheet;
	void(C_Sprite::*renderFunction)();
	m1::E_SpriteType spriteType;
	m1::double_Rect rect;

	//Functions
	void RenderFloor();

};

inline void C_Sprite::Render()
{
	(this->*renderFunction)();
}

inline void C_Sprite::Move(const float& xChange, const float& yChange)
{
	rect.x += xChange;
	rect.y += yChange;
}

inline void C_Sprite::RenderFloor()
{
	static SDL_Rect srcRect;
	static SDL_Rect dstRect;

	srcRect = { 0,0, 16, 16 };
	dstRect = { int(rect.x), int(rect.y), int(rect.w), int(rect.h)};
	
	SDL_RenderCopy(_GetRenderer, mapSheet, &srcRect, &dstRect);
}