//Top block for RISCV design
#include <stdint.h>
#include <stdio.h>
#include "datapath.hpp"


uint32_t PC;

void riscv_core(){
	PC = next_pc(datapath(PC));
   	}
