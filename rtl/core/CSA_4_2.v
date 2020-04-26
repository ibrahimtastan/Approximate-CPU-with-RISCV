`timescale 1ns / 1ps

module CSA_4_2(
	input [31:0] X, Y, Z, T,
	output [31:0] S, C
    );

wire [31:0] WS1, WC1,WC1_shift;
assign WC1_shift = (WC1 << 1);

CSA_3_2 u1 (
    .X(X), 
    .Y(Y), 
    .Z(Z), 
    .S(WS1), 
    .C(WC1)
    );
    
    
CSA_3_2 u2 (
        .X(T), 
        .Y(WS1), 
        .Z(WC1_shift), 
        .S(S), 
        .C(C)
        );

/*
  genvar i;
   generate
      for (i=0; i < 32; i=i+1) 
      begin: cmprsr_4_2
        compressor_4_2 u1(
         .p0(X[i]), 
         .p1(Y[i]), 
         .p2(Z[i]), 
         .p3(T[i]), 
         .w2(C[i]), 
         .w1(S[i])          
        );	  
      end
   endgenerate
	
*/	

endmodule
