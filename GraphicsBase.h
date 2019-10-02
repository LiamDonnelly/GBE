#pragma once
#include "GraphicSettings.h"

class GraphicsBase
{
public:
	virtual int Init(GraphicSettings* settings) = 0;
	virtual void Draw() = 0;
	virtual void CleanUp() = 0;
};

