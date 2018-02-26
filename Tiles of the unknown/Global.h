#pragma once


#define WIN7BUILD

#ifdef WIN7BUILD

	#define WINVER 0x0601
	#define _WIN32_WINNT 0x0601

#endif

#include <sdkddkver.h>

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

//General
extern const char* WINDOWNAME;
extern int SCREEN_RESOLUTION_W;
extern int SCREEN_RESOLUTION_H;

extern float RESOLUTION_SCALE_W;
extern float RESOLUTION_SCALE_H;

//Game
extern float MOVESPEED_W;
extern float MOVESPEED_H;

extern int ANIMATIONSPEED_PLAYERWALK;
extern const uint8_t ANIMATIONLENGTH_PLAYERWALKDOWN;

//PATHS
extern const char* MAPSHEETPATH;
extern const char* PLAYERWALKDOWNSHEETPATH;

//SCALES
extern float FLOOR_SCALE;
extern float PLAYER_SCALE;


namespace m1
{
	enum E_CollisionDirection { Left = 0, Right = 1, Bot = 2, Top = 3, None = 4 };

	enum E_GameState { GS_None = 0, GS_Game_Play = 1, GS_Game_Over = 2, GS_Game_Menu = 3, };

	enum E_SpriteType { Floor = 0};
	enum E_AnimationType { PlayerWalkDown = 0 };

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

	//CHECK IF THE KEY WITH THE SCANCODE scancode IS PRESSED
	inline bool KeyIsPressed(SDL_Scancode scancode)
	{
		static const Uint8* keyStatus = SDL_GetKeyboardState(NULL);
		keyStatus = SDL_GetKeyboardState(NULL);

		if (keyStatus[scancode] == 1)
		{
			return true;
		}

		else
		{
			return false;
		}

	}

}