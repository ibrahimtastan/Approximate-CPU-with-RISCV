# approximate_cpu_with_riscv
This repo describes an approximate cpu design with RISC-V ISA. It includes custom approximate adder and multiplier

# For testing in C (HLS), 

- Change the directory of the .hex and .mem file in /hls/Define_instruction/filepath.txt.
- All .hex and .mem files of the codes are resided in /codes/.
- After any change in filepath.txt., you should run /hls/Define_instruction/Define_instruction.exe.
- Observe the change in /hls/define_instructions.h. It should be updated.
- Now define_instructions.h shows your instruction and data memories content for your specific tests.
- You can run the test and print the results in a text by arranging proper address for the results in /hls/tb.cpp. 
- You can also check /hlsREADME.md for more details. 

# For generating a sample core from hls,

- Do not forget to add custom define definitions for approximate blocks to /hls/define_instructions.h.
	- for XADD,XSUB you should add "#define XALU" to define_instructions.h. 
	- for XMUL, you should add "#define XMULDIV" and "#define XMULTI" to define_instructions.h. 
- After synthesis, you obtain verilog codes from the directory: /hls/core_hls/solution1/syn/verilog/
- Do not forget to transfer .dat files, too. If you modify the approximate instructions by plug-in in C, then you can use datapath_inst_mem_rom.dat, directly for your operations. Otherwise, it includes only exact operations. You should change your target instructions to approximate counterparts by hand.


# Usage with HDL core

- For Vivado, open a new project add copy of the Verilog codes created by hls and .dat files to the project. 
	- Do not forget to transfer .dat files, too. Otherwise, you should correct the path in datapath_mem.v, datapath_inst_mem.v, and datapath_rf.v for readmemh.
- You should change approx_add and approx_mul verilog codes with the ones reside in /rtl/core/.
	This modules are different than the ones created by HLS!. 
	!! You should add approx_levels to definitions of the modules!!
	You should change instantiations of these modules in datapath.v.
	You should also change datapath module instantiation in riscv_core.v. 
	You should also make approx_levels inputs of riscv_core module to achieve independent controls of these levels.
	You can check the sample generated codes in /thesis_deliverables/rtl/core/.
- You can also use sample core, which is in /rtl/core/, as a main core and only change the datapath_inst_mem_rom.dat and datapath_mem_ram.dat for new code simulations.


