#pragma once
#include <string>
class GraphicSettings
{
public:
	GraphicSettings(int width, int height, std::string title);

	int Width;
	int Height;
	std::string WindowTitle;

};

