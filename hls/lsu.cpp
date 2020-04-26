//LOAD STORE UNIT

#include <stdint.h>
#include <stdio.h>
#include "datapath.hpp"

uint32_t store(uint8_t func, uint32_t addr,uint32_t val)
{
	uint32_t ret = 0;
	uint8_t last_bit;
	int32_t addr_s = addr-mem_start_adress;
	switch (func)
	{
		case  0b000: /// SB
			mem[addr_s]     = (val & 0x000000FF);
			break;
		case  0b001: /// SH
			mem[addr_s]     = (val & 0x000000FF);
			mem[addr_s + 1] = (val & 0x0000FF00) >> 8;
			break;
		case 0b010: /// SW
			mem[addr_s]     = (val & 0x000000FF);
			mem[addr_s + 1] = (val & 0x0000FF00) >> 8;
			mem[addr_s + 2] = (val & 0x00FF0000) >> 16;
			mem[addr_s + 3] = (val & 0xFF000000) >> 24;
		break;

		default:
			ret = 0;
			break;
	}

	return ret;
}

uint32_t load( uint8_t func, uint32_t addr)
{
	uint32_t ret = 0;
	uint8_t last_bit;
	int32_t addr_s = addr-mem_start_adress;
	switch (func)
	{
		case 0b000: /// LB
			ret |= (mem[addr_s]);
			last_bit = ret>>15;
			switch (last_bit){
			case 0:
				ret |= 0x00000000;
				break;
			case 1:
				ret |= 0xFFFFFF00;
				break;
			default:
				ret |= 0x00000000;
				break;
			}
			break;
		case  0b001: /// LH
			ret |= (mem[addr_s + 1] << 8) | (mem[addr_s]);
			last_bit = ret>>15;
			switch (last_bit){
			case 0:
				ret |= 0x00000000;
				break;
			case 1:
				ret |= 0xFFFF0000;
				break;
			default:
				ret |= 0x00000000;
				break;
			}
			break;
		case  0b010: /// LW
			ret |= (mem[addr_s + 3] << 24) | (mem[addr_s + 2] << 16) | (mem[addr_s + 1] << 8) | (mem[addr_s]);
			break;
		case  0b100: /// LBU
			ret |= (mem[addr_s]);
			break;
		case 0b101: /// LHU
			ret |= (mem[addr_s + 1] << 8) | (mem[addr_s]);
			break;
		default:
			ret = 0;
			break;
	}

	return ret;
}
