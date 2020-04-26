`timescale 100ps / 1ps

module sklansky_tree(
	input [31:0] G0,P0,
	input [2:0] approx_level,
	output [31:0] C
 );


wire [31:0] P[5:0], G[5:0];

assign G[0] = G0;
assign P[0] = P0;


//// creating gray cell //////
gray_cell row_1_g (
    .approx(approx_level[0]),
    .G_ik(G[0][1]), 
    .P_ik(P[0][1]), 
    .G_k1j(G[0][0]), 
    .G_ij(G[1][1])
    );


  genvar             i;
  generate
    for (i=2; i<4; i=i+1) 
		
      begin: row2_g
				gray_cell row_2_g (
                     .approx(approx_level[0]),
					 .G_ik(G[1][i]), 
					 .P_ik(P[1][i]), 
					 .G_k1j(G[1][1]), 
					 .G_ij(G[2][i])
					 );
      end
  endgenerate

  genvar             j;
  generate
    for (j=4; j<8; j=j+1) 
		
      begin: row3_g
				gray_cell row_3_g (
                     .approx(approx_level[0]),
					 .G_ik(G[2][j]), 
					 .P_ik(P[2][j]), 
					 .G_k1j(G[2][3]), 
					 .G_ij(G[3][j])
					 );
      end
  endgenerate

  genvar             k;
  generate
    for (k=8; k<16; k=k+1) 
		
      begin: row4_g
				gray_cell row_4_g (
                     .approx(approx_level[1]),
					 .G_ik(G[3][k]), 
					 .P_ik(P[3][k]), 
					 .G_k1j(G[3][7]), 
					 .G_ij(G[4][k])
					 );
      end
  endgenerate


  genvar             l;
  generate
    for (l=16; l<32; l=l+1) 
		
      begin: row5_g
				gray_cell row_5_g (
                     .approx(approx_level[2]),
					 .G_ik(G[4][l]), 
					 .P_ik(P[4][l]), 
					 .G_k1j(G[4][15]), 
					 .G_ij(G[5][l])
					 );
      end
  endgenerate

//// creating black cell //////

  genvar             m;
  generate
    for (m=3; m<32; m=m+2) 
		
      begin: row1_b
				black_cell row_1_b (
					 .G_ik(G[0][m]), 
					 .P_ik(P[0][m]), 
					 .G_k1j(G[0][m-1]), 
					 .P_k1j(P[0][m-1]), 
					 .G_ij(G[1][m]), 
					 .P_ij(P[1][m])
					 );
      end
  endgenerate

  genvar             n;
  genvar             nn; 
  generate
    for (n=6; n<32; n=n+4) begin: xx2
		for (nn=0; nn<2; nn=nn+1)
      begin: row2_b
				black_cell row_2_b (
					 .G_ik(G[1][n+nn]), 
					 .P_ik(P[1][n+nn]), 
					 .G_k1j(G[1][n-1]), 
					 .P_k1j(P[1][n-1]), 
					 .G_ij(G[2][n+nn]), 
					 .P_ij(P[2][n+nn])
					 );
		end
    end
  endgenerate


  genvar             p;
  genvar             pp; 
  generate
    for (p=12; p<32; p=p+8) begin: xx3
		for (pp=0; pp<4; pp=pp+1)
      begin: row3_b
				black_cell row_3_b (
					 .G_ik(G[2][p+pp]), 
					 .P_ik(P[2][p+pp]), 
					 .G_k1j(G[2][p-1]), 
					 .P_k1j(P[2][p-1]), 
					 .G_ij(G[3][p+pp]), 
					 .P_ij(P[3][p+pp])
					 );
		end
    end
  endgenerate

  genvar             r; 
  generate
    for (r=24; r<32; r=r+1) 
      begin: row4_b
				black_cell row_4_b (
					 .G_ik(G[3][r]), 
					 .P_ik(P[3][r]), 
					 .G_k1j(G[3][23]), 
					 .P_k1j(P[3][23]), 
					 .G_ij(G[4][r]), 
					 .P_ij(P[4][r])
					 );
    end
  endgenerate

//// creating buffer cell //////


  genvar             a;
  generate
    for (a=0; a<31; a=a+2) 
		
      begin: row1
				buffer_cell row_1_buff (
					 .in1(P[0][a]), 
					 .in2(G[0][a]), 
					 .out1(P[1][a]),
					 .out2(G[1][a])
					 );
      end
  endgenerate

 


  genvar             b;
  genvar             bb; 
  generate
    for (b=0; b<32; b=b+4) begin: yy2
		for (bb=0; bb<2; bb=bb+1)
      begin: row2
				buffer_cell row_2_buff (
					 .in1(P[1][b+bb]), 
					 .in2(G[1][b+bb]), 
					 .out1(P[2][b+bb]),
					 .out2(G[2][b+bb])
					 );
		end
    end
  endgenerate

  genvar             c;
  genvar             cc; 
  generate
    for (c=0; c<32; c=c+8) begin: yy3
		for (cc=0; cc<4; cc=cc+1)
      begin: row3
				buffer_cell row_3_buff (
					 .in1(P[2][c+cc]), 
					 .in2(G[2][c+cc]), 
					 .out1(P[3][c+cc]),
					 .out2(G[3][c+cc])
					 );
		end
    end
  endgenerate


  genvar             d;
  genvar             dd; 
  generate
    for (d=0; d<32; d=d+16) begin: yy4
		for (dd=0; dd<8; dd=dd+1)
      begin: row4
				buffer_cell row_4_buff (
					 .in1(P[3][d+dd]), 
					 .in2(G[3][d+dd]), 
					 .out1(P[4][d+dd]),
					 .out2(G[4][d+dd])
					 );
		end
    end
  endgenerate

  genvar             e;

  generate
    for (e=0; e<16; e=e+1) begin: yy5
				buffer_cell row_5_buff (
					 .in1(P[4][e]), 
					 .in2(G[4][e]), 
					 .out1(P[5][e]),
					 .out2(G[5][e])
					 );
    end
  endgenerate

assign C = G[5];

  
endmodule
