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
module pg_one_bit_mul(
    input a,
    input b,
    output P,
    output G
    );
 


 assign  G = a&b;
 assign  P = a^b;
 
 
endmodule
