#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <array>
#include <sstream>
#include <fstream>
#include <functional>
#include <M1Random.h>
#include <M1Timer.h>

extern const char* WINDOWNAME;
extern int SCREEN_RESOLUTION_W;
extern int SCREEN_RESOLUTION_H;

extern const char* MAPSHEETPATH;

extern float FLOOR_SCALE;

namespace m1
{
	enum E_CollisionDirection { Left = 0, Right = 1, Bot = 2, Top = 3, None = 4 };

	enum E_GameState { GS_None = 0, GS_Game_Play = 1, GS_Game_Over = 2, GS_Game_Menu = 3, };

	enum E_SpriteType { floor = 0 };

	struct double_Rect {

		double x;
		double y;
		int w;
		int h;

		double_Rect() : x(0), y(0), w(0), h(0)
		{}

		double_Rect(double x_, double y_, int w_, int h_) : x{ x_ }, y{ y_ }, w{ w_ }, h{ h_ }
		{}

		static int GetCenterX(const double_Rect& a)
		{
			return a.x + a.w / 2;
		}
		static int GetCenterY(const double_Rect& a)
		{
			return a.y + a.h / 2;
		}
	};

}