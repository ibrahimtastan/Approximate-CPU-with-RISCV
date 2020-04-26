`timescale 100ps / 1ps

module black_cell(
	input G_ik,P_ik,G_k1j,P_k1j,
	output G_ij, P_ij
    );


assign  G_ij = (G_ik) | (P_ik & G_k1j );
assign  P_ij = P_k1j & P_ik ;

endmodule
