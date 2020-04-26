//APROXIMATE MULTIPLICATION DIVISION UNIT

#include <stdint.h>
#include <stdio.h>
#include "datapath.hpp"

uint32_t convert_signed(uint32_t x){
	uint32_t res ;
	if ((int32_t) x < 0)
		res = -((int32_t)x);
	else
		res = x;
	return res;
}
uint32_t xmul_signed(uint32_t a, uint32_t b){

	uint32_t res=0;
	uint32_t a_s=0;
	uint32_t b_s=0;
	uint8_t approx_mul_size_op1 = 0;
	uint8_t approx_mul_size_op2 = 0;
	//uint16_t size_op1 = pow(2,approx_mul_size_op1)-1;
	//uint16_t size_op2 = pow(2,approx_mul_size_op2)-1;
	//uint32_t size_add = pow(2,(approx_mul_size_op1 + approx_mul_size_op2))-1;
	a_s = convert_signed(a);
	b_s = convert_signed(b);

	approx_mul_size_op1 = XLEN - fast_clz32(a_s);
	approx_mul_size_op2 = XLEN - fast_clz32(b_s);

	if (((int32_t)a < 0 && (int32_t)b < 0) || ((int32_t)a >= 0 && (int32_t)b >= 0) )
		res = approx_mul(a_s,b_s,approx_mul_size_op1,approx_mul_size_op2);
	else
		res = -((int32_t)approx_mul(a_s,b_s,approx_mul_size_op1,approx_mul_size_op2));
	return res;
}


uint32_t xmuldiv(uint32_t op_1,uint32_t op_2,uint8_t ftype){
	//uint32_t ret = 0;
	//ret = mul8_192(op_1, op_2);
	uint32_t ret = 0;
	switch (ftype)
	{
		#ifdef XMULTI
		case 0b000:{
			uint32_t prod_s = xmul_signed(op_1,op_2);//mul8_192((int32_t) op_1, (int32_t) op_2); //mul32x32_000(op_1,op_2);
			ret = prod_s; //prod_s & 0x00000000FFFFFFFF;
			break;}
/*		case 0b001:{
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
			break;}*/
		#endif

		#ifdef XDIVI
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

		#ifdef XREMI
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



return ret;

}

