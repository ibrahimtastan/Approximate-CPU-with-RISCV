//ARITHMETIC LOGIC UNIT

#include <stdint.h>
#include <stdio.h>
#include "datapath.hpp"

uint32_t alu(uint32_t op_1,uint32_t op_2,uint8_t ftype, uint8_t func7){
	uint32_t ret = 0;

	switch (ftype)
	{
		case 0b000:
			switch (func7)
			{
				case 0: /// ADD
						ret = int32_t((int32_t)op_1 + (int32_t)op_2); //todo your(ibrahim) exact
					break;
				case 0b100000: ///SUB
					ret = int32_t((int32_t)op_1 - (int32_t)op_2);//todo your(ibrahim) exact
					break;
			}
			break;
		case 0b100: ///XOR
			ret = op_1 ^ op_2 ;
			break;
		case 0b110: ///OR
			ret = op_1 | op_2 ;
			break;
		case 0b111: ///AND
			ret = op_1 & op_2 ;
			break;
		case 0b010: ///SLT/SLTI
			if ((int32_t)op_1 < (int32_t)op_2)
				ret = 1;
			else
				ret = 0;
			break;
		case 0b011: ///SLTU/SLTIU
			if (op_1 < op_2)
				ret = 1;
			else
				ret = 0;
			break;
#ifdef SHIFT
		case 0b001: ///SLL
			ret = op_1 << op_2;
			break;
		case 0b101:
			switch (func7)
			{
				case 0: ///SRL
					ret = op_1 >> op_2;
					break;
				case 0b100000: ///SRA
					ret = ((int32_t)op_1) >> op_2;
					break;
			}
			break;
#endif
		default:
			ret = 0;
			break;
	}
	return ret;
}
