//#include "ap_int.h"
#include <stdint.h>
#include <stdio.h>
#include "define_instructions.h"
#include <assert.h>
#include <math.h>

#define XLEN 32

typedef uint8_t funct3;
typedef uint8_t addr;

extern uint32_t rf[32];
extern uint32_t PC;

void riscv_core();
int32_t datapath(uint32_t instruction);
uint32_t next_pc(int32_t amount);
bool branch( uint8_t func, uint32_t op_1,uint32_t op_2);
uint32_t load( uint8_t func, uint32_t addr);
uint32_t store(uint8_t func, uint32_t addr,uint32_t val);
uint32_t alu(uint32_t op_1,uint32_t op_2,uint8_t ftype, uint8_t func7);
uint32_t xalu(uint32_t op_1,uint32_t op_2,uint8_t ftype, uint8_t func7);
uint32_t muldiv(uint32_t op_1,uint32_t op_2,uint8_t ftype);
uint32_t xmuldiv(uint32_t op_1,uint32_t op_2,uint8_t ftype);
//NOTE TO FUTURE
//IF NEW FUNCTIONS USES MEMORY THEY MUST ALL BE IN LSU.CPP

int32_t approx_add(int32_t a, int32_t b,  uint8_t approx_add_size, uint8_t add_sub);
//uint32_t mul8_192(uint32_t a, uint32_t b);
//uint64_t mul32x32_000(uint32_t opA, uint32_t opB);
//uint64_t approx_mul(uint32_t opA, uint32_t opB);
//uint64_t approx_mul(uint32_t opA, uint32_t opB, uint8_t approx_mul_size_op1, uint8_t approx_mul_size_op2);
uint64_t approx_mul(uint32_t opA, uint32_t opB, uint8_t size_op1, uint8_t size_op2);

uint32_t fast_clz32(uint32_t rs1);
