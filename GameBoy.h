#pragma once
#include "GameBoyCPU.h"
#include "GameBoyMemory.h"

class GameBoy
{
public:
	GameBoy(GameBoyCPU* cpu, GameBoyMemory* memory);
	~GameBoy();

	void Start();
	void CleanUp();

private:
	GameBoyCPU* m_Cpu = nullptr;
	GameBoyMemory* m_Memory = nullptr;
};

