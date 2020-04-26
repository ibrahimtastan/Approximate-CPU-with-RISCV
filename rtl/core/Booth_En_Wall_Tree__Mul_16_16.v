`timescale 1ns / 1ps

module Booth_En_Wall_Tree__Mul_16_16(
	input [2:0] approx_level,
	input [15:0] size_x, size_y,
	input [31:0] size_add,
	input [15:0] X, Y ,
	output [31:0] result

    );

wire [31:0] PP [8:0];
wire [31:0] WS1,WS2, WS3, WS4, WS5, WC1, WC2, WC3, WC4, WC5, S_last, C_last;
wire [31:0] WC1_shift, WC2_shift, WC3_shift, WC4_shift, WC5_shift, C_last_shift ;
wire co;


// shift carries in adder tree. //

assign WC1_shift = (WC1 << 1);
assign WC2_shift = (WC2 << 1);
assign WC3_shift = (WC3 << 1);
assign WC4_shift = (WC4 << 1);
assign WC5_shift = (WC5 << 1);
assign C_last_shift = (C_last << 1);
 


// partial product generation with sizing //

PP_Gen u1 (
    .size_x(size_x), 
    .size_y(size_y), 
    .X_in(X), 
    .Y_in(Y), 
    .PP0(PP[0]), 
    .PP1(PP[1]), 
    .PP2(PP[2]), 
    .PP3(PP[3]), 
    .PP4(PP[4]), 
    .PP5(PP[5]), 
    .PP6(PP[6]), 
    .PP7(PP[7]), 
    .PP8(PP[8])
    );


 
// Wallace Tree with Carry Save Adders

CSA_3_2 CSA1 (
	.X(PP[0]), 
    .Y(PP[1]), 
    .Z(PP[2]), 
    .S(WS1), 
    .C(WC1)
    );


CSA_3_2 CSA2 (
    .X(PP[3]), 
    .Y(PP[4]), 
    .Z(PP[5]), 
    .S(WS2), 
    .C(WC2)
    );
	 
CSA_3_2 CSA3 (
    .X(PP[6]), 
    .Y(PP[7]), 
    .Z(PP[8]), 
    .S(WS3), 
    .C(WC3)
    );

CSA_3_2 CSA4 (
    .X(WS1), 
    .Y(WS2), 
    .Z(WC1_shift), 
    .S(WS4), 
    .C(WC4)
    );

CSA_3_2 CSA5 (
    .X(WS3), 
    .Y(WC2_shift), 
    .Z(WC3_shift), 
    .S(WS5), 
    .C(WC5)
    );


CSA_4_2 CSA6 (
    .X(WS4), 
    .Y(WS5), 
    .Z(WC4_shift), 
    .T(WC5_shift), 
    .S(S_last), 
    .C(C_last)
    );

// final adder

Sklansky_sizeable uut(
	.approx_level(approx_level),
	.size_enable(size_add),
	.a(S_last),
	.b(C_last_shift),
	.ci(1'b0),
	.co(co),
	.s(result)
);



	 
endmodule
