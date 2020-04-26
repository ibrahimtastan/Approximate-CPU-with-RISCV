############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project core_hls
set_top riscv_core
add_files alu.cpp
add_files approx_add.cpp
add_files approx_mul.cpp
add_files branch.cpp
add_files clz.cpp
add_files datapath.cpp
add_files datapath.hpp
add_files define_instructions.h
add_files lsu.cpp
add_files muldiv.cpp
add_files next_pc.cpp
add_files riscv_core.cpp
add_files xalu.cpp
add_files xmuldiv.cpp
add_files -tb tb.cpp
open_solution "solution1"
set_part {xc7z020clg484-1} -tool vivado
create_clock -period 10 -name default
set_clock_uncertainty 1
#source "./core_hls/solution1/directives.tcl"
csim_design -clean
csynth_design
cosim_design
export_design -format ip_catalog
