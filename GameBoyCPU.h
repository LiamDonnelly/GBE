#pragma once
#include <windows.h>

class GameBoyCPU 
{
private:
	const float CLOCK_SPEED = 4.194304;

	// Registers - Left Char is High Bit
	
	USHORT m_AF; // Accumlator/Flag
	USHORT m_BC;
	USHORT m_DE;
	USHORT m_HL;
	USHORT m_StackPointer;
	USHORT m_ProgramCounter;

	//Array to fetch correct operation by code
	typedef byte(GameBoyCPU::* cpuOperation)(const byte& opCode);
	cpuOperation m_cpuOperations[0xff + 1];

	// operation functions

	// 0x
	byte NOP(const byte& opCode); //0x00
	byte LD_BC(const byte& opCode); //0x01
	byte LD_BC_A(const byte& opCode); //0x02
	byte INC_BC(const byte& opCode); //0x03
	byte INC_B(const byte& opCode); //0x04
	byte DEC_B(const byte& opCode); //0x05
	byte LD_B(const byte& opCode); //0x06
	byte RL_CA(const byte& opCode); //0x07
	byte LD_SP(const byte& opCode); //0x08
	byte ADD_HL_BC(const byte& opCode); //0x09
	byte LD_A_BC(const byte& opCode); //0x0A
	byte DEC_BC(const byte& opCode); //0x0B
	byte INC_C(const byte& opCode); //0x0C
	byte DEC_C(const byte& opCode); //0x0D
	byte LD_C(const byte& opCode); //0x0E
	byte RR_CA(const byte& opCode); //0x0F
	
	// 1x
	byte change(const byte& opCode); //0x10
	byte change(const byte& opCode); //0x11
	byte change(const byte& opCode); //0x12
	byte change(const byte& opCode); //0x13
	byte change(const byte& opCode); //0x14
	byte change(const byte& opCode); //0x15
	byte change(const byte& opCode); //0x16
	byte change(const byte& opCode); //0x17
	byte change(const byte& opCode); //0x18
	byte change(const byte& opCode); //0x19
	byte change(const byte& opCode); //0x1A
	byte change(const byte& opCode); //0x1B
	byte change(const byte& opCode); //0x1C
	byte change(const byte& opCode); //0x1D
	byte change(const byte& opCode); //0x1E
	byte change(const byte& opCode); //0x1F

	// 2x
	byte change(const byte& opCode); //0x20
	byte change(const byte& opCode); //0x21
	byte change(const byte& opCode); //0x22
	byte change(const byte& opCode); //0x23
	byte change(const byte& opCode); //0x24
	byte change(const byte& opCode); //0x25
	byte change(const byte& opCode); //0x26
	byte change(const byte& opCode); //0x27
	byte change(const byte& opCode); //0x28
	byte change(const byte& opCode); //0x29
	byte change(const byte& opCode); //0x2A
	byte change(const byte& opCode); //0x2B
	byte change(const byte& opCode); //0x2C
	byte change(const byte& opCode); //0x2D
	byte change(const byte& opCode); //0x2E
	byte change(const byte& opCode); //0x2F

	// 3x
	byte change(const byte& opCode); //0x30
	byte change(const byte& opCode); //0x31
	byte change(const byte& opCode); //0x32
	byte change(const byte& opCode); //0x33
	byte change(const byte& opCode); //0x34
	byte change(const byte& opCode); //0x35
	byte change(const byte& opCode); //0x36
	byte change(const byte& opCode); //0x37
	byte change(const byte& opCode); //0x38
	byte change(const byte& opCode); //0x39
	byte change(const byte& opCode); //0x3A
	byte change(const byte& opCode); //0x3B
	byte change(const byte& opCode); //0x3C
	byte change(const byte& opCode); //0x3D
	byte change(const byte& opCode); //0x3E
	byte change(const byte& opCode); //0x3F

	// 4x
	byte change(const byte& opCode); //0x40
	byte change(const byte& opCode); //0x41
	byte change(const byte& opCode); //0x42
	byte change(const byte& opCode); //0x43
	byte change(const byte& opCode); //0x44
	byte change(const byte& opCode); //0x45
	byte change(const byte& opCode); //0x46
	byte change(const byte& opCode); //0x47
	byte change(const byte& opCode); //0x48
	byte change(const byte& opCode); //0x49
	byte change(const byte& opCode); //0x4A
	byte change(const byte& opCode); //0x4B
	byte change(const byte& opCode); //0x4C
	byte change(const byte& opCode); //0x4D
	byte change(const byte& opCode); //0x4E
	byte change(const byte& opCode); //0x4F

