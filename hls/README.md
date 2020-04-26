
Description of the approximate CPU in HLS. 
Note that approximate blocks (approx_add & approx_mul) contain only dummy codes. Thus the core can only function exactly in HLS.

# HLS-RISCV-32IM-CPU
Riscv-core in high level syntesis that takes machine code format in 32 IM RISCV architecture and processes them.   
It uses 90kb memory and 32 registers.

## Usage   
1. Write a C code that does not contain       
```
printf()
a[5]  // Arrays still can be used but pointers must be initilized first in 1kb memory.(See example.c)   
```
2. Create hls.hex from .c file using command below.   
   - hls.hex creates RISCV ISA machine language of .c file using [RISCV-tools](https://github.com/riscv/riscv-tools/tree/cf052a0e005d537bba45312146449b7451609dbd).  
   - riscv tools must be installed
   - march=rv32i part can be changed to march=rv32im if multplication block is needed.
```
riscv32-unknown-elf-gcc -O0 -march=rv32i -c example.c -o test.o;
riscv32-unknown-elf-objcopy -O binary -j .text test.o hls.hex;
riscv32-unknown-elf-objdump -d test.o
```
3. open Vivado HLS  
4. choose open project and choose core_hls folder  
 
5. Run hls   
   - press run C simulation  and check Clean Build  
     - press ok   
   - You can also Run C synthesis   

## RISCV 32IM ISA  

https://content.riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf#chapter.19

## CORE SUBBLOCKS

### alu
ALU executes basic integer instructions and returns result value.

### approx_add
Approximate adder block. Only includes dummy operations. It is needed to create the module description in low-level (Verilog HDL)

### approx_mul
Approximate multiplier block. Only includes dummy operations. It is needed to create the module description in low-level (Verilog HDL)

### branch.cpp
Signed and unsigned branch instructions BEQ, BLT, BEG, BEGU,BLTU are implemented. Get immediate function is written to extract immediate value from the instruction.
If there is no any branch condition satisfied, then it will exit from the function while incrementing PC by 4. 

### clz.cpp
It counts leading zeros. Used for dynamic sizing.

### datapath.cpp
Describes all datapath of the core. It coordinates the flow among register file, memory and execution units.

### lsu
Handles memory operations.

### muldiv
Executes RV32M instructions, returns result value.

### next_pc.cpp
This function is needed for PC to count.

### riscv_core.cpp
Top module of the core.

### xalu
Executes ADD, SUB instructions approximately (XADD & XSUB).

### xmuldiv
Executes MUL instructions approximately (XMUL).

### tb.cpp
It starts the code and prints the PC value and instructions until the code is finished. 
You can print the register or memory values (rf or mem) for any PC values to debug the code.  

