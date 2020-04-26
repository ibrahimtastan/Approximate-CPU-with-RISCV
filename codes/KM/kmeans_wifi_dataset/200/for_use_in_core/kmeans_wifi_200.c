/*****
 ** kmeans.c
 ** - a simple k-means clustering routine
 ** - returns the cluster labels of the data points in an array
 ** - here's an example
 **   extern int *k_means(double**, int, int, int, double, double**);
 **   ...
 **   int *c = k_means(data_points, num_points, dim, 20, 1e-4, 0);
 **   for (i = 0; i < num_points; i++) {
 **      printf("data point %d is in cluster %d\n", i, c[i]);
 **   }
 **   ...
 **   free(c);
 ** Parameters
 ** - array of data points (double **data)
 ** - number of data points (int n)
 ** - dimension (int m)
 ** - desired number of clusters (int k)
 ** - error tolerance (double t)
 **   - used as the stopping criterion, i.e. when the sum of
 **     squared euclidean distance (standard error for k-means)
 **     of an iteration is within the tolerable range from that
 **     of the previous iteration, the clusters are considered
 **     "stable", and the function returns
 **   - a suggested value would be 0.0001
 ** - output address for the final centroids (double **centroids)
 **   - user must make sure the memory is properly allocated, or
 **     pass the null pointer if not interested in the centroids
 ** References
 ** - J. MacQueen, "Some methods for classification and analysis
 **   of multivariate observations", Fifth Berkeley Symposium on
 **   Math Statistics and Probability, 281-297, 1967.
 ** - I.S. Dhillon and D.S. Modha, "A data-clustering algorithm
 **   on distributed memory multiprocessors",
 **   Large-Scale Parallel Data Mining, 245-260, 1999.
 ** Notes
 ** - this function is provided as is with no warranty.
 ** - the author is not responsible for any damage caused
 **   either directly or indirectly by using this function.
 ** - anybody is free to do whatever he/she wants with this
 **   function as long as this header section is preserved.
 ** Created on 2005-04-12 by
 ** - Roger Zhang (rogerz@cs.dal.ca)
 ** Modifications
 ** -
 ** Last compiled under Linux with gcc-3
 */
 /*
 ** src: http://cs.smu.ca/~r_zhang/code/kmeans.c
 */

static int IMAX = 0x7FFFFFFF ;
#include <stdio.h>
#include <stdlib.h>
 #include <assert.h>
 #include <float.h>
 #include <math.h>


 #define num_points  200
 #define feature_number  7
 #define number_of_clusters  4

