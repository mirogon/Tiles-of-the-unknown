#include "Player.h"

C_Player::C_Player() :
	currentAnimation{ m1::E_AnimationType::PlayerWalkDown }
{
	rect.w = round(16 * PLAYER_SCALE * RESOLUTION_SCALE_W);
	rect.h = round(16 * PLAYER_SCALE * RESOLUTION_SCALE_H);

	rect.x = SCREEN_RESOLUTION_W / 2 - (rect.w / 2);
	rect.y = SCREEN_RESOLUTION_H / 2 - (rect.h / 2);
}