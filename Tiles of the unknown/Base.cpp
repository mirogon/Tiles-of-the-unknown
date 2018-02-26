#include "Base.h"

C_Base::C_Base()
{
	SDL_DisplayMode currentDisplayMode;
	SDL_GetCurrentDisplayMode(0, &currentDisplayMode);
	
	SCREEN_RESOLUTION_W = currentDisplayMode.w;
	SCREEN_RESOLUTION_H = currentDisplayMode.h;

	

	if (SCREEN_RESOLUTION_W == 1920 && SCREEN_RESOLUTION_H == 1080)
	{
		RESOLUTION_SCALE_W = 1;
		RESOLUTION_SCALE_H = 1;
	}
	else
	{
		RESOLUTION_SCALE_W =  float(SCREEN_RESOLUTION_W) / float(1920);
		RESOLUTION_SCALE_H = float(SCREEN_RESOLUTION_H) / float(1080);
	}

	MOVESPEED_H *= RESOLUTION_SCALE_H;
	MOVESPEED_W *= RESOLUTION_SCALE_W;

	std::cout << "RESOLUTION: " << SCREEN_RESOLUTION_W << "x" << SCREEN_RESOLUTION_H << std::endl;
	std::cout << "RESOLUTION SCALE: " << RESOLUTION_SCALE_W << "x" << RESOLUTION_SCALE_H << std::endl;

	std::cout << "MOVESPEED_W = " << MOVESPEED_W << " MOVESPEED_H = " << MOVESPEED_H << std::endl;

	mainWindow = SDL_CreateWindow(WINDOWNAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, currentDisplayMode.w, currentDisplayMode.h, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
	mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED );

	SDL_SetRenderDrawColor(mainRenderer, 0x00, 0x00, 0x00, 0xFF);
	//randomGenerator = m1::C_Random();
}
C_Base::~C_Base()
{
	SDL_DestroyWindow(mainWindow);
	mainWindow = nullptr;
	SDL_DestroyRenderer(mainRenderer);
	mainRenderer = nullptr;
}