#include "Game.h"

#undef main

void ReadConfig();

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();

	try 
	
	{

		ReadConfig();

		//Create static base instance
		C_Base::GetInstance();

		C_Sprite::InitStaticTextures();
		C_Animation::InitStaticAnimations();

		C_Game mainGame;
		m1::E_GameState currentGameState = m1::GS_Game_Play;

		bool quitGame = false;

		SDL_Event mainEvent;

		while (quitGame == false)
		{
			while (SDL_PollEvent(&mainEvent) != 0)
			{
				if (mainEvent.type == SDL_QUIT)
				{
					quitGame = true;
				}
				if (mainEvent.type == SDL_KEYDOWN)
				{
					if (mainEvent.key.keysym.sym == SDLK_ESCAPE)
					{
						quitGame = true;
					}
				}
			}

			SDL_RenderClear(_GetRenderer);

			switch (currentGameState)
			{
			case m1::GS_Game_Play:
				mainGame.Game_Play();
				break;

			}

			SDL_RenderPresent(_GetRenderer);

			//Calculate and show fps
			static Uint32 lastTime = SDL_GetTicks();
			static short fps = 0;
			++fps;
			if (SDL_GetTicks() - lastTime >= 1000)
			{
				std::cout << "FPS: " << fps <<std::endl;
				lastTime = SDL_GetTicks();
				fps = 0;
			}


		}

	}

	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	catch (std::string& e)
	{
		std::cout << "Error: " << e << std::endl;
	}


	C_Sprite::DeallocateStaticTextures();
	C_Sprite::DeallocateStaticTextures();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	return 0;
}

void ReadConfig()
{
	if (m1::ReadConfig("developement_config.m1cfg", "PLAYER_SCALE", PLAYER_SCALE) == false)
	{
		std::cout << "Could not find a value for PLAYER_SCALE in developement_config.m1cfg" << std::endl;
	}
	if (m1::ReadConfig("developement_config.m1cfg", "FLOOR_SCALE", FLOOR_SCALE) == false)
	{
		std::cout << "Could not find a value for FLOOR_SCALE in developement_config.m1cfg" << std::endl;
	}
	if (m1::ReadConfig("developement_config.m1cfg", "ANIMATIONSPEED_PLAYERWALK", ANIMATIONSPEED_PLAYERWALK) == false)
	{
		std::cout << "Could not find a value for ANIMATIONSPEED_PLAYERWALK in developement_config.m1cfg" << std::endl;
	}
}