static int arr [200][7] = {{	64,	56,	61,	66,	71,	82,	81	},
{	68,	57,	61,	65,	71,	85,	85	},
{	63,	60,	60,	67,	76,	85,	84	},
{	61,	60,	68,	62,	77,	90,	80	},
{	63,	65,	60,	63,	77,	81,	87	},
{	64,	55,	63,	66,	76,	88,	83	},
{	65,	61,	65,	67,	69,	87,	84	},
{	61,	63,	58,	66,	74,	87,	82	},
{	65,	60,	59,	63,	76,	86,	82	},
{	60,	58,	60,	61,	73,	84,	88	},
{	62,	59,	63,	64,	70,	84,	84	},
{	63,	59,	64,	66,	72,	84,	90	},
{	65,	59,	66,	65,	68,	82,	85	},
{	63,	56,	63,	65,	72,	82,	89	},
{	67,	60,	66,	65,	75,	86,	87	},
{	63,	57,	67,	66,	79,	86,	89	},
{	66,	59,	64,	68,	68,	97,	83	},
{	65,	61,	64,	68,	77,	86,	89	},
{	66,	57,	65,	69,	78,	85,	85	},
{	67,	57,	64,	71,	75,	89,	87	},
{	65,	62,	62,	65,	77,	84,	85	},
{	61,	54,	60,	61,	74,	87,	83	},
{	65,	53,	60,	62,	69,	85,	83	},
{	66,	55,	63,	65,	68,	85,	90	},
{	63,	57,	59,	67,	71,	82,	93	},
{	63,	57,	62,	65,	76,	82,	88	},
{	64,	57,	62,	67,	68,	83,	84	},
{	68,	63,	68,	64,	74,	86,	84	},
{	70,	62,	68,	65,	81,	89,	83	},
{	67,	59,	62,	66,	80,	96,	82	},
{	66,	59,	64,	67,	77,	87,	85	},
{	66,	59,	65,	68,	75,	88,	84	},
{	67,	59,	62,	65,	71,	91,	84	},
{	69,	61,	62,	62,	75,	85,	84	},
{	68,	58,	65,	65,	76,	87,	82	},
{	66,	62,	64,	68,	73,	89,	83	},
{	68,	58,	65,	67,	83,	89,	86	},
{	65,	58,	62,	67,	77,	86,	91	},
{	65,	58,	64,	69,	81,	88,	90	},
{	65,	56,	63,	71,	77,	89,	85	},
{	64,	59,	65,	70,	84,	90,	89	},
{	64,	56,	64,	70,	80,	91,	84	},
{	68,	57,	64,	68,	77,	88,	85	},
{	67,	56,	65,	68,	82,	96,	89	},
{	66,	69,	63,	69,	79,	88,	86	},
{	68,	57,	62,	68,	77,	91,	86	},
{	62,	58,	61,	68,	70,	85,	86	},
{	63,	58,	66,	68,	75,	90,	93	},
{	62,	58,	57,	65,	70,	82,	91	},
{	64,	51,	57,	67,	68,	84,	82	},
{	40,	50,	49,	51,	65,	75,	80	},
{	38,	52,	56,	44,	65,	71,	75	},
{	38,	51,	54,	45,	67,	72,	76	},
{	40,	55,	47,	47,	64,	75,	79	},
{	39,	56,	53,	40,	69,	75,	72	},
{	43,	58,	50,	45,	71,	68,	74	},
{	40,	53,	50,	40,	60,	69,	74	},
{	38,	58,	59,	37,	66,	74,	67	},
{	38,	63,	61,	43,	64,	76,	76	},
{	37,	56,	58,	39,	66,	70,	72	},
{	20,	63,	61,	35,	70,	73,	71	},
{	39,	57,	55,	37,	67,	70,	73	},
{	35,	58,	59,	40,	75,	75,	73	},
{	19,	59,	55,	37,	73,	72,	66	},
{	20,	56,	55,	37,	61,	79,	72	},
{	35,	54,	55,	40,	61,	79,	73	},
{	19,	60,	56,	36,	63,	70,	75	},
{	15,	60,	59,	37,	65,	74,	73	},
{	18,	60,	59,	17,	68,	75,	75	},
{	19,	63,	66,	20,	79,	73,	72	},
{	14,	59,	64,	16,	79,	76,	72	},
{	13,	63,	65,	16,	74,	73,	74	},
{	13,	60,	63,	18,	70,	73,	73	},
{	12,	60,	68,	15,	74,	73,	70	},
{	12,	64,	63,	18,	69,	72,	74	},
{	17,	63,	65,	27,	86,	72,	74	},
{	27,	59,	56,	38,	62,	75,	79	},
{	41,	58,	66,	41,	73,	71,	79	},
{	39,	54,	55,	37,	71,	64,	67	},
{	38,	56,	55,	39,	75,	71,	75	},
{	38,	62,	57,	41,	77,	65,	68	},
{	41,	57,	64,	42,	74,	69,	70	},
{	43,	59,	63,	40,	74,	66,	64	},
{	44,	58,	63,	39,	80,	71,	72	},
{	45,	58,	63,	45,	80,	76,	65	},
{	44,	57,	64,	40,	75,	69,	64	},
{	42,	58,	63,	41,	75,	69,	67	},
{	44,	57,	62,	41,	75,	65,	68	},
{	45,	58,	62,	40,	73,	70,	67	},
{	41,	59,	65,	47,	75,	68,	66	},
{	40,	63,	67,	40,	75,	70,	70	},
{	40,	56,	57,	35,	84,	70,	66	},
{	36,	60,	57,	37,	68,	66,	77	},
{	36,	59,	57,	19,	70,	69,	75	},
{	17,	59,	63,	15,	70,	76,	85	},
{	35,	57,	54,	35,	64,	78,	76	},
{	39,	54,	55,	37,	61,	77,	79	},
{	42,	56,	52,	36,	75,	68,	81	},
{	39,	51,	64,	38,	71,	78,	78	},
{	43,	53,	53,	38,	63,	76,	73	},
{	49,	56,	47,	50,	58,	77,	84	},
{	47,	58,	51,	43,	65,	80,	80	},
{	47,	54,	56,	47,	62,	78,	83	},
{	49,	55,	53,	48,	61,	79,	78	},
{	47,	57,	52,	44,	67,	78,	75	},
{	50,	62,	57,	45,	62,	81,	78	},
{	46,	56,	60,	46,	65,	84,	85	},
{	51,	55,	53,	50,	63,	79,	86	},
{	46,	48,	53,	49,	59,	80,	78	},
{	46,	58,	53,	48,	60,	79,	79	},
{	49,	45,	50,	48,	61,	79,	84	},
{	49,	49,	47,	50,	59,	79,	88	},
{	49,	53,	50,	54,	62,	77,	82	},
{	52,	54,	55,	55,	60,	74,	78	},
{	48,	56,	49,	52,	60,	82,	73	},
{	54,	57,	53,	54,	62,	77,	75	},
{	48,	54,	49,	59,	63,	78,	80	},
{	52,	53,	50,	52,	63,	84,	88	},
{	53,	52,	48,	50,	62,	81,	80	},
{	53,	53,	51,	50,	66,	82,	82	},
{	46,	56,	54,	51,	62,	80,	79	},
{	47,	58,	50,	55,	64,	76,	74	},
{	48,	47,	52,	56,	61,	77,	77	},
{	49,	50,	50,	45,	64,	79,	77	},
{	47,	51,	56,	50,	60,	78,	80	},
{	52,	50,	52,	49,	63,	80,	85	},
{	48,	47,	51,	52,	60,	74,	79	},
{	47,	51,	54,	50,	64,	75,	82	},
{	49,	52,	53,	49,	64,	77,	83	},
{	45,	56,	55,	46,	68,	79,	78	},
{	46,	58,	54,	48,	63,	78,	75	},
{	51,	51,	59,	46,	60,	80,	82	},
{	53,	56,	54,	53,	62,	88,	85	},
{	50,	58,	54,	50,	65,	79,	89	},
{	52,	51,	53,	54,	68,	88,	84	},
{	51,	62,	53,	51,	64,	86,	79	},
{	51,	51,	54,	53,	59,	86,	85	},
{	50,	68,	48,	56,	63,	80,	77	},
{	48,	52,	54,	52,	63,	80,	77	},
{	52,	53,	54,	49,	63,	85,	79	},
{	51,	54,	54,	54,	62,	85,	78	},
{	54,	54,	55,	52,	61,	86,	78	},
{	52,	54,	54,	51,	63,	87,	78	},
{	52,	53,	56,	49,	62,	83,	80	},
{	47,	56,	54,	51,	63,	81,	86	},
{	51,	57,	54,	55,	62,	87,	81	},
{	49,	54,	52,	56,	60,	85,	73	},
{	49,	54,	50,	51,	66,	78,	82	},
{	46,	47,	47,	50,	65,	79,	84	},
{	51,	54,	44,	52,	56,	79,	79	},
{	59,	52,	57,	60,	49,	86,	88	},
{	60,	53,	59,	59,	53,	86,	86	},
{	57,	52,	56,	62,	52,	92,	85	},
{	56,	51,	43,	59,	47,	83,	89	},
{	55,	52,	46,	59,	53,	88,	84	},
{	56,	58,	48,	60,	51,	85,	85	},
{	63,	58,	52,	59,	51,	88,	94	},
{	57,	61,	53,	59,	52,	87,	89	},
{	58,	61,	52,	61,	53,	85,	88	},
{	57,	57,	51,	60,	53,	85,	89	},
{	57,	60,	49,	61,	54,	85,	88	},
{	57,	61,	56,	60,	53,	86,	86	},
{	58,	54,	52,	61,	53,	85,	89	},
{	55,	56,	47,	54,	49,	81,	79	},
{	58,	55,	55,	54,	49,	78,	79	},
{	63,	54,	50,	55,	50,	85,	79	},
{	58,	55,	53,	59,	52,	81,	84	},
{	59,	59,	52,	60,	51,	87,	86	},
{	57,	55,	57,	59,	48,	85,	84	},
{	59,	57,	53,	58,	55,	85,	86	},
{	59,	59,	52,	59,	53,	87,	87	},
{	59,	56,	53,	60,	49,	85,	84	},
{	58,	56,	56,	61,	52,	85,	85	},
{	58,	59,	56,	60,	50,	86,	83	},
{	57,	57,	54,	58,	56,	84,	87	},
{	55,	56,	48,	60,	55,	84,	84	},
{	52,	61,	48,	60,	51,	80,	80	},
{	54,	57,	50,	61,	53,	83,	82	},
{	55,	53,	51,	62,	56,	85,	87	},
{	58,	55,	51,	66,	54,	86,	85	},
{	58,	53,	49,	60,	48,	86,	91	},
{	55,	48,	49,	62,	55,	86,	91	},
{	59,	57,	50,	59,	50,	89,	80	},
{	64,	55,	52,	74,	53,	89,	80	},
{	62,	62,	49,	66,	47,	93,	80	},
{	64,	57,	53,	64,	47,	88,	91	},
{	64,	59,	51,	62,	51,	88,	91	},
{	63,	56,	53,	60,	49,	88,	88	},
{	61,	58,	54,	63,	47,	88,	81	},
{	63,	57,	52,	64,	52,	88,	93	},
{	64,	58,	50,	65,	50,	91,	85	},
{	66,	57,	55,	64,	52,	91,	87	},
{	61,	55,	54,	69,	53,	84,	89	},
{	61,	61,	50,	64,	51,	84,	89	},
{	60,	60,	51,	64,	53,	87,	87	},
{	62,	63,	52,	70,	48,	87,	87	},
{	64,	57,	53,	66,	48,	92,	87	},
{	63,	54,	53,	65,	52,	92,	89	},
{	63,	57,	57,	70,	50,	92,	87	},
{	70,	59,	56,	64,	46,	88,	95	} };

