################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/alu.cpp \
C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/approx_add.cpp \
C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/approx_mul.cpp \
C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/branch.cpp \
C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/clz.cpp \
C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/datapath.cpp \
C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/lsu.cpp \
C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/muldiv.cpp \
C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/next_pc.cpp \
C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/riscv_core.cpp \
C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/xalu.cpp \
C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/xmuldiv.cpp 

OBJS += \
./source/alu.o \
./source/approx_add.o \
./source/approx_mul.o \
./source/branch.o \
./source/clz.o \
./source/datapath.o \
./source/lsu.o \
./source/muldiv.o \
./source/next_pc.o \
./source/riscv_core.o \
./source/xalu.o \
./source/xmuldiv.o 

CPP_DEPS += \
./source/alu.d \
./source/approx_add.d \
./source/approx_mul.d \
./source/branch.d \
./source/clz.d \
./source/datapath.d \
./source/lsu.d \
./source/muldiv.d \
./source/next_pc.d \
./source/riscv_core.d \
./source/xalu.d \
./source/xmuldiv.d 


# Each subdirectory must supply rules for building sources it contributes
source/alu.o: C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/alu.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119 -IC:/Xilinx/Vivado/2018.1/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.1/include/ap_sysc -IC:/Xilinx/Vivado/2018.1/include/etc -IC:/Xilinx/Vivado/2018.1/include -IC:/Xilinx/Vivado/2018.1/win64/tools/systemc/include -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218 -IC:/Users/Tutel/Desktop/thesis_230119/thesis_230119/thesis_hls/Version_271218 -IC:/Users/ASUS/Desktop/THESIS_02_02_19/thesis_230119/thesis_230119/thesis_hls/Version_271218 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/approx_add.o: C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/approx_add.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119 -IC:/Xilinx/Vivado/2018.1/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.1/include/ap_sysc -IC:/Xilinx/Vivado/2018.1/include/etc -IC:/Xilinx/Vivado/2018.1/include -IC:/Xilinx/Vivado/2018.1/win64/tools/systemc/include -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218 -IC:/Users/Tutel/Desktop/thesis_230119/thesis_230119/thesis_hls/Version_271218 -IC:/Users/ASUS/Desktop/THESIS_02_02_19/thesis_230119/thesis_230119/thesis_hls/Version_271218 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/approx_mul.o: C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/approx_mul.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119 -IC:/Xilinx/Vivado/2018.1/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.1/include/ap_sysc -IC:/Xilinx/Vivado/2018.1/include/etc -IC:/Xilinx/Vivado/2018.1/include -IC:/Xilinx/Vivado/2018.1/win64/tools/systemc/include -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218 -IC:/Users/Tutel/Desktop/thesis_230119/thesis_230119/thesis_hls/Version_271218 -IC:/Users/ASUS/Desktop/THESIS_02_02_19/thesis_230119/thesis_230119/thesis_hls/Version_271218 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/branch.o: C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/branch.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119 -IC:/Xilinx/Vivado/2018.1/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.1/include/ap_sysc -IC:/Xilinx/Vivado/2018.1/include/etc -IC:/Xilinx/Vivado/2018.1/include -IC:/Xilinx/Vivado/2018.1/win64/tools/systemc/include -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218 -IC:/Users/Tutel/Desktop/thesis_230119/thesis_230119/thesis_hls/Version_271218 -IC:/Users/ASUS/Desktop/THESIS_02_02_19/thesis_230119/thesis_230119/thesis_hls/Version_271218 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/clz.o: C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/clz.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119 -IC:/Xilinx/Vivado/2018.1/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.1/include/ap_sysc -IC:/Xilinx/Vivado/2018.1/include/etc -IC:/Xilinx/Vivado/2018.1/include -IC:/Xilinx/Vivado/2018.1/win64/tools/systemc/include -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218 -IC:/Users/Tutel/Desktop/thesis_230119/thesis_230119/thesis_hls/Version_271218 -IC:/Users/ASUS/Desktop/THESIS_02_02_19/thesis_230119/thesis_230119/thesis_hls/Version_271218 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/datapath.o: C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/datapath.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119 -IC:/Xilinx/Vivado/2018.1/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.1/include/ap_sysc -IC:/Xilinx/Vivado/2018.1/include/etc -IC:/Xilinx/Vivado/2018.1/include -IC:/Xilinx/Vivado/2018.1/win64/tools/systemc/include -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218 -IC:/Users/Tutel/Desktop/thesis_230119/thesis_230119/thesis_hls/Version_271218 -IC:/Users/ASUS/Desktop/THESIS_02_02_19/thesis_230119/thesis_230119/thesis_hls/Version_271218 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/lsu.o: C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/lsu.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119 -IC:/Xilinx/Vivado/2018.1/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.1/include/ap_sysc -IC:/Xilinx/Vivado/2018.1/include/etc -IC:/Xilinx/Vivado/2018.1/include -IC:/Xilinx/Vivado/2018.1/win64/tools/systemc/include -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218 -IC:/Users/Tutel/Desktop/thesis_230119/thesis_230119/thesis_hls/Version_271218 -IC:/Users/ASUS/Desktop/THESIS_02_02_19/thesis_230119/thesis_230119/thesis_hls/Version_271218 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/muldiv.o: C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/muldiv.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119 -IC:/Xilinx/Vivado/2018.1/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.1/include/ap_sysc -IC:/Xilinx/Vivado/2018.1/include/etc -IC:/Xilinx/Vivado/2018.1/include -IC:/Xilinx/Vivado/2018.1/win64/tools/systemc/include -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218 -IC:/Users/Tutel/Desktop/thesis_230119/thesis_230119/thesis_hls/Version_271218 -IC:/Users/ASUS/Desktop/THESIS_02_02_19/thesis_230119/thesis_230119/thesis_hls/Version_271218 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/next_pc.o: C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/next_pc.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119 -IC:/Xilinx/Vivado/2018.1/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.1/include/ap_sysc -IC:/Xilinx/Vivado/2018.1/include/etc -IC:/Xilinx/Vivado/2018.1/include -IC:/Xilinx/Vivado/2018.1/win64/tools/systemc/include -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218 -IC:/Users/Tutel/Desktop/thesis_230119/thesis_230119/thesis_hls/Version_271218 -IC:/Users/ASUS/Desktop/THESIS_02_02_19/thesis_230119/thesis_230119/thesis_hls/Version_271218 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/riscv_core.o: C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/riscv_core.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119 -IC:/Xilinx/Vivado/2018.1/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.1/include/ap_sysc -IC:/Xilinx/Vivado/2018.1/include/etc -IC:/Xilinx/Vivado/2018.1/include -IC:/Xilinx/Vivado/2018.1/win64/tools/systemc/include -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218 -IC:/Users/Tutel/Desktop/thesis_230119/thesis_230119/thesis_hls/Version_271218 -IC:/Users/ASUS/Desktop/THESIS_02_02_19/thesis_230119/thesis_230119/thesis_hls/Version_271218 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/xalu.o: C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/xalu.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119 -IC:/Xilinx/Vivado/2018.1/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.1/include/ap_sysc -IC:/Xilinx/Vivado/2018.1/include/etc -IC:/Xilinx/Vivado/2018.1/include -IC:/Xilinx/Vivado/2018.1/win64/tools/systemc/include -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218 -IC:/Users/Tutel/Desktop/thesis_230119/thesis_230119/thesis_hls/Version_271218 -IC:/Users/ASUS/Desktop/THESIS_02_02_19/thesis_230119/thesis_230119/thesis_hls/Version_271218 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/xmuldiv.o: C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/xmuldiv.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119 -IC:/Xilinx/Vivado/2018.1/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.1/include/ap_sysc -IC:/Xilinx/Vivado/2018.1/include/etc -IC:/Xilinx/Vivado/2018.1/include -IC:/Xilinx/Vivado/2018.1/win64/tools/systemc/include -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218 -IC:/Users/Tutel/Desktop/thesis_230119/thesis_230119/thesis_hls/Version_271218 -IC:/Users/ASUS/Desktop/THESIS_02_02_19/thesis_230119/thesis_230119/thesis_hls/Version_271218 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


