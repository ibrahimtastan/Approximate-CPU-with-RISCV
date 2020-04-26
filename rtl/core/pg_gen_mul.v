`timescale 100ps / 1ps

module pg_gen_mul(a,b,G,P);
 input [31:0] a,b;
 output [31:0] G,P;


   genvar i;
   generate
			for (i=0; i < 32; i=i+1) 
			begin: pg_generate	
			pg_one_bit_mul u1(
						.a(a[i]),
						.b(b[i]),
						.P(P[i]),
						.G(G[i]));
			end
   endgenerate



endmodule