static     int  labels[num_points];
static     int  c[number_of_clusters][feature_number];
static     int  c1[number_of_clusters][feature_number];
static int counts[number_of_clusters];


//k_means( num_points, feature_number,arr, number_of_clusters, 1e-4 );
  volatile  int * k_means( int n, int m,int data[][m], int k, int t ) {
        /* output cluster label for each data point */

   volatile     int h, i, j; /* loop counters, of course :) */
   volatile     int old_error, error = IMAX; /* sum of squared euclidean distance */
   volatile     int cluster[num_points];
       // assert(data && k > 0 && k <= n && m > 0 && t >= 0); /* for debugging */

        /****
         ** initialization */

        for (h = i = 0; i < k; h += n / k, i++) {
            /* pick k points as initial centroids */
            //printf("data point %d is in cluster \n", c[i][0]);
            for (j = m; j-- > 0; c[i][j] = data[h][j]);
        }

        /****
         ** main loop */

        do {
            /* save error from last step */
            old_error = error, error = 0;

            /* clear old counts and temp centroids */
            for (i = 0; i < k; counts[i++] = 0) {
                for (j = 0; j < m; c1[i][j++] = 0);
            }

            for (h = 0; h < n; h++) {
                /* identify the closest cluster */
                volatile int min_distance = IMAX;
                for (i = 0; i < k; i++) {
                   volatile  int distance = 0;
                    for (j = m; j-- > 0; distance = distance + (data[h][j] - c[i][j])*(data[h][j] - c[i][j]));
                    if (distance < min_distance) {
                        labels[h] = i;
                       // printf("data point %d is in cluster %d\n", h, labels[h]);

                        min_distance = distance;
                    }
                }


                /* update size and temp centroid of the destination cluster */
                for (j = m; j-- > 0; c1[labels[h]][j] += data[h][j]);
                counts[labels[h]]++;
                /* update standard error */
                error += min_distance;

            }

             for (i = 0; i < k; i++) { /* update all centroids */
                for (j = 0; j < m; j++) {
                    c[i][j] = counts[i] ? c1[i][j] / counts[i] : c1[i][j];
                }
            }


    } while (abs(error - old_error) > t);



	for (i = 0; i < n; i++) {
	  cluster[i] = labels[i];
	 // printf("data point %d is in cluster %d\n", i, cluster[i]);
	}


        return labels;
    }



	int main() {

	/* **   extern int *k_means(double**, int, int, int, double, double**);
	- array of data points (double **data)
 ** - number of data points (int n)
 ** - dimension (int m)
 ** - desired number of clusters (int k)
 ** - error tolerance (double t)
 **   - used as the stopping criterion, i.e. when the sum of
 **     squared euclidean distance (standard error for k-means)
 **     of an iteration is within the tolerable range from that
 **     of the previous iteration, the clusters are considered
 **     "stable", and the function returns
 **   - a suggested value would be 0.0001
 ** - output address for the final centroids (double **centroids)
 **   - user must make sure the memory is properly allocated, or
 **     pass the null pointer if not interested in the centroids  */

volatile	int * z = k_means( num_points, feature_number,arr, number_of_clusters, 5 );
/*	for (int i = 0; i < num_points; i++) {
      printf("data point %d is in cluster %d\n", i, z[i]);
    }
*/

	// FILE *myfile = fopen("result_kmeans_first.txt", "w");
	// for (int i = 0; i < num_points; i++) {
      // fprintf(myfile, "data point %d is in cluster %d\n", i, z[i]);
	// }

    return 0;

	}
