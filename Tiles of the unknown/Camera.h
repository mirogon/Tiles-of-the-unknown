#pragma once
#include "Map.h"

class C_Camera
{

public:

	C_Camera();
	~C_Camera() = default;

	void SetPosition(const float& x, const float& y);
	void Move(const float& xChange, const float& yChange);

	m1::double_Rect GetRect()
	{
		return rect;
	}

private:

	m1::double_Rect rect;

};

inline void C_Camera::Move(const float& xChange, const float& yChange)
{
	rect.x += xChange;
	rect.y += yChange;
}