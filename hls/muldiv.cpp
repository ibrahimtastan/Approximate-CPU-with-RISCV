//MULTIPLICATION DIVISION UNIT

#include <stdint.h>
#include <stdio.h>
#include "datapath.hpp"

uint32_t muldiv(uint32_t op_1,uint32_t op_2,uint8_t ftype){
	uint32_t ret = 0;
	switch (ftype)
	{
		#ifdef MULTI 
		case 0b000:{
			int64_t prod_s = (int32_t)op_1 * (int32_t)op_2;
			ret = prod_s & 0x00000000FFFFFFFF;
			break;}
		case 0b001:{
			int64_t prod_s = (int32_t)op_1 * (int32_t)op_2;
			ret = ( prod_s & 0xFFFFFFFF00000000 ) >> 32;
			break;}
		case 0b010:{
			int64_t prod_us = (int32_t)op_1 * (uint32_t)op_2;
			ret = ( prod_us & 0xFFFFFFFF00000000 ) >> 32;
			break;}
		case 0b011:{
			uint64_t prod_u = op_1 * op_2; //todo your(ibrahim) exact
			ret = ( prod_u & 0xFFFFFFFF00000000 ) >> 32;
			break;}
		#endif
		
		#ifdef DIVI  
		case 0b100:{
			int32_t div_s = 0x7FFFFFFF;	
			if(op_2 != 0 )
				div_s = (int32_t)op_1 / (int32_t)op_2; //todo your(ibrahim) exact
			ret = div_s;
			break;}
		case 0b101:{
			uint32_t div_u = 0xFFFFFFFF;
			if(op_2 != 0 )
				div_u = op_1 / op_2; //todo your(ibrahim) exact
			ret = div_u;
			break;}
		#endif
		
		#ifdef REMI  		
		case 0b110:{
			int32_t rem_s = (int32_t)op_1 % (int32_t)op_2;
			ret = rem_s;
			break;}
		case 0b111:{
			uint32_t rem_u = op_1 % op_2;
			ret = rem_u;
			break;}
		#endif

		default:
			ret = 0;
			break;
	}

	return ret;
}
