`timescale 1ns / 1ps

module booth_decoder(

		input  [15:0] Y, 
		input single_i, double_i, negative_i,
		output  [16:0] PP_last

    );

wire [16:0] carry,sum,PPj;

Booth_Selector u1 (
	 .Yj(Y[0]), 
	 .Yj_1(1'b0), 
	 .single_i(single_i), 
	 .double_i(double_i), 
	 .negative_i(negative_i), 
	 .PPij(PPj[0])
	 );


  genvar j;
   generate
      for (j=1; j < 16;j=j+1) 
      begin: booth_sel
		
		Booth_Selector u2 (
			 .Yj(Y[j]), 
			 .Yj_1(Y[j-1]), 
			 .single_i(single_i), 
			 .double_i(double_i), 
			 .negative_i(negative_i), 
			 .PPij(PPj[j])
			 );				
		  
      end
   endgenerate


		Booth_Selector u2 (
			 .Yj(Y[15]), 
			 .Yj_1(Y[15]), 
			 .single_i(single_i), 
			 .double_i(double_i), 
			 .negative_i(negative_i), 
			 .PPij(PPj[16])
			 );


	HAd u3 (
    .a(PPj[0]), 
    .b(negative_i), 
    .c(carry[0]), 
    .s(sum[0])
    );


  genvar i;
   generate
      for (i=1; i < 17;i=i+1) 
      begin: half_adder
	
	HAd u4 (
    .a(PPj[i]), 
    .b(carry[i-1]), 
    .c(carry[i]), 
    .s(sum[i])
    );
	
assign PP_last = sum ;
      end
   endgenerate


endmodule



