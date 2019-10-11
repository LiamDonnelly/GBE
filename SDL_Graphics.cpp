#include "SDL_Graphics.h"

SDL_Graphics::~SDL_Graphics()
{
	CleanUp();
}

int SDL_Graphics::Init(GraphicSettings* settings) 
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}
	else
	{
		//Create window
		m_window = SDL_CreateWindow(settings->WindowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, settings->Width, settings->Height, SDL_WINDOW_SHOWN);
		if (m_window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return -1;
		}
		else
		{
			//Get window surface
			m_screenSurface = SDL_GetWindowSurface(m_window);

			//Fill the surface white
			SDL_FillRect(m_screenSurface, NULL, SDL_MapRGB(m_screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(m_window);

			//Wait two seconds
			SDL_Delay(2000);
		}
	}

	return 0;
}

void SDL_Graphics::Draw() 
{
	
}

void SDL_Graphics::CleanUp()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();

	m_window = NULL;
	m_screenSurface = NULL;
}