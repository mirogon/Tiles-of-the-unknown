#pragma once
#include "Base.h"

class C_Sprite
{

public:

	C_Sprite() = delete;
	C_Sprite(m1::E_SpriteType, int x = 0, int y = 0);
	virtual ~C_Sprite();

	virtual void Init(m1::E_SpriteType spriteType, int x = 0, int y = 0);

	virtual void Render( int xOffset = 0, int yOffset = 0);
	virtual void Move(const float& xChange, const float& yChange) = delete;

	const m1::double_Rect GetRect()
	{
		return rect;
	}

	static void InitStaticTextures();
	static void DeallocateStaticTextures();
	
protected:
	static SDL_Texture* mapSheet;

	m1::E_SpriteType spriteType;
	m1::double_Rect rect;

	SDL_Texture* currentTexture;
	SDL_Rect renderSrcRect;

	//Functions

};

inline void C_Sprite::Render(int xOffset, int yOffset)
{
	static SDL_Rect dstRect;

	dstRect = { int(rect.x + xOffset), int(rect.y + yOffset), int(rect.w), int(rect.h) };
	
	SDL_RenderCopy(_GetRenderer, currentTexture, &renderSrcRect, &dstRect);
}

/*
inline void C_Sprite::Move(const float& xChange, const float& yChange)
{
	rect.x += xChange;
	rect.y += yChange;
}
*/
