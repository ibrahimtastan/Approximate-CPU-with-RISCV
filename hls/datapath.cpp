//Datapath 

#include <stdint.h>
#include <stdio.h>
#include "datapath.hpp"

uint32_t rf[32];

int16_t get_immediate (uint32_t instruction)
{
uint32_t bit_11, bit_12, bit_10s, bit_4s = 0;
int16_t imm16=0;

bit_11  = instruction & 0x80;
bit_11  = bit_11 << 3;
bit_12  = instruction & 0x80000000;
bit_12  = bit_12 >> 20;
bit_10s = instruction & 0x7E000000;
bit_10s = bit_10s>>	21;
bit_4s  = instruction & 0xF00;
bit_4s  = bit_4s>> 8;

imm16 = (bit_4s | bit_10s | bit_12 | bit_11) ;
if(bit_12)
	imm16 = imm16 | 0xF000;

imm16 <<= 1 ;
return imm16;
}

int32_t datapath(uint32_t PC){

	uint32_t instruction = inst_mem[(PC>>2)] ;
	rf[0] = 0 ;		 //overwrite first register as 0
	uint8_t Rs1, Rs2, Rd ;
	uint8_t Opcode, imm7;
	uint8_t imm3;
	uint32_t op_1, op_2, i_imm;
	int32_t inst_s = instruction;
	Opcode = instruction & 127 ;
	Rd = (instruction >> 7) & 31 ;
	imm3 = (instruction >> 12) & 7 ;
	Rs1 = (instruction >> 15) & 31 ;
	Rs2 = (instruction >> 20) & 31 ;
	imm7 = (instruction >> 25) & 127 ;
	i_imm = (inst_s >> 20);
	op_1 = rf[Rs1];
	op_2 = rf[Rs2];
	int32_t pc_amount = 4;
	switch (Opcode){
	    case 23:   ///AUIPC
			rf[Rd] = PC + (instruction & (0b11111111111111111111000000000000));
			break;
#ifdef ALUMULDIV
		case 51:  
#ifdef	XNMULDIV
			switch(imm7)
			{
#endif
#ifdef MULDIV
				case 1: /// MUL MULH MULHSU MULHU DIV DIVU REM REMU
					rf[Rd] = muldiv(op_1,op_2,imm3);
					break;
#endif

#ifdef XMULDIV
				case 65: /// APPROXIMATE MUL DIV
					rf[Rd] = xmuldiv(op_1,op_2,imm3);
					break;
#endif

#ifdef	XNALU

#ifdef	XNMULDIV
				default:
#endif

					switch(imm7>>6)// x/32
					{

#ifdef ALU
					case 0: /// 0110011 for ADD, SUB, AND, OR, XOR, SLL, SRL, SRA,  SLT, SLTU	
						rf[Rd] = alu(op_1,op_2,imm3,imm7);//0110011
						break;
#endif

#ifdef XALU
					case 1: /// APROXIMATE ADD / SUB
						rf[Rd] = xalu(op_1,op_2,imm3,imm7);//0110011
						break;
#endif
					}
#endif

#ifdef	XNMULDIV
			}
#endif
			break;
#endif
		case 19: ///0010011 for ADDI SLLI SRLI SRAI ANDI ORI XORI SLTI SLTIU	
			op_2 = i_imm;
			if(imm3 == 0b001  || imm3 == 0b101){
				i_imm =i_imm & 0b011111;} //shamt
			if(imm3 == 0 )  //SUBI YOK ADDI VAR
					imm7 =0;
			rf[Rd] = alu(op_1,op_2,imm3,imm7);  
			break;
#ifdef LUI
		case 0b0110111: ///LUI
			rf[Rd] = instruction & (0b11111111111111111111000000000000);
			break;
#endif
#ifdef LOAD
		case 0b0000011: /// LB LH LW LBU LHU 
			rf[Rd] = load(imm3,op_1+i_imm);
			break;
#endif
#ifdef STORE
		case 0b0100011: {/// SB SH SW
			uint32_t s_imm = ((inst_s >> 20) & ~(0b11111)) | Rd ;
			store(imm3,op_1+s_imm,op_2);
			break;}
#endif
#ifdef BRANCH
		case 0b1100011:{ /// BEQ, BNE, BLT, BGE, BGEU, BLTU
			if(branch(imm3,op_1,op_2)){
				pc_amount = get_immediate (instruction);
							//(((instruction >>20) & (0b100000000000)) | ((instruction<< 3 ) & (0b10000000000)) | ((instruction>>21 ) & (0b01111110000)) | ((instruction>>8 ) & (0b0000000000001111)))<<1;
			}else{pc_amount =4;}
			break;}
#endif
#ifdef JUMP
		case 0b1101111:{ /// JAL
			uint32_t jal_imm = ((((instruction >>12) & (0b10000000000000000000)) | ((instruction>>1) & (0b1111111100000000000)) | ((instruction>>10 ) & (0x400)) | ((instruction>>21 ) & (0b01111111111)))<<1);
			if(jal_imm > 0x0fffff){
				jal_imm = jal_imm | 0b11111111111000000000000000000000;
			}
			pc_amount =  jal_imm;
			rf[Rd] = PC +4;
			break;}
		case 0b1100111:{ ///  JALR
			int16_t jalr_imm = ((int32_t)instruction >>20);
			pc_amount =  op_1 + jalr_imm - PC;
			rf[Rd] = PC +4;			 
			break;}
#endif
	}
	return pc_amount;
}
