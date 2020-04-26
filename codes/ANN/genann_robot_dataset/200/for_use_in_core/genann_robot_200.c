#include <stdio.h>
#include <stdlib.h>
//#include "genann.h"



#ifndef GENANN_H
#define GENANN_H


#ifdef __cplusplus
extern "C" {
#endif


#include <assert.h>
#include <errno.h>
#include <math.h>
#include <string.h>


#define LOOKUP_SIZE 1421





//const char *save_name = "example/xor.ann";

//static int init_array[4] = {2,1,2,1}; //input ,hidden(layer num), hidden2 (neurons in one layer), output


//changeable variables

#define inputs_g 4
#define hidden_layers_g 1
#define hidden_g  2
#define outputs_g  2

//#define print_en

static int weights [16]  = {	1964	,
	6942	,
	7114	,
	1181	,
	2661	,
	894	,
	6749	,
	-8412	,
	-896	,
	765	,
	619	,
	1252	,
	2661	,
	-601	,
	-2879	,
	3001	};


static const int input[200][4] = {	{	33	,	12	,	72	,	18	}	,
	{	32	,	12	,	71	,	18	}	,
	{	32	,	13	,	71	,	19	}	,
	{	32	,	13	,	71	,	19	}	,
	{	31	,	13	,	71	,	20	}	,
	{	31	,	13	,	70	,	20	}	,
	{	30	,	13	,	70	,	15	}	,
	{	30	,	13	,	70	,	15	}	,
	{	29	,	13	,	69	,	21	}	,
	{	29	,	14	,	69	,	22	}	,
	{	25	,	19	,	61	,	43	}	,
	{	25	,	19	,	61	,	41	}	,
	{	25	,	19	,	61	,	41	}	,
	{	25	,	19	,	61	,	41	}	,
	{	25	,	19	,	61	,	43	}	,
	{	25	,	19	,	61	,	43	}	,
	{	24	,	19	,	61	,	43	}	,
	{	24	,	19	,	61	,	43	}	,
	{	24	,	19	,	61	,	41	}	,
	{	24	,	19	,	61	,	41	}	,
	{	24	,	19	,	61	,	41	}	,
	{	24	,	19	,	61	,	42	}	,
	{	23	,	19	,	61	,	57	}	,
	{	23	,	19	,	61	,	42	}	,
	{	23	,	19	,	61	,	43	}	,
	{	46	,	19	,	56	,	23	}	,
	{	46	,	21	,	55	,	22	}	,
	{	23	,	19	,	57	,	22	}	,
	{	23	,	19	,	68	,	22	}	,
	{	23	,	18	,	55	,	22	}	,
	{	24	,	12	,	81	,	31	}	,
	{	24	,	12	,	81	,	31	}	,
	{	24	,	12	,	81	,	31	}	,
	{	35	,	12	,	40	,	32	}	,
	{	33	,	12	,	40	,	32	}	,
	{	33	,	12	,	41	,	32	}	,
	{	33	,	12	,	41	,	21	}	,
	{	34	,	13	,	41	,	22	}	,
	{	34	,	13	,	41	,	27	}	,
	{	34	,	13	,	42	,	33	}	,
	{	40	,	20	,	34	,	12	}	,
	{	40	,	20	,	34	,	12	}	,
	{	43	,	20	,	34	,	13	}	,
	{	43	,	19	,	34	,	13	}	,
	{	42	,	19	,	34	,	13	}	,
	{	23	,	15	,	34	,	14	}	,
	{	41	,	16	,	34	,	14	}	,
	{	41	,	19	,	35	,	14	}	,
	{	40	,	19	,	35	,	15	}	,
	{	40	,	18	,	35	,	15	}	,
	{	18	,	13	,	81	,	32	}	,
	{	17	,	13	,	81	,	32	}	,
	{	16	,	13	,	81	,	33	}	,
	{	16	,	13	,	81	,	33	}	,
	{	16	,	13	,	81	,	33	}	,
	{	16	,	12	,	81	,	34	}	,
	{	22	,	12	,	81	,	34	}	,
	{	21	,	12	,	81	,	34	}	,
	{	22	,	12	,	62	,	34	}	,
	{	22	,	12	,	82	,	34	}	,
	{	19	,	20	,	34	,	20	}	,
	{	19	,	20	,	34	,	20	}	,
	{	20	,	20	,	34	,	20	}	,
	{	19	,	20	,	34	,	20	}	,
	{	19	,	20	,	34	,	20	}	,
	{	19	,	20	,	34	,	19	}	,
	{	19	,	20	,	34	,	19	}	,
	{	19	,	19	,	35	,	19	}	,
	{	21	,	19	,	36	,	19	}	,
	{	20	,	19	,	48	,	19	}	,
	{	20	,	12	,	34	,	12	}	,
	{	20	,	12	,	34	,	12	}	,
	{	20	,	13	,	34	,	11	}	,
	{	23	,	18	,	35	,	14	}	,
	{	22	,	18	,	35	,	14	}	,
	{	22	,	18	,	35	,	15	}	,
	{	21	,	17	,	36	,	16	}	,
	{	21	,	17	,	36	,	16	}	,
	{	20	,	17	,	36	,	17	}	,
	{	21	,	17	,	36	,	18	}	,
	{	19	,	29	,	39	,	18	}	,
	{	22	,	19	,	39	,	18	}	,
	{	20	,	20	,	39	,	18	}	,
	{	19	,	20	,	39	,	18	}	,
	{	19	,	20	,	39	,	18	}	,
	{	19	,	20	,	40	,	18	}	,
	{	19	,	20	,	40	,	18	}	,
	{	19	,	19	,	74	,	18	}	,
	{	20	,	19	,	74	,	18	}	,
	{	20	,	19	,	74	,	18	}	,
	{	22	,	21	,	33	,	13	}	,
	{	20	,	14	,	33	,	13	}	,
	{	20	,	17	,	33	,	13	}	,
	{	20	,	17	,	34	,	13	}	,
	{	20	,	17	,	34	,	13	}	,
	{	20	,	13	,	34	,	13	}	,
	{	21	,	20	,	33	,	13	}	,
	{	21	,	18	,	36	,	17	}	,
	{	20	,	17	,	36	,	17	}	,
	{	20	,	17	,	36	,	18	}	,
	{	29	,	58	,	35	,	60	}	,
	{	33	,	23	,	32	,	13	}	,
	{	45	,	23	,	31	,	13	}	,
	{	27	,	23	,	61	,	128	}	,
	{	26	,	23	,	50	,	32	}	,
	{	26	,	23	,	60	,	40	}	,
	{	26	,	23	,	60	,	41	}	,
	{	25	,	23	,	60	,	41	}	,
	{	25	,	23	,	71	,	41	}	,
	{	24	,	24	,	69	,	33	}	,
	{	41	,	36	,	42	,	52	}	,
	{	41	,	36	,	42	,	52	}	,
	{	41	,	36	,	42	,	52	}	,
	{	39	,	36	,	42	,	52	}	,
	{	39	,	36	,	42	,	52	}	,
	{	39	,	36	,	42	,	52	}	,
	{	39	,	36	,	42	,	52	}	,
	{	39	,	36	,	46	,	52	}	,
	{	39	,	36	,	45	,	52	}	,
	{	39	,	36	,	42	,	52	}	,
	{	32	,	57	,	37	,	56	}	,
	{	32	,	33	,	36	,	59	}	,
	{	32	,	33	,	36	,	58	}	,
	{	31	,	34	,	36	,	59	}	,
	{	31	,	58	,	35	,	60	}	,
	{	28	,	60	,	34	,	60	}	,
	{	28	,	60	,	33	,	62	}	,
	{	27	,	60	,	33	,	62	}	,
	{	25	,	61	,	32	,	89	}	,
	{	25	,	61	,	32	,	63	}	,
	{	47	,	38	,	48	,	46	}	,
	{	47	,	38	,	48	,	47	}	,
	{	47	,	38	,	49	,	47	}	,
	{	46	,	38	,	49	,	48	}	,
	{	46	,	37	,	47	,	48	}	,
	{	45	,	37	,	49	,	49	}	,
	{	45	,	37	,	49	,	49	}	,
	{	44	,	37	,	49	,	50	}	,
	{	44	,	37	,	49	,	50	}	,
	{	43	,	37	,	49	,	51	}	,
	{	43	,	37	,	49	,	51	}	,
	{	42	,	37	,	44	,	51	}	,
	{	42	,	37	,	50	,	52	}	,
	{	42	,	37	,	43	,	52	}	,
	{	41	,	37	,	43	,	53	}	,
	{	41	,	38	,	42	,	53	}	,
	{	40	,	37	,	41	,	53	}	,
	{	40	,	37	,	41	,	54	}	,
	{	40	,	36	,	41	,	54	}	,
	{	39	,	36	,	41	,	54	}	,
	{	34	,	12	,	73	,	17	}	,
	{	34	,	12	,	72	,	17	}	,
	{	38	,	11	,	45	,	27	}	,
	{	30	,	11	,	45	,	27	}	,
	{	30	,	11	,	46	,	26	}	,
	{	30	,	11	,	49	,	26	}	,
	{	30	,	11	,	47	,	26	}	,
	{	30	,	11	,	49	,	26	}	,
	{	30	,	11	,	46	,	26	}	,
	{	30	,	11	,	46	,	26	}	,
	{	30	,	11	,	45	,	25	}	,
	{	30	,	11	,	45	,	26	}	,
	{	30	,	11	,	45	,	25	}	,
	{	30	,	11	,	45	,	25	}	,
	{	30	,	11	,	45	,	25	}	,
	{	30	,	11	,	45	,	25	}	,
	{	40	,	11	,	49	,	25	}	,
	{	30	,	11	,	47	,	25	}	,
	{	39	,	11	,	47	,	25	}	,
	{	39	,	11	,	47	,	22	}	,
	{	46	,	8	,	55	,	21	}	,
	{	46	,	8	,	55	,	21	}	,
	{	46	,	8	,	55	,	21	}	,
	{	46	,	8	,	55	,	21	}	,
	{	46	,	8	,	55	,	21	}	,
	{	46	,	8	,	55	,	21	}	,
	{	46	,	8	,	55	,	21	}	,
	{	24	,	8	,	55	,	21	}	,
	{	24	,	8	,	55	,	21	}	,
	{	23	,	9	,	68	,	21	}	,
	{	66	,	11	,	53	,	25	}	,
	{	66	,	12	,	53	,	23	}	,
	{	39	,	12	,	47	,	26	}	,
	{	39	,	12	,	47	,	26	}	,
	{	39	,	12	,	51	,	26	}	,
	{	44	,	12	,	52	,	26	}	,
	{	44	,	12	,	49	,	26	}	,
	{	44	,	12	,	50	,	26	}	,
	{	44	,	12	,	49	,	26	}	,
	{	44	,	12	,	50	,	26	}	,
	{	28	,	11	,	45	,	14	}	,
	{	28	,	11	,	45	,	14	}	,
	{	28	,	11	,	45	,	27	}	,
	{	28	,	11	,	45	,	26	}	,
	{	38	,	12	,	45	,	26	}	,
	{	38	,	12	,	45	,	26	}	,
	{	38	,	12	,	45	,	14	}	,
	{	37	,	12	,	45	,	14	}	,
	{	37	,	12	,	45	,	14	}	,
	{	37	,	12	,	45	,	14	}	};





static const int sigmoid_dom_min = -0x58A;
static const int sigmoid_dom_max = 0x58A;

//non changable variables
#if hidden_layers_g
#define  hidden_weights ((inputs_g+1) * hidden_g + (hidden_layers_g-1) * (hidden_g+1) * hidden_g)
#define output_weights ((hidden_g+1) * outputs_g)
#else
#define  hidden_weights 0
#define output_weights ((inputs_g+1) * outputs_g)
#endif

#define total_weights_g ((hidden_weights + output_weights))//9
#define total_neurons ((inputs_g + hidden_g * hidden_layers_g + outputs_g))
#define size  (sizeof(genann) + sizeof(int) * (total_weights_g + total_neurons + (total_neurons - inputs_g)))
//<<8 https://www.rapidtables.com/convert/number/decimal-to-hex.html?x=-6.029
//https://www.rapidtables.com/convert/number/hex-to-decimal.html?x=1c6
// turn float to hex and shift left 8 bits (*256)







//static const int hidden_weights = hidden_layers ? (inputs+1) * hidden + (hidden_layers-1) * (hidden+1) * hidden : 0;//6
//static const int output_weights = (hidden_layers ? (hidden+1) : (inputs+1)) * outputs;//3
//static const int total_weights = (hidden_weights + output_weights);//9

//static const int total_neurons = (inputs + hidden * hidden_layers + outputs);

/* Allocate extra size for weights, outputs, and deltas. */
//static const int size = sizeof(genann) + sizeof(int) * (total_weights + total_neurons + (total_neurons - inputs));
//static const genann *ret = malloc(size);



// -5.5390625 -(0x5.8A)	low limit  altý 0.00390625     (0x0.01)    den küçük
//  5.5390625  (0x5.8A)   up limit  üstü 1-0.00390625 = 0.99609375  den büyük
//  0.0078125  (0x0.02) is step size
static  int lookup [LOOKUP_SIZE]= {0 , 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 22, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24, 24, 24, 25, 25, 25, 25, 25, 26, 26, 26, 26, 26, 26, 27, 27, 27, 27, 27, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 31, 31, 31, 31, 32, 32, 32, 32, 32, 33, 33, 33, 33, 34, 34, 34, 34, 34, 35, 35, 35, 35, 36, 36, 36, 36, 37, 37, 37, 37, 38, 38, 38, 38, 39, 39, 39, 39, 40, 40, 40, 41, 41, 41, 41, 42, 42, 42, 42, 43, 43, 43, 44, 44, 44, 44, 45, 45, 45, 46, 46, 46, 46, 47, 47, 47, 48, 48, 48, 49, 49, 49, 50, 50, 50, 51, 51, 51, 51, 52, 52, 52, 53, 53, 53, 54, 54, 54, 55, 55, 55, 56, 56, 57, 57, 57, 58, 58, 58, 59, 59, 59, 60, 60, 60, 61, 61, 62, 62, 62, 63, 63, 63, 64, 64, 64, 65, 65, 66, 66, 66, 67, 67, 68, 68, 68, 69, 69, 70, 70, 70, 71, 71, 72, 72, 72, 73, 73, 74, 74, 74, 75, 75, 76, 76, 76, 77, 77, 78, 78, 79, 79, 79, 80, 80, 81, 81, 82, 82, 83, 83, 83, 84, 84, 85, 85, 86, 86, 86, 87, 87, 88, 88, 89, 89, 90, 90, 91, 91, 91, 92, 92, 93, 93, 94, 94, 95, 95, 96, 96, 97, 97, 98, 98, 99, 99, 99, 100, 100, 101, 101, 102, 102, 103, 103, 104, 104, 105, 105, 106, 106, 107, 107, 108, 108, 109, 109, 110, 110, 111, 111, 112, 112, 113, 113, 114, 114, 115, 115, 116, 116, 117, 117, 118, 118, 119, 119, 120, 120, 121, 121, 122, 122, 123, 123, 124, 124, 125, 125, 126, 126, 127, 127, 128, 128, 128, 129, 129, 130, 130, 131, 131, 132, 132, 133, 133, 134, 134, 135, 135, 136, 136, 137, 137, 138, 138, 139, 139, 140, 140, 141, 141, 142, 142, 143, 143, 144, 144, 145, 145, 146, 146, 147, 147, 148, 148, 149, 149, 150, 150, 151, 151, 152, 152, 153, 153, 154, 154, 155, 155, 156, 156, 156, 157, 157, 158, 158, 159, 159, 160, 160, 161, 161, 162, 162, 163, 163, 164, 164, 164, 165, 165, 166, 166, 167, 167, 168, 168, 169, 169, 169, 170, 170, 171, 171, 172, 172, 172, 173, 173, 174, 174, 175, 175, 176, 176, 176, 177, 177, 178, 178, 179, 179, 179, 180, 180, 181, 181, 181, 182, 182, 183, 183, 183, 184, 184, 185, 185, 185, 186, 186, 187, 187, 187, 188, 188, 189, 189, 189, 190, 190, 191, 191, 191, 192, 192, 192, 193, 193, 193, 194, 194, 195, 195, 195, 196, 196, 196, 197, 197, 197, 198, 198, 198, 199, 199, 200, 200, 200, 201, 201, 201, 202, 202, 202, 203, 203, 203, 204, 204, 204, 204, 205, 205, 205, 206, 206, 206, 207, 207, 207, 208, 208, 208, 209, 209, 209, 209, 210, 210, 210, 211, 211, 211, 211, 212, 212, 212, 213, 213, 213, 213, 214, 214, 214, 214, 215, 215, 215, 216, 216, 216, 216, 217, 217, 217, 217, 218, 218, 218, 218, 219, 219, 219, 219, 220, 220, 220, 220, 221, 221, 221, 221, 221, 222, 222, 222, 222, 223, 223, 223, 223, 223, 224, 224, 224, 224, 225, 225, 225, 225, 225, 226, 226, 226, 226, 226, 227, 227, 227, 227, 227, 228, 228, 228, 228, 228, 229, 229, 229, 229, 229, 229, 230, 230, 230, 230, 230, 231, 231, 231, 231, 231, 231, 232, 232, 232, 232, 232, 232, 233, 233, 233, 233, 233, 233, 234, 234, 234, 234, 234, 234, 234, 235, 235, 235, 235, 235, 235, 236, 236, 236, 236, 236, 236, 236, 236, 237, 237, 237, 237, 237, 237, 237, 238, 238, 238, 238, 238, 238, 238, 238, 239, 239, 239, 239, 239, 239, 239, 239, 240, 240, 240, 240, 240, 240, 240, 240, 240, 241, 241, 241, 241, 241, 241, 241, 241, 241, 242, 242, 242, 242, 242, 242, 242, 242, 242, 242, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 243, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 244, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 245, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 246, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 247, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 248, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 249, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 251, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 253, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254, 254,256}
;

#ifdef __GNUC__
#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)
#define unused          __attribute__((unused))
#else
#define likely(x)       x
#define unlikely(x)     x
#define unused
#pragma warning(disable : 4996) /* For fscanf */
#endif

static int outputs_a[total_neurons] ;


typedef struct _genann {
    /* How many inputs, outputs, and hidden neurons. */
    int inputs, hidden_layers, hidden, outputs;

    /* Which activation function to use for hidden neurons. Default: gennann_act_sigmoid_cached*/
    //genann_actfun activation_hidden;

    /* Which activation function to use for output. Default: gennann_act_sigmoid_cached*/
   // genann_actfun activation_output;

    /* Total number of weights, and size of weights buffer. */
    int total_weights;

    /* Total number of neurons + inputs and size of output buffer. */
    //int total_neurons;

    /* All weights (total_weights long). */
    int *weight;

    /* Stores input array and output of each neuron (total_neurons long). */
    int *output;

    /* Stores delta of each hidden and output neuron (total_neurons - inputs long). */
   // int *delta;

} genann;


#ifdef __cplusplus
}
#endif

