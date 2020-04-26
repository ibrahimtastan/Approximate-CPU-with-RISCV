`timescale 1ns / 1ps

module mul_in_sizing(
    input size_x,
    input size_y,
    input X_in,
    input Y_in,
    output X,
    output Y
    );
    
   assign  X = (size_x == 1) ? X_in : X;
   assign  Y = (size_y == 1) ? Y_in : Y;    
    
endmodule
