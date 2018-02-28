#include "Sprite.h"

C_Sprite::C_Sprite(m1::E_SpriteType s, int x, int y )
{
	rect.x = x;
	rect.y = y;

	spriteType = s;

	currentTexture = nullptr;

	switch (spriteType)
	{
	case m1::E_SpriteType::Floor1:
		rect.w = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_W);
		rect.h = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_H);
		renderSrcRect.x = 0;
		renderSrcRect.y = 0;
		renderSrcRect.w = 8;
		renderSrcRect.h = 8;
		currentTexture = mapSheet;
		break;

	case m1::E_SpriteType::Floor2:
		rect.w = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_W);
		rect.h = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_H);
		renderSrcRect.x = 8;
		renderSrcRect.y = 0;
		renderSrcRect.w = 8;
		renderSrcRect.h = 8;
		currentTexture = mapSheet;
		break;

	case m1::E_SpriteType::Floor3:
		rect.w = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_W);
		rect.h = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_H);
		renderSrcRect.x = 16;
		renderSrcRect.y = 0;
		renderSrcRect.w = 8;
		renderSrcRect.h = 8;
		currentTexture = mapSheet;
		break;

	case m1::E_SpriteType::Floor4:
		rect.w = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_W);
		rect.h = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_H);
		renderSrcRect.x = 24;
		renderSrcRect.y = 0;
		renderSrcRect.w = 8;
		renderSrcRect.h = 8;
		currentTexture = mapSheet;
		break;

	case m1::E_SpriteType::Floor5:
		rect.w = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_W);
		rect.h = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_H);
		renderSrcRect.x = 32;
		renderSrcRect.y = 0;
		renderSrcRect.w = 8;
		renderSrcRect.h = 8;
		currentTexture = mapSheet;
		break;

	default:
		std::cout << "Spritetype could not be found (C_Sprite)" << std::endl;
		break;
	}

}

C_Sprite::~C_Sprite()
{
	//SDL_DestroyTexture(currentTexture);
	//currentTexture = nullptr;
}

void C_Sprite::Init(m1::E_SpriteType s, int x, int y)
{

	rect.x = x;
	rect.y = y;

	spriteType = s;

	currentTexture = nullptr;

	switch (spriteType)
	{
	case m1::E_SpriteType::Floor1:
		rect.w = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_W);
		rect.h = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_H);
		renderSrcRect.x = 0;
		renderSrcRect.y = 0;
		renderSrcRect.w = 8;
		renderSrcRect.h = 8;
		currentTexture = mapSheet;
		if (currentTexture == nullptr)
		{
			throw "Floor1 could not be intialized";
		}
		break;

	case m1::E_SpriteType::Floor2:
		rect.w = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_W);
		rect.h = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_H);
		renderSrcRect.x = 8;
		renderSrcRect.y = 0;
		renderSrcRect.w = 8;
		renderSrcRect.h = 8;
		currentTexture = mapSheet;
		break;

	case m1::E_SpriteType::Floor3:
		rect.w = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_W);
		rect.h = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_H);
		renderSrcRect.x = 16;
		renderSrcRect.y = 0;
		renderSrcRect.w = 8;
		renderSrcRect.h = 8;
		currentTexture = mapSheet;
		break;

	case m1::E_SpriteType::Floor4:
		rect.w = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_W);
		rect.h = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_H);
		renderSrcRect.x = 24;
		renderSrcRect.y = 0;
		renderSrcRect.w = 8;
		renderSrcRect.h = 8;
		currentTexture = mapSheet;
		break;

	case m1::E_SpriteType::Floor5:
		rect.w = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_W);
		rect.h = round(float(8) * FLOOR_SCALE * RESOLUTION_SCALE_H);
		renderSrcRect.x = 32;
		renderSrcRect.y = 0;
		renderSrcRect.w = 8;
		renderSrcRect.h = 8;
		currentTexture = mapSheet;
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