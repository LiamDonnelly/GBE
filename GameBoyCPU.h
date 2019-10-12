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

	// Generic functions. r - single register, rr - 16 bit register
	byte INC_r(const byte& opCode); 
	byte INC_rr(const byte& opCode); 
	byte LD_B_r(const byte& opCode);
	byte LD_C_r(const byte& opCode);
	byte LD_D_r(const byte& opCode);
	byte LD_E_r(const byte& opCode);
	byte LD_H_r(const byte& opCode);
	byte LD_L_r(const byte& opCode);
	byte LD_HL_r(const byte& opCode);
	byte HALT(const byte& opCode); 
	byte LD_A_r(const byte& opCode);
	byte ADD_A_r(const byte& opCode);
	byte ADC_A_r(const byte& opCode);
	byte SUB_r(const byte& opCode);
	byte SBC_A_r(const byte& opCode);
	byte AND_r(const byte& opCode);
	byte XOR_r(const byte& opCode);
	byte OR_r(const byte& opCode); 
	byte CP_r(const byte& opCode); 
	byte DEC_r(const byte& opCode);
	byte DEC_rr(const byte& opCode);
	byte RST(const byte& opCode); //0xC7


	byte NOP(const byte& opCode); //0x00
	byte LD_BC(const byte& opCode); //0x01
	byte LD_BC_A(const byte& opCode); //0x02
	byte LD_B(const byte& opCode); //0x06
	byte RL_CA(const byte& opCode); //0x07
	byte LD_SP(const byte& opCode); //0x08
	byte ADD_HL_BC(const byte& opCode); //0x09
	byte LD_A_BC(const byte& opCode); //0x0A
	byte LD_C(const byte& opCode); //0x0E
	byte RR_CA(const byte& opCode); //0x0F
	
	// 1x
	byte STOP(const byte& opCode); //0x10
	byte LD_DE(const byte& opCode); //0x11
	byte LD_DE_A(const byte& opCode); //0x12
	byte LD_D(const byte& opCode); //0x16
	byte RL_A(const byte& opCode); //0x17
	byte JR(const byte& opCode); //0x18
	byte ADD_HL_DE(const byte& opCode); //0x19
	byte LD_A_DE(const byte& opCode); //0x1A
	byte LD_£(const byte& opCode); //0x1E
	byte RR_A(const byte& opCode); //0x1F

	// 2x
	byte JR_NZ(const byte& opCode); //0x20
	byte LD_HL(const byte& opCode); //0x21
	byte LD_HL_A(const byte& opCode); //0x22
	byte LD_H(const byte& opCode); //0x26
	byte DAA(const byte& opCode); //0x27
	byte JR_Z(const byte& opCode); //0x28
	byte ADD_HL_HL(const byte& opCode); //0x29
	byte LD_A_HL(const byte& opCode); //0x2A
	byte LD_L(const byte& opCode); //0x2E
	byte CPL(const byte& opCode); //0x2F

	// 3x
	byte JR_NC(const byte& opCode); //0x30
	byte LD_SP(const byte& opCode); //0x31
	byte LD_HL_A(const byte& opCode); //0x32
	byte LD_HL(const byte& opCode); //0x36
	byte SCF(const byte& opCode); //0x37
	byte JR_C(const byte& opCode); //0x38
	byte ADD_HL_SP(const byte& opCode); //0x39
	byte LD_A_HL(const byte& opCode); //0x3A
	byte LD_A(const byte& opCode); //0x3E
	byte CCF(const byte& opCode); //0x3F

	// CX
	byte RET_NZ(const byte& opCode); //0xC0
	byte POP_BC(const byte& opCode); //0xC1
	byte JP_NZ(const byte& opCode); //0xC2
	byte JP(const byte& opCode); //0xC3
	byte CALL_NZ(const byte& opCode); //0xC4
	byte PUSH_BC(const byte& opCode); //0xC5
	byte ADD_A(const byte& opCode); //0xC6
	byte RET_Z(const byte& opCode); //0xC8
	byte RET(const byte& opCode); //0xC9
	byte JP_Z(const byte& opCode); //0xCA
	byte PREFIX_CB(const byte& opCode); //0xCB
	byte CALL_Z(const byte& opCode); //0xCC
	byte CALL(const byte& opCode); //0xCD
	byte ADC_A(const byte& opCode); //0xCE

	// Dx
	byte RET_NC(const byte& opCode); //0xD0
	byte POP_DE(const byte& opCode); //0xD1
	byte JP_NC(const byte& opCode); //0xD2
	byte CALL_NC(const byte& opCode); //0xD4
	byte PUSH_DE(const byte& opCode); //0xD5
	byte SUB(const byte& opCode); //0xD6
	byte RET_C(const byte& opCode); //0xD8
	byte RETI(const byte& opCode); //0xD9
	byte JP_C(const byte& opCode); //0xDA
	byte CALL_C(const byte& opCode); //0xDD
	byte SBC_A(const byte& opCode); //0xDE

	// Ex
	byte LDH_A(const byte& opCode); //0xE0
	byte POP_HL(const byte& opCode); //0xE1
	byte LD_C_A(const byte& opCode); //0xE2
	byte PUSH_HL(const byte& opCode); //0xE5
	byte AND(const byte& opCode); //0xE6
	byte ADD_SP(const byte& opCode); //0xE8
	byte JP_HL(const byte& opCode); //0xE9
	byte LD_A(const byte& opCode); //0xEA

	// Fx
	byte LDH_A(const byte& opCode); //0xF0
	byte POP_AF(const byte& opCode); //0xF1
	byte LD_A_C(const byte& opCode); //0xF2
	byte DI(const byte& opCode); //0xF3
	byte PUSH_AF(const byte& opCode); //0xF5
	byte OR(const byte& opCode); //0xF6
	byte LD_HL_SP(const byte& opCode); //0xF8
	byte LD_SP_HL(const byte& opCode); //0xF9
	byte LD_A(const byte& opCode); //0xFA
	byte EI(const byte& opCode); //0xFB
	byte CP(const byte& opCode); //0xFE
};

