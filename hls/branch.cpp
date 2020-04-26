//Branch

#include <stdint.h>
#include <stdio.h>
#include "datapath.hpp"

bool branch( uint8_t func, uint32_t op_1,uint32_t op_2)
{
	bool ret = false;
	int32_t op_1_s, op_2_s;
	op_1_s = (int32_t )op_1;
	op_2_s = (int32_t )op_2;
	switch (func)
	{
		case 0b000:  /// BEQ
			if(op_1_s == op_2_s){
				ret = true;
			}else{ret = false;}
			break;
		case  0b001:  /// BNE
			if(op_1_s != op_2_s){
				ret = true;
			}else{ret = false;}
			break;
		case  0b100: /// BLT
			if(op_1_s < op_2_s){
				ret = true;
			}else{ret = false;}
			break;
		case  0b101: /// BGE
			if(op_1_s >= op_2_s){
				ret = true;
			}else{ret = false;}
			break;
		case  0b110: /// BLTU
			if(op_1 < op_2){
				ret = true;
			}else{ret = false;}
			break;
		case  0b111: /// BGEU
			if(op_1 >= op_2){
				ret = true;
			}else{ret = false;}
			break;
		default:
			ret = false;
			break;
	}

	return ret;
}
