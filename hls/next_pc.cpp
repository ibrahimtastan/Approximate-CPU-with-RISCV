//PC incrementation

#include <stdint.h>
#include <stdio.h>
#include "datapath.hpp"

uint32_t next_pc(int32_t amount){
	PC += amount;
	return PC;
}
