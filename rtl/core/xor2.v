`timescale 100ps / 1ps

module xor2(
 input a,b,en,
 output o

 );

assign o = (en == 1) ? (a^b) : 1'b0 ; 

endmodule