#endif /*GENANN_H*/
static genann ann [1] = {{inputs_g,hidden_layers_g,hidden_g,outputs_g,total_weights_g,weights,outputs_a }};

/*****
genann *genann_init( int * weights) {
    //if (hidden_layers < 0) return 0;
    //if (inputs < 1) return 0;
    //if (outputs < 1) return 0;
    //if (hidden_layers > 0 && hidden < 1) return 0;

    //2 1 2 1

    //if (!ret) return 0;

    ret->inputs = inputs_g;
    ret->hidden_layers = hidden_layers_g;
    ret->hidden = hidden_g;
    ret->outputs = outputs_g;

    ret->total_weights = total_weights_g;
    //ret->total_neurons = total_neurons;

    // Set pointers.
    //ret->weight = (int*)((char*)ret + sizeof(genann));
    ret->weight = weights;

    ret->output = ret->weight + ret->total_weights;
    //ret->delta = ret->output + ret->total_neurons;

    //genann_randomize(ret);

    //genann_init_sigmoid_lookup(ret);

    return ret;
}
**/




/*   int  output[200][2] =   {	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	0	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	0	,	1	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	0	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	,
	{	1	,	1	}	};


int predicted[200][2]= {
{	1,	0	}	,
{	0,	0	}	,
{	0,	0	}	,
{	0,	0	}	,
{	0,	0	}	,
{	0,	0	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	0	}	,
{	0,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	0,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	0,	0	}	,
{	0,	0	}	,
{	0,	1	}	,
{	0,	0	}	,
{	0,	0	}	,
{	0,	0	}	,
{	1,	0	}	,
{	1,	1	}	,
{	1,	1	}	,
{	0,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	0,	1	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	0	}	,
{	0,	0	}	,
{	0,	1	}	,
{	0,	0	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	0	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	1,	0	}	,
{	0,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	1,	1	}	,
{	0,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	1,	0	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	0,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	,
{	1,	1	}	}; */

 int genann_activation( int a) {
    //assert(!isnan(a));
    a = a >> 8;
    if (a < sigmoid_dom_min) return lookup[0];
    if (a > sigmoid_dom_max) return lookup[LOOKUP_SIZE - 1];

    int  j = (a-sigmoid_dom_min)/2 + 1;

    /* Because floating point... */
    //if (unlikely(j >= LOOKUP_SIZE)) return lookup[LOOKUP_SIZE - 1];

    return lookup[j];
}

