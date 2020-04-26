`timescale 1ns / 1ps

module Booth_Selector(
		input  Yj, Yj_1 , 
		input single_i, double_i, negative_i,
		output  PPij
    );

wire  wire1, wire2, wire3;


assign   wire1 =  ~(single_i & Yj);
assign   wire2 =  ~(double_i & Yj_1);
assign   wire3 =  ~(wire1 & wire2);
assign   PPij  =  wire3 ^ negative_i;


endmodule
