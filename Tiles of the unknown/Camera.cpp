#include "Camera.h"


C_Camera::C_Camera()
{
	rect.x = 0;
	rect.y = 0;
	rect.w = SCREEN_RESOLUTION_W;
	rect.h = SCREEN_RESOLUTION_H;
}

void C_Camera::SetPosition(const float& x, const float& y)
{
	rect.x = x;
	rect.y = y;
}