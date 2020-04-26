################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/tb.cpp 

OBJS += \
./testbench/tb.o 

CPP_DEPS += \
./testbench/tb.d 


# Each subdirectory must supply rules for building sources it contributes
testbench/tb.o: C:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119/tb.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DAESL_TB -D__llvm__ -D__llvm__ -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218_backup121119 -IC:/Xilinx/Vivado/2018.1/win64/tools/auto_cc/include -IC:/Xilinx/Vivado/2018.1/include/ap_sysc -IC:/Xilinx/Vivado/2018.1/include/etc -IC:/Xilinx/Vivado/2018.1/include -IC:/Xilinx/Vivado/2018.1/win64/tools/systemc/include -IC:/Users/ASUS/Desktop/THESIS/thesis_hls/Version_271218 -IC:/Users/Tutel/Desktop/thesis_230119/thesis_230119/thesis_hls/Version_271218 -IC:/Users/ASUS/Desktop/THESIS_02_02_19/thesis_230119/thesis_230119/thesis_hls/Version_271218 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


