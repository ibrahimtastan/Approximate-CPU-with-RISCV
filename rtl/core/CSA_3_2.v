`timescale 1ns / 1ps

module CSA_3_2(
	input [31:0] X, Y, Z,
	output [31:0] S, C
    );



  genvar i;
   generate
      for (i=0; i < 32; i=i+1) 
      begin: cmprsr_3_2
        compressor_3_2 u1(
         .p0(X[i]), 
         .p1(Y[i]), 
         .p2(Z[i]), 
         .w2(C[i]), 
         .w1(S[i])          
        );	  
      end
   endgenerate
	
	
	
endmodule

