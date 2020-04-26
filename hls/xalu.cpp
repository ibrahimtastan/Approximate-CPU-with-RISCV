//APROXIMATE ARITHMETIC LOGIC UNIT

#include <stdint.h>
#include <stdio.h>
#include "datapath.hpp"

uint32_t xalu(uint32_t op_1,uint32_t op_2,uint8_t ftype, uint8_t func7){
	uint32_t ret = 0;
    uint8_t approx_add_size = 0;
    uint8_t add_sub=0;
  //  uint32_t size = pow(2,approx_add_size+1)-1;
	switch (ftype)
	{
		case 0b000:
			switch (func7)
			{
				case 0b1000000: /// XADD
						add_sub = 0;
						/// size adjustment ///
					  if (op_1 < op_2)
						  approx_add_size = XLEN - fast_clz32(op_2);
					  else
						  approx_add_size = XLEN - fast_clz32(op_1);
					  /// approximate addition operation ///
					  ret = approx_add((int32_t) op_1,(int32_t) op_2,approx_add_size, add_sub);
					  break;
				case 0b1100000: // XSUB
					 add_sub = 1;
					 ret = approx_add((int32_t) op_1,-(int32_t) op_2, XLEN,add_sub);
//				case 0b1XXXXXXX: // new approximate operation
//					  .
//					  .
//					  .
//					break;
			}
			break;
		default:
				ret = 0;
				break;
		}

return ret;
}
