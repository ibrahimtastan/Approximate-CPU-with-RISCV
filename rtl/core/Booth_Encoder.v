`timescale 1ns / 1ps

module Booth_Encoder(
		input x2i_1, x2i, x2i1,
		output single, double, negative
//		output X1_b, X2_b,Z,N  
	 );

wire wire1,wire2;


assign  single = x2i_1 ^ x2i;

assign  wire1  = (~(x2i_1 & x2i & ~(x2i1)));
  
assign  wire2  = (~(~(x2i_1) & ~(x2i) & x2i1));  

assign  double = (~(wire1 & wire2));

assign negative =  x2i1 ;


endmodule
