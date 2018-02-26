#include "Sprite.h"

C_Sprite::C_Sprite(m1::E_SpriteType s, int x, int y )
{

	rect.x = x;
	rect.y = y;

	spriteType = s;

	switch (spriteType)
	{
	case m1::E_SpriteType::Floor:
		rect.w = 16 * FLOOR_SCALE * RESOLUTION_SCALE_W;
		rect.h = 16 * FLOOR_SCALE * RESOLUTION_SCALE_H;
		renderFunction = &C_Sprite::RenderFloor;
		break;

	default:
		std::cout << "Spritetype could not be found (C_Sprite)" << std::endl;
		break;
	}

}

C_Sprite::~C_Sprite()
{

}

void C_Sprite::Init(m1::E_SpriteType s, int x, int y)
{
	rect.x = x;
	rect.y = y;

	spriteType = s;

	switch (spriteType)
	{
	case m1::E_SpriteType::Floor:
		rect.w = 16 * FLOOR_SCALE * RESOLUTION_SCALE_W;
		rect.h = 16 * FLOOR_SCALE * RESOLUTION_SCALE_H;
		renderFunction = &C_Sprite::RenderFloor;
		break;

	default:
		std::cout << "Spritetype could not be found (C_Sprite)" << std::endl;
		break;
	}

}

void C_Sprite::InitStaticTextures()
{
	SDL_Surface* surface = IMG_Load(MAPSHEETPATH);
	
	if (surface == nullptr)
	{
		throw "Surface could not be intialized (InitStaticTextures)";
	}
	
	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB( surface->format, 0, 255, 255 ) );

	mapSheet = SDL_CreateTextureFromSurface(_GetRenderer, surface);

	if (mapSheet == nullptr)
	{
		throw "mapSheet texture could not be intialized (InitStaticTextures)";
	}

	SDL_FreeSurface(surface);
	surface = nullptr;

}

void C_Sprite::DeallocateStaticTextures()
{
	SDL_DestroyTexture(mapSheet);
	mapSheet = nullptr;
}

SDL_Texture* C_Sprite::mapSheet = nullptr;