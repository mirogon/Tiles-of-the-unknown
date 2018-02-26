#include "Animation.h"


C_Animation::C_Animation(m1::E_AnimationType type)
{

	currentFrame = 0;

	animationType = type;
	switch (animationType)
	{
	case m1::E_AnimationType::PlayerWalkDown:
		frameWidth = round( 16 * PLAYER_SCALE * RESOLUTION_SCALE_W );
		frameHeight = round(16 * PLAYER_SCALE * RESOLUTION_SCALE_H );
		animationLength = ANIMATIONLENGTH_PLAYERWALKDOWN;
		renderFunction = &C_Animation::RenderPlayer;
		break;
	}

}

void C_Animation::InitStaticAnimations()
{
	SDL_Surface* surface = IMG_Load(PLAYERWALKDOWNSHEETPATH);

	if (surface == nullptr)
	{
		throw "Surface could not be intialized (InitStaticAnimations)";
	}

	SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 255, 255));

	playerAnimation = SDL_CreateTextureFromSurface(_GetRenderer, surface);

	if (playerAnimation == nullptr)
	{
		throw "playerAnimation texture could not be intialized (InitStaticAnimations)";
	}

	SDL_FreeSurface(surface);
	surface = nullptr;
}

void C_Animation::DeallocateStaticAnimations()
{
	SDL_DestroyTexture(playerAnimation);
	playerAnimation = nullptr;
}

SDL_Texture* C_Animation::playerAnimation = nullptr;