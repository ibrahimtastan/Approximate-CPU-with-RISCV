`timescale 1ns / 1ps

module compressor_3_2(
    input p0,
    input p1,
    input p2,
    output w1,
    output w2
    );

//assign w1 = (p0 | p1); 
//assign w2 = (p2|(p0 & p1)); 

assign w1 = (p2 ^ (p0 ^ p1));
assign w2 = (p0 & p1) | (p2 & (p0 ^ p1));


endmodule


