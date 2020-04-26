#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <math.h>
#include "datapath.hpp"

int main()
{

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
	/// **** Uncomment which file you wish to create the results **** ////

	FILE *myfile = fopen("../../../../result_knn_wifi_200_20.txt", "w");
//	FILE *myfile = fopen("../../../../result_knn_robot_200_20.txt", "w");

//	FILE *myfile = fopen("../../../../result_kmeans_robot_200.txt", "w");
//	FILE *myfile = fopen("../../../../result_kmeans.txt", "w");
//	FILE *myfile = fopen("../../../../result_kmeans_wifi_200.txt", "w");

//	FILE *myfile = fopen("../../../../result_genann_robot_200.txt", "w");


	while (true){

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

		/// **** Uncomment this part for knn code results **** ////


 /*		if( PC == 0x6cc ){ //0x6f8
			fprintf(myfile," %x: %08x : " ,PC , inst_mem[PC/4]);
			fprintf(myfile," res = %d ", rf[14]);
			fprintf(myfile," mem_address = %d\n ", rf[15]);
		}
*/

/*
 		if( PC == 0x2cc){ //0x664 //0x6f8
			fprintf(myfile," %x: %08x : " ,PC , inst_mem[PC/4]);
			fprintf(myfile," distance = %d\n ", rf[28]);
			fprintf(myfile," mem_address = %d\n ",rf[15]-40960);
		}

*/

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

		/// **** Uncomment this part for knn code robot data 200_20 results **** ////

/*
		if( PC == 0x110 ){ //0x6f8
			fprintf(myfile," %x: %08x : " ,PC , inst_mem[PC/4]);
			fprintf(myfile," res = %d ", rf[14]);
			fprintf(myfile," mem_address = %d\n ", rf[15]-92-40960);
		}

*/




/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

		/// **** Uncomment this part for knn code robot data 1960_40 results **** ////

/*
		if( PC == 0x110 ){ //0x6f8
			fprintf(myfile," %x: %08x : " ,PC , inst_mem[PC/4]);
			fprintf(myfile," res = %d ", rf[14]);
			fprintf(myfile," mem_address = %d\n ", rf[15]-172-40960);
		}

*/

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

		/// **** Uncomment this part for knn code wifi data 200_20 results **** ////


		if( PC == 0x128 ){ //0x6f8
			fprintf(myfile," %x: %08x : " ,PC , inst_mem[PC/4]);
			fprintf(myfile," res = %d ", rf[14]);
			fprintf(myfile," mem_address = %d\n ", rf[15]-92-40960);
		}







/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

		/// **** Uncomment this part for kmeans code results **** ////

/*
    	if( PC == 0x6cc ){ //0x6f8
			fprintf(myfile," %x: %08x : " ,PC , inst_mem[PC/4]);
			fprintf(myfile," res = %d ", rf[14]);
			fprintf(myfile," mem_address = %d\n ", rf[15]);
		}
*/

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

		/// **** Uncomment this part for kmeans code wifi data 200 results **** ////


/*		if( PC == 0x460 ){
			fprintf(myfile," %x: %08x : " ,PC , inst_mem[PC/4]);
			fprintf(myfile," res = %d ", rf[14]);
			fprintf(myfile," mem_address = %d\n ", rf[15]-800-40960);
		}
*/

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

		/// **** Uncomment this part for kmeans code robot data 200 results **** ////

/*
		if( PC == 0x43c ){
			fprintf(myfile," %x: %08x : " ,PC , inst_mem[PC/4]);
			fprintf(myfile," res = %d ", rf[14]);
			fprintf(myfile," mem_address = %d\n ", rf[15]-800-40960);
		}
*/

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

		/// **** Uncomment this part for knn-wifi code results **** ////

/*		if( PC == 0x118 ){
			fprintf(myfile," %x: %08x : " ,PC , inst_mem[PC/4]);
			fprintf(myfile," res = %d ", rf[15]);
			fprintf(myfile," mem_address = %d\n ", rf[8]);
		}
*/
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

		/// **** Uncomment this part for genann-robot code results **** ////
/*
		if( PC == 0x870 ){
			fprintf(myfile," %x: %08x : " ,PC , inst_mem[PC/4]);
			fprintf(myfile," res[0] = %d ", rf[13]);
			fprintf(myfile," mem_address = %d\n ", rf[14]-40960);
		}

		if( PC == 0x87c ){
			fprintf(myfile," %x: %08x : " ,PC , inst_mem[PC/4]);
			fprintf(myfile," res[1] = %d ", rf[12]);
			fprintf(myfile," mem_address = %d\n ", rf[14]-40960);
		}

		if( PC == 0x95c ){
			fprintf(myfile," %x: %08x : " ,PC , inst_mem[PC/4]);
			fprintf(myfile," res[1] = %d ", rf[14]);
			fprintf(myfile," mem_address = %d\n ", rf[15]+1600-40960);
		}
*/
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


		/// **** Standard implementation part **** ////

		if( inst_mem[PC/4] == 0x00100073 ){break;}

		printf("%x: %08x \n" ,PC , inst_mem[PC/4]);

		riscv_core();

	}

return 0;
}
