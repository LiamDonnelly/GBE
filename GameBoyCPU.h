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
	byte STOP(const byte& opCode); //0x10
	byte LD_DE(const byte& opCode); //0x11
	byte LD_DE_A(const byte& opCode); //0x12
	byte INC_DE(const byte& opCode); //0x13
	byte INC_D(const byte& opCode); //0x14
	byte DEC_D(const byte& opCode); //0x15
	byte LD_D(const byte& opCode); //0x16
	byte RL_A(const byte& opCode); //0x17
	byte JR(const byte& opCode); //0x18
	byte ADD_HL_DE(const byte& opCode); //0x19
	byte LD_A_DE(const byte& opCode); //0x1A
	byte DEC_DE(const byte& opCode); //0x1B
	byte INC_E(const byte& opCode); //0x1C
	byte DEC_E(const byte& opCode); //0x1D
	byte LD_£(const byte& opCode); //0x1E
	byte RR_A(const byte& opCode); //0x1F

	// 2x
	byte JR_NZ(const byte& opCode); //0x20
	byte LD_HL(const byte& opCode); //0x21
	byte LD_HL_A(const byte& opCode); //0x22
	byte INC_HL(const byte& opCode); //0x23
	byte INC_H(const byte& opCode); //0x24
	byte DEC_H(const byte& opCode); //0x25
	byte LD_H(const byte& opCode); //0x26
	byte DAA(const byte& opCode); //0x27
	byte JR_Z(const byte& opCode); //0x28
	byte ADD_HL_HL(const byte& opCode); //0x29
	byte LD_A_HL(const byte& opCode); //0x2A
	byte DEC_HL(const byte& opCode); //0x2B
	byte INC_L(const byte& opCode); //0x2C
	byte DEC_L(const byte& opCode); //0x2D
	byte LD_L(const byte& opCode); //0x2E
	byte CPL(const byte& opCode); //0x2F

	// 3x
	byte JR_NC(const byte& opCode); //0x30
	byte LD_SP(const byte& opCode); //0x31
	byte LD_HL_A(const byte& opCode); //0x32
	byte INC_SP(const byte& opCode); //0x33
	byte INC_HL(const byte& opCode); //0x34
	byte DEC_HL(const byte& opCode); //0x35
	byte LD_HL(const byte& opCode); //0x36
	byte SCF(const byte& opCode); //0x37
	byte JR_C(const byte& opCode); //0x38
	byte ADD_HL_SP(const byte& opCode); //0x39
	byte LD_A_HL(const byte& opCode); //0x3A
	byte DEC_SP(const byte& opCode); //0x3B
	byte INC_A(const byte& opCode); //0x3C
	byte DEC_A(const byte& opCode); //0x3D
	byte LD_A(const byte& opCode); //0x3E
	byte CCF(const byte& opCode); //0x3F

	// 4x
	byte LD_B_B(const byte& opCode); //0x40
	byte LD_B_C(const byte& opCode); //0x41
	byte LD_B_D(const byte& opCode); //0x42
	byte LD_B_E(const byte& opCode); //0x43
	byte LD_B_H(const byte& opCode); //0x44
	byte LD_B_L(const byte& opCode); //0x45
	byte LD_B_HL(const byte& opCode); //0x46
	byte LD_B_A(const byte& opCode); //0x47
	byte LD_C_B(const byte& opCode); //0x48
	byte LD_C_C(const byte& opCode); //0x49
	byte LD_C_D(const byte& opCode); //0x4A
	byte LD_C_E(const byte& opCode); //0x4B
	byte LD_C_H(const byte& opCode); //0x4C
	byte LD_C_L(const byte& opCode); //0x4D
	byte LD_C_HL(const byte& opCode); //0x4E
	byte LD_C_A(const byte& opCode); //0x4F

	// 5x
	byte LD_D_B(const byte& opCode); //0x50
	byte LD_D_C(const byte& opCode); //0x51
	byte LD_D_D(const byte& opCode); //0x52
	byte LD_D_E(const byte& opCode); //0x53
	byte LD_D_H(const byte& opCode); //0x54
	byte LD_D_L(const byte& opCode); //0x55
	byte LD_D_HL(const byte& opCode); //0x56
	byte LD_D_A(const byte& opCode); //0x57
	byte LD_E_B(const byte& opCode); //058
	byte LD_E_C(const byte& opCode); //0x59
	byte LD_E_D(const byte& opCode); //0x5A
	byte LD_E_E(const byte& opCode); //0x5B
	byte LD_E_H(const byte& opCode); //0x5C
	byte LD_E_L(const byte& opCode); //0x5D
	byte LD_E_HL(const byte& opCode); //0x45E
	byte LD_E_A(const byte& opCode); //0x5F

	// 6x
	byte LD_H_B(const byte& opCode); //0x60
	byte LD_H_C(const byte& opCode); //0x61
	byte LD_H_D(const byte& opCode); //0x62
	byte LD_H_E(const byte& opCode); //0x63
	byte LD_H_H(const byte& opCode); //0x64
	byte LD_H_L(const byte& opCode); //0x65
	byte LD_H_HL(const byte& opCode); //0x66
	byte LD_H_A(const byte& opCode); //0x67
	byte LD_L_B(const byte& opCode); //0x68
	byte LD_L_C(const byte& opCode); //0x69
	byte LD_L_D(const byte& opCode); //0x6A
	byte LD_L_E(const byte& opCode); //0x6B
	byte LD_L_H(const byte& opCode); //0x6C
	byte LD_L_L(const byte& opCode); //0x6D
	byte LD_L_HL(const byte& opCode); //0x6E
	byte LD_L_A(const byte& opCode); //0x6F

	// 7x
	byte LD_HL_B(const byte& opCode); //0x70
	byte LD_HL_C(const byte& opCode); //0x71
	byte LD_HL_D(const byte& opCode); //0x72
	byte LD_HL_E(const byte& opCode); //0x73
	byte LD_HL_H(const byte& opCode); //0x74
	byte LD_HL_L(const byte& opCode); //0x75
	byte HALT(const byte& opCode); //0x76
	byte LD_HL_A(const byte& opCode); //0x77
	byte LD_A_B(const byte& opCode); //0x78
	byte LD_A_C(const byte& opCode); //0x79
	byte LD_A_D(const byte& opCode); //0x7A
	byte LD_A_E(const byte& opCode); //0x7B
	byte LD_A_H(const byte& opCode); //0x7C
	byte LD_A_L(const byte& opCode); //0x7D
	byte LD_A_HL(const byte& opCode); //0x7E
	byte LD_A_A(const byte& opCode); //0x7F

	// 8x
	byte ADD_A_B(const byte& opCode); //0x80
	byte ADD_A_C(const byte& opCode); //0x81
	byte ADD_A_D(const byte& opCode); //0x82
	byte ADD_A_E(const byte& opCode); //0x83
	byte ADD_A_H(const byte& opCode); //0x84
	byte ADD_A_L(const byte& opCode); //0x85
	byte ADD_A_HL(const byte& opCode); //0x86
	byte ADD_A_A(const byte& opCode); //0x87
	byte ADC_A_B(const byte& opCode); //0x88
	byte ADC_A_C(const byte& opCode); //0x89
	byte ADC_A_D(const byte& opCode); //0x8A
	byte ADC_A_E(const byte& opCode); //0x8B
	byte ADC_A_H(const byte& opCode); //0x8C
	byte ADC_A_L(const byte& opCode); //0x8D
	byte ADC_A_HL(const byte& opCode); //0x8E
	byte ADC_A_A(const byte& opCode); //0x8F

	// 9x
	byte SUB_B(const byte& opCode); //0x90
	byte SUB_C(const byte& opCode); //0x91
	byte SUB_D(const byte& opCode); //0x92
	byte SUB_E(const byte& opCode); //0x93
	byte SUB_H(const byte& opCode); //0x49
	byte SUB_L(const byte& opCode); //0x95
	byte SUB_HL(const byte& opCode); //0x96
	byte SUB_A(const byte& opCode); //0x97
	byte SBC_A_B(const byte& opCode); //0x98
	byte SBC_A_C(const byte& opCode); //0x99
	byte SBC_A_D(const byte& opCode); //0x9A
	byte SBC_A_E(const byte& opCode); //0x9B
	byte SBC_A_H(const byte& opCode); //0x9C
	byte SBC_A_L(const byte& opCode); //0x9D
	byte SBC_A_HL(const byte& opCode); //0x9E
	byte SBC_A_A(const byte& opCode); //0x9F

	// Ax
	byte AND_B(const byte& opCode); //0xA0
	byte AND_C(const byte& opCode); //0xA1
	byte AND_D(const byte& opCode); //0xA2
	byte AND_E(const byte& opCode); //0xA3
	byte AND_H(const byte& opCode); //0xA4
	byte AND_L(const byte& opCode); //0xA5
	byte AND_HL(const byte& opCode); //0xA6
	byte AND_A(const byte& opCode); //0xA7
	byte XOR_B(const byte& opCode); //0xA8
	byte XOR_C(const byte& opCode); //0xA9
	byte XOR_D(const byte& opCode); //0xAA
	byte XOR_E(const byte& opCode); //0xAB
	byte XOR_H(const byte& opCode); //0xAC
	byte XOR_L(const byte& opCode); //0xAD
	byte XOR_HL(const byte& opCode); //0xAE
	byte XOR_A(const byte& opCode); //0xAF

	// Bx
	byte OR_B(const byte& opCode); //0xB0
	byte OR_C(const byte& opCode); //0xB1
	byte OR_D(const byte& opCode); //0xB2
	byte OR_E(const byte& opCode); //0xB3
	byte OR_H(const byte& opCode); //0xB4
	byte OR_L(const byte& opCode); //0xB5
	byte OR_HL(const byte& opCode); //0xB6
	byte OR_A(const byte& opCode); //0xB7
	byte CP_B(const byte& opCode); //0xB8
	byte CP_C(const byte& opCode); //0xB9
	byte CP_D(const byte& opCode); //0xBA
	byte CP_E(const byte& opCode); //0xBB
	byte CP_H(const byte& opCode); //0xBC
	byte CP_L(const byte& opCode); //0xBD
	byte CP_HL(const byte& opCode); //0xBE
	byte CP_A(const byte& opCode); //0xBF

	// CX
	byte RET_NZ(const byte& opCode); //0xC0
	byte POP_BC(const byte& opCode); //0xC1
	byte JP_NZ(const byte& opCode); //0xC2
	byte JP(const byte& opCode); //0xC3
	byte CALL_NZ(const byte& opCode); //0xC4
	byte PUSH_BC(const byte& opCode); //0xC5
	byte ADD_A(const byte& opCode); //0xC6
	byte RST(const byte& opCode); //0xC7
	byte RET_Z(const byte& opCode); //0xC8
	byte RET(const byte& opCode); //0xC9
	byte JP_Z(const byte& opCode); //0xCA
	byte PREFIX_CB(const byte& opCode); //0xCB
	byte CALL_Z(const byte& opCode); //0xCC
	byte CALL(const byte& opCode); //0xCD
	byte ADC_A(const byte& opCode); //0xCE
	byte RST(const byte& opCode); //0xCF

	// Dx
	byte RET_NC(const byte& opCode); //0xD0
	byte POP_DE(const byte& opCode); //0xD1
	byte JP_NC(const byte& opCode); //0xD2
	byte CALL_NC(const byte& opCode); //0xD4
	byte PUSH_DE(const byte& opCode); //0xD5
	byte SUB(const byte& opCode); //0xD6
	byte RST_10H(const byte& opCode); //0xD7
	byte RET_C(const byte& opCode); //0xD8
	byte RETI(const byte& opCode); //0xD9
	byte JP_C(const byte& opCode); //0xDA
	byte CALL_C(const byte& opCode); //0xDD
	byte SBC_A(const byte& opCode); //0xDE
	byte RST(const byte& opCode); //0xDF

	// Ex
	byte LDH_A(const byte& opCode); //0xE0
	byte POP_HL(const byte& opCode); //0xE1
	byte LD_C_A(const byte& opCode); //0xE2
	byte PUSH_HL(const byte& opCode); //0xE5
	byte AND(const byte& opCode); //0xE6
	byte RST(const byte& opCode); //0xE7
	byte ADD_SP(const byte& opCode); //0xE8
	byte JP_HL(const byte& opCode); //0xE9
	byte LD_A(const byte& opCode); //0xEA
	byte XOR(const byte& opCode); //0xEE
	byte RST(const byte& opCode); //0xEF

	// Fx
	byte LDH_A(const byte& opCode); //0xF0
	byte POP_AF(const byte& opCode); //0xF1
	byte LD_A_C(const byte& opCode); //0xF2
	byte DI(const byte& opCode); //0xF3
	byte PUSH_AF(const byte& opCode); //0xF5
	byte OR(const byte& opCode); //0xF6
	byte RST(const byte& opCode); //0xF7
	byte LD_HL_SP(const byte& opCode); //0xF8
	byte LD_SP_HL(const byte& opCode); //0xF9
	byte LD_A(const byte& opCode); //0xFA
	byte EI(const byte& opCode); //0xFB
	byte CP(const byte& opCode); //0xFE
	byte RST(const byte& opCode); //0xFF
};

