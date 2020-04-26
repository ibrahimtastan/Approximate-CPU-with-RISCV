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

static int weights [16]  =
{	-1505	,
	-8544	,
	-6025	,
	5346	,
	477	,
	2810	,
	-405	,
	2997	,
	4222	,
	-2526	,
	1501	,
	-433	,
	-459	,
	407	,
	804	,
	1951	};



static const int input[300][4] = {
{	7	,	49	,	60	,	56	},
{	69	,	92	,	1	,	96	},
{	3	,	2	,	22	,	6	},
{	17	,	52	,	60	,	33	},
{	3	,	63	,	65	,	81	},
{	83	,	122	,	3	,	89	},
{	52	,	31	,	10	,	14	},
{	32	,	21	,	19	,	4	},
{	17	,	24	,	1	,	1	},
{	3	,	26	,	42	,	8	},
{	7	,	47	,	52	,	26	},
{	9	,	43	,	44	,	45	},
{	52	,	48	,	8	,	53	},
{	90	,	117	,	3	,	59	},
{	63	,	45	,	10	,	19	},
{	45	,	3	,	8	,	3	},
{	26	,	2	,	12	,	10	},
{	11	,	35	,	40	,	15	},
{	14	,	29	,	32	,	18	},
{	31	,	20	,	11	,	18	},
{	45	,	24	,	2	,	31	},
{	29	,	10	,	34	,	0	},
{	46	,	76	,	129	,	10	},
{	64	,	66	,	133	,	11	},
{	50	,	52	,	3	,	27	},
{	14	,	23	,	17	,	17	},
{	31	,	58	,	82	,	0	},
{	57	,	166	,	218	,	38	},
{	53	,	104	,	155	,	20	},
{	43	,	9	,	32	,	9	},
{	31	,	46	,	18	,	37	},
{	9	,	1	,	0	,	4	},
{	34	,	87	,	96	,	7	},
{	58	,	161	,	197	,	19	},
{	49	,	100	,	125	,	6	},
{	32	,	2	,	19	,	15	},
{	27	,	38	,	30	,	31	},
{	24	,	44	,	22	,	49	},
{	7	,	7	,	4	,	8	},
{	23	,	80	,	72	,	2	},
{	0	,	43	,	56	,	54	},
{	56	,	63	,	8	,	70	},
{	31	,	3	,	17	,	5	},
{	33	,	87	,	79	,	7	},
{	37	,	132	,	112	,	27	},
{	9	,	56	,	28	,	6	},
{	7	,	12	,	28	,	1	},
{	35	,	73	,	76	,	5	},
{	25	,	84	,	61	,	5	},
{	1	,	1	,	21	,	7	},
{	15	,	52	,	60	,	33	},
{	3	,	62	,	65	,	79	},
{	82	,	121	,	0	,	87	},
{	51	,	33	,	8	,	14	},
{	34	,	20	,	17	,	2	},
{	18	,	27	,	1	,	2	},
{	1	,	25	,	43	,	8	},
{	6	,	46	,	52	,	25	},
{	9	,	44	,	44	,	43	},
{	50	,	47	,	7	,	51	},
{	90	,	118	,	2	,	58	},
{	63	,	42	,	13	,	18	},
{	45	,	2	,	9	,	4	},
{	27	,	1	,	13	,	11	},
{	12	,	34	,	39	,	16	},
{	13	,	28	,	33	,	16	},
{	29	,	18	,	10	,	16	},
{	47	,	24	,	0	,	32	},
{	32	,	12	,	34	,	2	},
{	50	,	77	,	129	,	12	},
{	67	,	65	,	132	,	14	},
{	49	,	51	,	3	,	27	},
{	15	,	22	,	18	,	18	},
{	33	,	56	,	76	,	1	},
{	59	,	163	,	213	,	41	},
{	54	,	100	,	151	,	24	},
{	42	,	6	,	33	,	6	},
{	14	,	42	,	17	,	25	},
{	7	,	3	,	2	,	5	},
{	19	,	93	,	101	,	15	},
{	44	,	160	,	194	,	9	},
{	37	,	105	,	131	,	14	},
{	20	,	4	,	20	,	24	},
{	16	,	36	,	31	,	24	},
{	6	,	39	,	23	,	36	},
{	8	,	0	,	2	,	2	},
{	9	,	86	,	74	,	7	},
{	25	,	121	,	123	,	1	},
{	12	,	82	,	71	,	13	},
{	0	,	2	,	1	,	15	},
{	0	,	37	,	45	,	34	},
{	70	,	80	,	11	,	84	},
{	16	,	34	,	10	,	26	},
{	3	,	22	,	27	,	15	},
{	17	,	123	,	121	,	4	},
{	37	,	170	,	172	,	33	},
{	14	,	92	,	76	,	4	},
{	2	,	6	,	5	,	15	},
{	11	,	43	,	57	,	47	},
{	36	,	57	,	7	,	54	},
{	13	,	3	,	16	,	5	},
{	20	,	92	,	83	,	1	},
{	26	,	139	,	121	,	18	},
{	2	,	57	,	27	,	18	},
{	20	,	11	,	29	,	10	},
{	19	,	48	,	62	,	47	},
{	53	,	91	,	1	,	82	},
{	28	,	1	,	35	,	6	},
{	22	,	74	,	75	,	15	},
{	12	,	85	,	63	,	4	},
{	17	,	3	,	24	,	16	},
{	28	,	52	,	61	,	27	},
{	16	,	62	,	67	,	75	},
{	68	,	116	,	5	,	75	},
{	38	,	30	,	6	,	5	},
{	20	,	27	,	21	,	11	},
{	2	,	28	,	1	,	7	},
{	16	,	24	,	42	,	0	},
{	19	,	43	,	51	,	18	},
{	1	,	41	,	43	,	36	},
{	43	,	42	,	9	,	45	},
{	78	,	111	,	2	,	46	},
{	52	,	37	,	11	,	8	},
{	33	,	5	,	11	,	5	},
{	12	,	2	,	11	,	0	},
{	0	,	31	,	37	,	7	},
{	3	,	24	,	31	,	10	},
{	20	,	13	,	9	,	10	},
{	27	,	20	,	0	,	21	},
{	14	,	18	,	37	,	8	},
{	36	,	84	,	134	,	5	},
{	57	,	74	,	139	,	6	},
{	30	,	47	,	5	,	16	},
{	5	,	17	,	18	,	7	},
{	17	,	62	,	82	,	4	},
{	48	,	172	,	225	,	35	},
{	45	,	107	,	158	,	16	},
{	32	,	8	,	34	,	15	},
{	21	,	3	,	18	,	0	},
{	26	,	90	,	84	,	4	},
{	34	,	133	,	116	,	22	},
{	6	,	55	,	25	,	9	},
{	13	,	15	,	33	,	1	},
{	14	,	48	,	63	,	52	},
{	57	,	94	,	3	,	86	},
{	34	,	5	,	31	,	2	},
{	29	,	69	,	74	,	11	},
{	20	,	81	,	59	,	2	},
{	6	,	6	,	25	,	7	},
{	20	,	54	,	62	,	34	},
{	35	,	145	,	32	,	71	},
{	43	,	66	,	47	,	14	},
{	58	,	30	,	33	,	20	},
{	65	,	6	,	8	,	14	},
{	42	,	59	,	50	,	3	},
{	53	,	2	,	12	,	12	},
{	45	,	15	,	25	,	27	},
{	29	,	136	,	45	,	61	},
{	23	,	100	,	21	,	23	},
{	39	,	122	,	54	,	51	},
{	37	,	138	,	42	,	52	},
{	51	,	57	,	47	,	1	},
{	19	,	72	,	1	,	0	},
{	41	,	123	,	41	,	33	},
{	53	,	87	,	16	,	9	},
{	22	,	88	,	16	,	20	},
{	32	,	37	,	10	,	1	},
{	49	,	94	,	23	,	1	},
{	26	,	86	,	2	,	6	},
{	37	,	9	,	29	,	23	},
{	11	,	48	,	59	,	3	},
{	44	,	136	,	43	,	52	},
{	52	,	133	,	53	,	60	},
{	18	,	116	,	22	,	65	},
{	19	,	24	,	91	,	11	},
{	11	,	127	,	15	,	66	},
{	38	,	92	,	15	,	4	},
{	29	,	165	,	42	,	76	},
{	48	,	36	,	28	,	2	},
{	59	,	16	,	0	,	24	},
{	44	,	14	,	22	,	17	},
{	41	,	55	,	47	,	3	},
{	65	,	110	,	37	,	19	},
{	25	,	78	,	4	,	7	},
{	5	,	70	,	26	,	5	},
{	13	,	120	,	10	,	68	},
{	53	,	143	,	46	,	52	},
{	69	,	121	,	63	,	50	},
{	64	,	104	,	33	,	13	},
{	67	,	134	,	52	,	54	},
{	2	,	118	,	47	,	87	},
{	26	,	12	,	58	,	15	},
{	22	,	4	,	53	,	12	},
{	53	,	42	,	18	,	7	},
{	50	,	41	,	44	,	10	},
{	49	,	129	,	49	,	54	},
{	6	,	41	,	39	,	12	},
{	49	,	10	,	14	,	21	},
{	22	,	2	,	66	,	16	},
{	46	,	12	,	8	,	8	},
{	35	,	94	,	0	,	32	},
{	58	,	105	,	30	,	20	},
{	22	,	152	,	34	,	42	},
{	64	,	2	,	2	,	15	},
{	44	,	142	,	53	,	65	},
{	24	,	104	,	0	,	28	},
{	31	,	12	,	68	,	1	},
{	31	,	58	,	76	,	2	},
{	50	,	48	,	36	,	0	},
{	28	,	57	,	46	,	7	},
{	17	,	54	,	27	,	4	},
{	64	,	49	,	18	,	11	},
{	45	,	110	,	41	,	15	},
{	2	,	100	,	3	,	48	},
{	30	,	119	,	42	,	42	},
{	62	,	20	,	0	,	20	},
{	53	,	41	,	33	,	2	},
{	14	,	110	,	12	,	23	},
{	13	,	88	,	25	,	34	},
{	23	,	152	,	26	,	67	},
{	1	,	80	,	19	,	31	},
{	7	,	0	,	15	,	7	},
{	51	,	31	,	29	,	13	},
{	21	,	13	,	113	,	12	},
{	14	,	137	,	26	,	72	},
{	24	,	31	,	31	,	4	},
{	45	,	48	,	44	,	1	},
{	2	,	116	,	47	,	74	},
{	46	,	72	,	21	,	3	},
{	1	,	22	,	106	,	4	},
{	30	,	125	,	38	,	36	},
{	21	,	38	,	2	,	1	},
{	1	,	20	,	102	,	0	},
{	8	,	110	,	23	,	55	},
{	37	,	94	,	12	,	11	},
{	22	,	152	,	39	,	62	},
{	16	,	139	,	24	,	55	},
{	41	,	57	,	48	,	1	},
{	23	,	81	,	0	,	0	},
{	58	,	46	,	36	,	3	},
{	35	,	64	,	85	,	7	},
{	11	,	48	,	59	,	3	},
{	50	,	130	,	52	,	58	},
{	18	,	1	,	53	,	7	},
{	61	,	39	,	8	,	10	},
{	29	,	158	,	9	,	97	},
{	23	,	100	,	21	,	23	},
{	53	,	92	,	24	,	11	},
{	24	,	77	,	3	,	25	},
{	51	,	28	,	31	,	14	},
{	75	,	75	,	36	,	3	},
{	26	,	138	,	30	,	43	},
{	51	,	46	,	45	,	3	},
{	10	,	122	,	48	,	96	},
{	53	,	131	,	49	,	55	},
{	10	,	96	,	8	,	11	},
{	61	,	28	,	3	,	19	},
{	67	,	67	,	36	,	6	},
{	32	,	118	,	45	,	17	},
{	26	,	97	,	6	,	23	},
{	27	,	9	,	69	,	9	},
{	54	,	117	,	58	,	55	},
{	44	,	130	,	54	,	63	},
{	33	,	102	,	47	,	16	},
{	8	,	29	,	62	,	7	},
{	53	,	9	,	10	,	9	},
{	77	,	37	,	16	,	18	},
{	16	,	42	,	3	,	1	},
{	16	,	13	,	72	,	5	},
{	2	,	97	,	15	,	46	},
{	16	,	131	,	37	,	75	},
{	28	,	160	,	37	,	45	},
{	30	,	82	,	9	,	2	},
{	14	,	8	,	76	,	7	},
{	59	,	134	,	58	,	53	},
{	4	,	52	,	39	,	4	},
{	17	,	41	,	55	,	10	},
{	7	,	0	,	15	,	7	},
{	33	,	129	,	17	,	70	},
{	39	,	40	,	24	,	4	},
{	70	,	19	,	0	,	24	},
{	17	,	19	,	90	,	13	},
{	29	,	153	,	39	,	69	},
{	28	,	0	,	60	,	3	},
{	6	,	8	,	94	,	4	},
{	34	,	36	,	6	,	6	},
{	26	,	25	,	27	,	1	},
{	16	,	121	,	31	,	67	},
{	49	,	27	,	33	,	14	},
{	51	,	11	,	14	,	21	},
{	30	,	121	,	40	,	38	},
{	41	,	88	,	13	,	2	},
{	17	,	20	,	96	,	10	},
{	20	,	45	,	17	,	4	},
{	35	,	87	,	13	,	0	},
{	31	,	120	,	41	,	18	},
{	53	,	35	,	25	,	8	},
{	21	,	6	,	60	,	15	},
{	26	,	12	,	66	,	3	},
{	4	,	9	,	9	,	5	} };





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
    volatile static int results [300][2];
    volatile static int real_results [300];

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