/*
void genann_free(genann *ann) {
    // The weight, output, and delta pointers go to the same buffer.
    free(ann);
}*/



int const *genann_run(genann const *ann, int const *inputs) {
    int const *w = ann->weight;
    int *o = ann->output + ann->inputs;
    int const *i = ann->output;

    /* Copy the inputs to the scratch area, where we also store each neuron's
     * output, for consistency. This way the first layer isn't a special case. */
    memcpy(ann->output, inputs, sizeof(int) * ann->inputs);

    int h, j, k;

    if (!ann->hidden_layers) {//no hidden layers
        int *ret = o;
        for (j = 0; j < ann->outputs; ++j) {
            int sum = *w++ * -1;
            sum = sum * 256;
            for (k = 0; k < ann->inputs; ++k) {
                sum += *w++ * i[k];
            }
            *o++ = genann_activation( sum);
        }
        return ret;
    }

    /* Figure input layer */
    for (j = 0; j < ann->hidden; ++j) {
        int sum = *w++ * -1;
            sum = sum * 256;
        for (k = 0; k < ann->inputs; ++k) {
           //printf("in_pre_o w= %d i = %d\n", *w , i[k]);

            sum += *w++ * i[k];

            //printf("in_pre %d\n", sum);

        }
        *o++ = genann_activation( sum);
        //printf("in %d %d\n",  genann_activation(  sum), sum);

                        //printf("in %d\n",  genann_activation( sum));

    }

    i += ann->inputs;

    /* Figure hidden layers, if any. */
    for (h = 1; h < ann->hidden_layers; ++h) {
        for (j = 0; j < ann->hidden; ++j) {
            int sum = *w++ * -1;
            sum = sum * 256;
            for (k = 0; k < ann->hidden; ++k) {
                sum += *w++ * i[k];
            }
           *o++ = genann_activation( sum);
           // printf("hid %d %d\n",  genann_activation(  sum), sum);

        }

        i += ann->hidden;
    }
    //*o = *o << 20;
    int const *ret = o;

    /* Figure output layer. */
    for (j = 0; j < ann->outputs; ++j) {
        int sum = *w++ * -1;
            sum = sum * 256;
        for (k = 0; k < ann->hidden; ++k) {
           //printf("out_pre_o w= %d i = %d\n", *w , i[k]);

            sum += *w++ * i[k];
        //printf("out_pre %d\n", sum);
        }
        *o++ = genann_activation( sum);

        //printf("out %d %d\n",  genann_activation(  sum), sum);

        //printf("out %d\n",  genann_activation(sum));
    }

    /* Sanity check that we used all weights and wrote all outputs. */
    //assert(w - ann->weight == ann->total_weights);
    //assert(o - ann->output == ann->total_neurons);

    return ret;
}




