`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:44:48 05/30/2019 
// Design Name: 
// Module Name:    pg_one_bit 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module pg_one_bit(
    input en,
    input a,
    input b,
    output P,
    output G
    );


 wire a_p;
 wire b_p;  


// dynamic sizing avoids changing inputs

 assign  a_p = (en == 1) ? a : a_p ;
 assign  b_p = (en == 1) ? b : b_p;

 assign  G = a_p&b_p;
 assign  P = a_p^b_p;
 
 
endmodule
