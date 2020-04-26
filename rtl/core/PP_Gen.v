`timescale 1ns / 1ps

module PP_Gen(
	input [15:0] size_x, size_y,
	input [15:0] X_in, Y_in ,
	output [31:0] PP0,PP1,PP2,PP3,PP4,PP5,PP6,PP7,PP8

    );


wire [15:0] X,Y;
wire [19:1] X_gen;
wire [8:0] single,double,negative; 
wire [16:0] PPi [8:0];


   genvar s;
   generate
			for (s=0; s < 16; s=s+1) 
			begin: dynamic_sizing
         mul_in_sizing s1(
                 .size_x(size_x[s]),
                 .size_y(size_y[s]),
                 .X_in(X_in[s]),
                 .Y_in(Y_in[s]),
                 .X(X[s]),
                 .Y(Y[s])
                );
			end
   endgenerate



///////////////////////////
///////////////////////////

assign X_gen = {2'b0,{X},1'b0};

  genvar i;
   generate
      for (i=1; i < 10; i=i+1) 
      begin: booth_en
	
		Booth_Encoder booth_en (
         .x2i_1(X_gen[2*i-1]), 
		 .x2i(X_gen[2*i]), 
		 .x2i1(X_gen[2*i+1]), 
		 .single(single[i-1]), 
		 .double(double[i-1]), 
		 .negative(negative[i-1])
		 );			
		  
      end
   endgenerate


  genvar j;
   generate
      for (j=0; j < 9;j=j+1) 
      begin: booth_dec

	booth_decoder booth_dec (
		 .Y(Y), 
		 .single_i(single[j]), 
		 .double_i(double[j]), 
		 .negative_i(negative[j]), 
		 .PP_last(PPi[j])
		 );

						  
      end
   endgenerate

assign PP0 = { {15{PPi[0][16]}} ,PPi[0] };
assign PP1 = { {13{PPi[1][16]}} ,PPi[1],2'b0};
assign PP2 = { {11{PPi[2][16]}} ,PPi[2],4'b0};
assign PP3 = { {9{PPi[3][16]}}  ,PPi[3],6'b0};
assign PP4 = { {7{PPi[4][16]}}  ,PPi[4],8'b0};
assign PP5 = { {5{PPi[5][16]}}  ,PPi[5],10'b0};
assign PP6 = { {3{PPi[6][16]}}  ,PPi[6],12'b0};
assign PP7 = { {1{PPi[7][16]}}  ,PPi[7],14'b0};
assign PP8 = { PPi[8][15:0],16'b0};

endmodule