int main(int argc, char *argv[])
{
//ret = malloc(size);
    /*printf("GENANN example 3.\n");
    printf("Load a saved ANN to solve the XOR function.\n");


    FILE *saved = fopen(save_name, "r");
    if (!saved) {
        printf("Couldn't open file: %s\n", save_name);
        exit(1);
    }

    genann *ann = genann_read(saved);
    fclose(saved);

    if (!ann) {
        printf("Error loading ANN from file: %s.", save_name);
        exit(1);
    } */
        //int inputs, int hidden_layers, int hidden, int outputs, int * weights)
    //genann *ann = genann_init(weights);
          // printf("abababa w= %d \n", ann->weight[4]) ;


    /* Input data for the XOR function. */

    /* Run the network and see what it predicts. */
    //printf("Output for [%d, %d] is %d.\n", input[0][0], input[0][1], *genann_run(ann, input[0]));
    //printf("Output for [%d, %d] is %d.\n", input[1][0], input[1][1], *genann_run(ann, input[1]));
    //printf("Output for [%d, %d] is %d.\n", input[2][0], input[2][1], *genann_run(ann, input[2]));
    //printf("Output for [%d, %d] is %d.\n", input[3][0], input[3][1], *genann_run(ann, input[3]));

 /*   volatile int results [50][2];
    int i;
	for (i = 0; i<20; i++){
		results[i] = *genann_run(ann, input[i]);
		printf("Output for the %d. result is %d\n", i+1,results[i]);
	}
*/
    volatile static int results [200][2];
    volatile static int real_results [200];

	for (int j = 0; j < 200; j++) {
           int const * result  = genann_run(ann, input[j]);
        results[j][0] = *result++;
        results[j][1] = *result;
        if (results[j][0] <128 && results[j][1] <128)
            real_results[j] = 1;
        else if (results[j][0] <128 && results[j][1] >= 128)
            real_results[j] = 2;
        else if (results[j][0] >= 128 && results[j][1] <128)
            real_results[j] = 3;
        else if (results[j][0] >= 128 && results[j][1] >=128)
            real_results[j] = 4;
        else real_results[j] = 0;
		#ifdef print_en
			printf("Output of input [%d,%d,%d,%d] output [%d %d] predicted [%d %d] is [%d %d] ",input[j][0],input[j][1],input[j][2],input[j][3],output[j][0], output[j][1], predicted[j][0],predicted[j][1], results[j][0],results[j][1]);
			printf("%d\n", real_results[j]);
		 #endif // print_en
		}

/*    results[0] = *genann_run(ann, input[0]);
    results[1] = *genann_run(ann, input[1]);
    results[2] =  *genann_run(ann, input[2]);
    results[3] = *genann_run(ann, input[3]);*/

    //printf("%d",results[1]);
/*
	*genann_run(ann, input[0]);//0
	*genann_run(ann, input[1]);//1
	*genann_run(ann, input[2]);//1
	*genann_run(ann, input[3]);//0 */

    //genann_free(ann);
    return 0;
}
