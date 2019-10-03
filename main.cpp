#include <stdio.h>
#include <string>
#include "GraphicSettings.h"
#include "SDL_Graphics.h"
#include "GameBoyCPU.h"
#include "GameBoyMemory.h"
#include "GameBoy.h"
#undef main

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
std::string WINDOW_TITLE = "GBE";

int main(int argc, char* args) 
{
	GraphicSettings* graphicSettings = new GraphicSettings(SCREEN_WIDTH,SCREEN_HEIGHT, WINDOW_TITLE);
	
	GraphicsBase* graphics = new SDL_Graphics();
	GameBoyMemory* memory = new GameBoyMemory();
	GameBoyCPU* cpu = new GameBoyCPU();
	GameBoy* gameBoy = new GameBoy(cpu, memory);

	graphics->Init(graphicSettings);
	
	gameBoy->Start();

	gameBoy->CleanUp();
	graphics->CleanUp();

	delete memory;
	delete cpu;
	delete gameBoy;
	delete graphicSettings;
	delete graphics;

	return 0;
}