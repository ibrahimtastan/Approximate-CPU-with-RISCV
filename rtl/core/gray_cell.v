`timescale 100ps / 1ps

module gray_cell(
	input G_ik,P_ik,G_k1j,
	input approx,
	output G_ij
    );
    
reg G_out;

reg G1, G2, P1;


always @(*) begin

     case (approx)
         1'b0: begin  
                G_out <= (G_ik)|(P_ik & G_k1j);
               end
         1'b1: begin
                G_out <= (G_ik);
               end
      endcase


end

assign G_ij = G_out;	
	 
endmodule
