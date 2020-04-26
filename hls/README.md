## MEHMET ALP ŞARKIŞLA

# Version Differences
This is the first chekpoint of my thesis. It encomposes finest version of the imporovments of the first two weeks.Hex and LUT file paths can be changed in **Codeblocks** code now. So running exe file be sufficient. 

Also LUTs can be grouped in GLUTs now. GLUTS not control each instruction but groups of instructions. Theese are used in controlling funtions. For example BRANCH function is executed if any of the BEQ BNE BLT BGE BLTU BGEU is in the hex file. Branch function is completely not used if no branch related instruction is used in the application.

# HLS-RISCV-32IM-datapath
Datapath in high level syntesis that takes machine code format in 32 IM RISCV architecture and processes them.   
It uses 1kb memory and 32 registers.   
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
4. choose open project and choose data_path folder  
5. change lcoation of hls.hex on tb.cpp  

5. Run hls   
   - press run C simulation  and check Clean Build  
     - press ok   
   - You can also Run C synthesis   

* If needed pragma's  can be changed from data_path function in the data_path.cpp 
* If needed memory size can be changed from mem[<size>] in data_path.cpp and data_path.hpp 

## RISCV 32IM ISA  

https://content.riscv.org/wp-content/uploads/2017/05/riscv-spec-v2.2.pdf#chapter.19


## data_path.cpp

### muldiv
Executes RV32M instructions, returns result value.

### alu
ALU executes basic integer instructions and returns result value.

### lsu
Handles memory operations.

### branch
Signed and unsigned branch instructions BEQ, BLT, BEG, BEGU,BLTU are implemented. Get immediate function is written to extract immediate value from the instruction.
If there is no any branch condition satisfied, then it will exit from the function while incrementing PC by 4. 

### jump
JAL and JALR commands are implemented. Immediate values are calculated inside of the function. Last PC value is incremented by 4 and stored in the link register. For JALR instruction, it takes a register value for base instead of previous PC value.

### get_immediate 
Parses encoded immediate values in RISCV ISA.

### data_path
Datapath coordinates the flow between register file and execution units.

## tb.cpp
First it initializes stack pointer and porgram counter registers.   
Then it reads hls.hex file and assigns it to a vector type array.   
It prints values of PC(hex) Machine instruction(hex) rf[15](dec) , rf[14](dec), rf[2](dec), and rf[0](dec).  
You can confirm the code by checking results in step 2.  
* Other elements (rf or mem) can also be added

