#pragma once
#include "GraphicsBase.h"
#include <SDL.h>

class SDL_Graphics : public GraphicsBase
{
public:
	virtual int Init(GraphicSettings* settings);
	virtual void Draw();
	virtual void CleanUp();

	~SDL_Graphics();

private:
	SDL_Window* m_window = nullptr;
	SDL_Surface* m_screenSurface = nullptr;
};

