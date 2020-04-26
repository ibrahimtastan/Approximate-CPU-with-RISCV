`timescale 100ps / 1ps

module pg_gen(a,b,G,P,size);
 input [31:0] a,b,size;
 output [31:0] G,P;


   genvar i;
   generate
			for (i=0; i < 32; i=i+1) 
			begin: pg_generate	
			pg_one_bit u1(
						.en(size[i]),
						.a(a[i]),
						.b(b[i]),
						.P(P[i]),
						.G(G[i]));
			end
   endgenerate



endmodule


