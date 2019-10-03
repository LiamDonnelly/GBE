#include "GameBoy.h"


GameBoy::GameBoy(GameBoyCPU* cpu, GameBoyMemory* memory)
{
	m_Cpu = cpu;
	m_Memory = memory;
}

GameBoy::~GameBoy()
{
}

void GameBoy::CleanUp()
{
	m_Cpu = nullptr;
	m_Memory = nullptr;
}
