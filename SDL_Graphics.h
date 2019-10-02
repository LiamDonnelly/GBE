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
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
};