	// 5x
	byte change(const byte& opCode); //0x50
	byte change(const byte& opCode); //0x51
	byte change(const byte& opCode); //0x52
	byte change(const byte& opCode); //0x53
	byte change(const byte& opCode); //0x54
	byte change(const byte& opCode); //0x55
	byte change(const byte& opCode); //0x56
	byte change(const byte& opCode); //0x57
	byte change(const byte& opCode); //0x58
	byte change(const byte& opCode); //0x59
	byte change(const byte& opCode); //0x5A
	byte change(const byte& opCode); //0x5B
	byte change(const byte& opCode); //0x5C
	byte change(const byte& opCode); //0x5D
	byte change(const byte& opCode); //0x5E
	byte change(const byte& opCode); //0x5F

	// 6x
	byte change(const byte& opCode); //0x60
	byte change(const byte& opCode); //0x61
	byte change(const byte& opCode); //0x62
	byte change(const byte& opCode); //0x63
	byte change(const byte& opCode); //0x64
	byte change(const byte& opCode); //0x65
	byte change(const byte& opCode); //0x66
	byte change(const byte& opCode); //0x67
	byte change(const byte& opCode); //0x68
	byte change(const byte& opCode); //0x69
	byte change(const byte& opCode); //0x6A
	byte change(const byte& opCode); //0x6B
	byte change(const byte& opCode); //0x6C
	byte change(const byte& opCode); //0x6D
	byte change(const byte& opCode); //0x6E
	byte change(const byte& opCode); //0x6F

	// 7x
	byte change(const byte& opCode); //0x70
	byte change(const byte& opCode); //0x71
	byte change(const byte& opCode); //0x12
	byte change(const byte& opCode); //0x13
	byte change(const byte& opCode); //0x14
	byte change(const byte& opCode); //0x15
	byte change(const byte& opCode); //0x16
	byte change(const byte& opCode); //0x17
	byte change(const byte& opCode); //0x18
	byte change(const byte& opCode); //0x19
	byte change(const byte& opCode); //0x1A
	byte change(const byte& opCode); //0x1B
	byte change(const byte& opCode); //0x1C
	byte change(const byte& opCode); //0x1D
	byte change(const byte& opCode); //0x1E
	byte change(const byte& opCode); //0x1F

	// 8x
	byte change(const byte& opCode); //0x10
	byte change(const byte& opCode); //0x11
	byte change(const byte& opCode); //0x12
	byte change(const byte& opCode); //0x13
	byte change(const byte& opCode); //0x14
	byte change(const byte& opCode); //0x15
	byte change(const byte& opCode); //0x16
	byte change(const byte& opCode); //0x17
	byte change(const byte& opCode); //0x18
	byte change(const byte& opCode); //0x19
	byte change(const byte& opCode); //0x1A
	byte change(const byte& opCode); //0x1B
	byte change(const byte& opCode); //0x1C
	byte change(const byte& opCode); //0x1D
	byte change(const byte& opCode); //0x1E
	byte change(const byte& opCode); //0x1F

	// 9x
	byte change(const byte& opCode); //0x10
	byte change(const byte& opCode); //0x11
	byte change(const byte& opCode); //0x12
	byte change(const byte& opCode); //0x13
	byte change(const byte& opCode); //0x14
	byte change(const byte& opCode); //0x15
	byte change(const byte& opCode); //0x16
	byte change(const byte& opCode); //0x17
	byte change(const byte& opCode); //0x18
	byte change(const byte& opCode); //0x19
	byte change(const byte& opCode); //0x1A
	byte change(const byte& opCode); //0x1B
	byte change(const byte& opCode); //0x1C
	byte change(const byte& opCode); //0x1D
	byte change(const byte& opCode); //0x1E
	byte change(const byte& opCode); //0x1F

	// Ax
	byte change(const byte& opCode); //0x10
	byte change(const byte& opCode); //0x11
	byte change(const byte& opCode); //0x12
	byte change(const byte& opCode); //0x13
	byte change(const byte& opCode); //0x14
	byte change(const byte& opCode); //0x15
	byte change(const byte& opCode); //0x16
	byte change(const byte& opCode); //0x17
	byte change(const byte& opCode); //0x18
	byte change(const byte& opCode); //0x19
	byte change(const byte& opCode); //0x1A
	byte change(const byte& opCode); //0x1B
	byte change(const byte& opCode); //0x1C
	byte change(const byte& opCode); //0x1D
	byte change(const byte& opCode); //0x1E
	byte change(const byte& opCode); //0x1F

