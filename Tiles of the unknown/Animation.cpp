#include "Animation.h"

SDL_Texture* InitSDL_Texture(const char* path);

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
		renderFunction = &C_Animation::RenderPlayerWalkDown;
		break;
	case m1::E_AnimationType::PlayerWalkUp:
		frameWidth = round(16 * PLAYER_SCALE * RESOLUTION_SCALE_W);
		frameHeight = round(16 * PLAYER_SCALE * RESOLUTION_SCALE_H);
		animationLength = ANIMATIONLENGTH_PLAYERWALKDOWN;
		renderFunction = &C_Animation::RenderPlayerWalkUp;
		break;
	case m1::E_AnimationType::PlayerWalkLeft:
		frameWidth = round(16 * PLAYER_SCALE * RESOLUTION_SCALE_W);
		frameHeight = round(16 * PLAYER_SCALE * RESOLUTION_SCALE_H);
		animationLength = ANIMATIONLENGTH_PLAYERWALKDOWN;
		renderFunction = &C_Animation::RenderPlayerWalkLeft;
		break;
	case m1::E_AnimationType::PlayerWalkRight:
		frameWidth = round(16 * PLAYER_SCALE * RESOLUTION_SCALE_W);
		frameHeight = round(16 * PLAYER_SCALE * RESOLUTION_SCALE_H);
		animationLength = ANIMATIONLENGTH_PLAYERWALKDOWN;
		renderFunction = &C_Animation::RenderPlayerWalkRight;
		break;
	}

}

void C_Animation::InitStaticAnimations()
{
	playerWalkDownAnimation = InitSDL_Texture(PLAYERWALKDOWNSHEETPATH);
	playerWalkUpAnimation =  InitSDL_Texture(PLAYERWALKUPSHEETPATH);
	playerWalkRightAnimation = InitSDL_Texture(PLAYERWALKRIGHTSHEETPATH);
	playerWalkLeftAnimation = InitSDL_Texture(PLAYERWALKLEFTSHEETPATH);
}

void C_Animation::DeallocateStaticAnimations()
{
	SDL_DestroyTexture(playerWalkDownAnimation);
	playerWalkDownAnimation = nullptr;

	SDL_DestroyTexture(playerWalkUpAnimation);
	playerWalkUpAnimation = nullptr;

	SDL_DestroyTexture(playerWalkRightAnimation);
	playerWalkRightAnimation = nullptr;

	SDL_DestroyTexture(playerWalkLeftAnimation);
	playerWalkLeftAnimation = nullptr;
}

SDL_Texture* InitSDL_Texture(const char* path)
{
	SDL_Surface surface = *IMG_Load(path);

	/*if (surface == nullptr)
	{
		throw "Surface could not be intialized (InitSDL_Texture)";
	}*/

	SDL_SetColorKey(&surface, SDL_TRUE, SDL_MapRGB(surface.format, 0, 255, 255));

	return SDL_CreateTextureFromSurface(_GetRenderer, &surface);

}

SDL_Texture* C_Animation::playerWalkDownAnimation = nullptr;
SDL_Texture* C_Animation::playerWalkUpAnimation = nullptr;
SDL_Texture* C_Animation::playerWalkRightAnimation = nullptr;
SDL_Texture* C_Animation::playerWalkLeftAnimation = nullptr;