`timescale 100ps / 1ps

module Sklansky_sizeable(
size_enable,approx_level,a,b,ci,co,s);

 input [31:0] size_enable;
 input [2:0] approx_level;
 input [31:0] a,b;
 output [31:0] s;
 input ci;
 output co;


//wire [32:0] size_enable;
wire [31:0] P,C;
wire [31:0] G0;


pg_gen_mul U1 (
	.a(a), 
    .b(b), 
    .G(G0), 
    .P(P)
    );

sklansky_tree sklansky_tree_32_bit (
    .approx_level(approx_level),
	.G0(G0), 
    .P0(P), 
    .C(C)
    );
	
xor2 s0 (
         .a(ci), 
         .b(P[0]),
         .en(size_enable[0]),
         .o(s[0])
         );

  genvar             i;
  generate
    for (i=1; i<32; i=i+1) begin: sum
			xor2 s1_31 (
			 .a(C[i-1]), 
			 .b(P[i]), 
			 .en(size_enable[i]),
			 .o(s[i])
			 );
    end 
  endgenerate
  
assign co   = C[31];

endmodule
