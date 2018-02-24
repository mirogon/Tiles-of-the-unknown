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

	static void InitStaticTextures();
	static void DeallocateStaticTextures();
	
private:
	static SDL_Texture* mapSheet;
	std::function<void()> renderFunction;
	m1::E_SpriteType spriteType;
	m1::double_Rect rect;

	//Functions
	void RenderFloor();

};

inline void C_Sprite::Render()
{
	renderFunction();
}

inline void C_Sprite::RenderFloor()
{
	static SDL_Rect srcRect;
	static SDL_Rect dstRect;

	srcRect = { 0,0, 16, 16 };
	dstRect = { int(rect.x), int(rect.y), int(rect.w), int(rect.h)};

	SDL_RenderCopy(_GetRenderer, mapSheet, &srcRect, &dstRect);
}