	// Bx
	byte change(const byte& opCode); //0x10
	byte change(const byte& opCode); //0x11
	byte change(const byte& opCode); //0x12
	byte change(const byte& opCode); //0x13
	byte change(const byte& opCode); //0x14
	byte change(const byte& opCode); //0x15
	byte change(const byte& opCode); //0x16
	byte change(const byte& opCode); //0x17
	byte change(const byte& opCode); //0x18
	byte change(const byte& opCode); //0x19
	byte change(const byte& opCode); //0x1A
	byte change(const byte& opCode); //0x1B
	byte change(const byte& opCode); //0x1C
	byte change(const byte& opCode); //0x1D
	byte change(const byte& opCode); //0x1E
	byte change(const byte& opCode); //0x1F

	// 1x
	byte change(const byte& opCode); //0x10
	byte change(const byte& opCode); //0x11
	byte change(const byte& opCode); //0x12
	byte change(const byte& opCode); //0x13
	byte change(const byte& opCode); //0x14
	byte change(const byte& opCode); //0x15
	byte change(const byte& opCode); //0x16
	byte change(const byte& opCode); //0x17
	byte change(const byte& opCode); //0x18
	byte change(const byte& opCode); //0x19
	byte change(const byte& opCode); //0x1A
	byte change(const byte& opCode); //0x1B
	byte change(const byte& opCode); //0x1C
	byte change(const byte& opCode); //0x1D
	byte change(const byte& opCode); //0x1E
	byte change(const byte& opCode); //0x1F

	// Cx
	byte change(const byte& opCode); //0x10
	byte change(const byte& opCode); //0x11
	byte change(const byte& opCode); //0x12
	byte change(const byte& opCode); //0x13
	byte change(const byte& opCode); //0x14
	byte change(const byte& opCode); //0x15
	byte change(const byte& opCode); //0x16
	byte change(const byte& opCode); //0x17
	byte change(const byte& opCode); //0x18
	byte change(const byte& opCode); //0x19
	byte change(const byte& opCode); //0x1A
	byte change(const byte& opCode); //0x1B
	byte change(const byte& opCode); //0x1C
	byte change(const byte& opCode); //0x1D
	byte change(const byte& opCode); //0x1E
	byte change(const byte& opCode); //0x1F

	// Dx
	byte change(const byte& opCode); //0x10
	byte change(const byte& opCode); //0x11
	byte change(const byte& opCode); //0x12
	byte change(const byte& opCode); //0x13
	byte change(const byte& opCode); //0x14
	byte change(const byte& opCode); //0x15
	byte change(const byte& opCode); //0x16
	byte change(const byte& opCode); //0x17
	byte change(const byte& opCode); //0x18
	byte change(const byte& opCode); //0x19
	byte change(const byte& opCode); //0x1A
	byte change(const byte& opCode); //0x1B
	byte change(const byte& opCode); //0x1C
	byte change(const byte& opCode); //0x1D
	byte change(const byte& opCode); //0x1E
	byte change(const byte& opCode); //0x1F

	// Ex
	byte change(const byte& opCode); //0x10
	byte change(const byte& opCode); //0x11
	byte change(const byte& opCode); //0x12
	byte change(const byte& opCode); //0x13
	byte change(const byte& opCode); //0x14
	byte change(const byte& opCode); //0x15
	byte change(const byte& opCode); //0x16
	byte change(const byte& opCode); //0x17
	byte change(const byte& opCode); //0x18
	byte change(const byte& opCode); //0x19
	byte change(const byte& opCode); //0x1A
	byte change(const byte& opCode); //0x1B
	byte change(const byte& opCode); //0x1C
	byte change(const byte& opCode); //0x1D
	byte change(const byte& opCode); //0x1E
	byte change(const byte& opCode); //0x1F

	// Fx
	byte change(const byte& opCode); //0xF0
	byte change(const byte& opCode); //0xF1
	byte change(const byte& opCode); //0xF2
	byte change(const byte& opCode); //0xF3
	byte change(const byte& opCode); //0xF4
	byte change(const byte& opCode); //0xF5
	byte change(const byte& opCode); //0xF6
	byte change(const byte& opCode); //0xF7
	byte change(const byte& opCode); //0xF8
	byte change(const byte& opCode); //0xF9
	byte change(const byte& opCode); //0xFA
	byte change(const byte& opCode); //0xFB
	byte change(const byte& opCode); //0xFC
	byte change(const byte& opCode); //0xFD
	byte change(const byte& opCode); //0xFE
	byte change(const byte& opCode); //0xFF
};

