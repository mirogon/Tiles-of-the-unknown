#include "Base.h"

C_Base::C_Base()
{
	SDL_DisplayMode currentDisplayMode;
	SDL_GetCurrentDisplayMode(0, &currentDisplayMode);
	
	SCREEN_RESOLUTION_W = currentDisplayMode.w;
	SCREEN_RESOLUTION_H = currentDisplayMode.h;

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