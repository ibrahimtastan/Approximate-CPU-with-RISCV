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
 #define feature_number  4
 #define number_of_clusters  4
static int arr [200][4] = {
{	1298,	504,	2816,	730	},
{	1285,	507,	2810,	742	},
{	1271,	511,	2800,	756	},
{	1256,	515,	2789,	771	},
{	1239,	520,	2777,	787	},
{	1223,	525,	2766,	807	},
{	1206,	530,	2753,	611	},
{	1188,	535,	2741,	621	},
{	1170,	541,	2727,	859	},
{	1152,	548,	2713,	878	},
{	981,	780,	2387,	1703	},
{	980,	780,	2391,	1606	},
{	979,	779,	2388,	1610	},
{	978,	779,	2385,	1614	},
{	978,	779,	2388,	1704	},
{	977,	779,	2388,	1708	},
{	976,	778,	2392,	1709	},
{	974,	778,	2392,	1710	},
{	972,	777,	2391,	1616	},
{	968,	777,	2390,	1624	},
{	961,	776,	2393,	1628	},
{	952,	775,	2387,	1642	},
{	937,	773,	2392,	2247	},
{	924,	775,	2398,	1669	},
{	910,	774,	2402,	1685	},
{	1815,	746,	2217,	926	},
{	1824,	835,	2150,	874	},
{	919,	747,	2241,	868	},
{	912,	746,	2663,	893	},
{	905,	742,	2160,	882	},
{	961,	500,	3177,	1228	},
{	951,	499,	3179,	1235	},
{	943,	498,	3181,	1245	},
{	1389,	497,	1595,	1265	},
{	1315,	499,	1600,	1271	},
{	1304,	502,	1606,	1280	},
{	1299,	504,	1618,	856	},
{	1358,	508,	1631,	865	},
{	1349,	512,	1640,	1076	},
{	1339,	516,	1653,	1323	},
{	1569,	791,	1331,	497	},
{	1566,	792,	1333,	502	},
{	1696,	788,	1337,	511	},
{	1685,	780,	1343,	521	},
{	1669,	775,	1349,	533	},
{	902,	616,	1355,	547	},
{	1637,	632,	1362,	562	},
{	1620,	753,	1370,	577	},
{	1596,	745,	1378,	594	},
{	1569,	737,	1385,	611	},
{	711,	540,	3166,	1255	},
{	679,	530,	3176,	1272	},
{	658,	521,	3199,	1291	},
{	650,	515,	3185,	1309	},
{	644,	509,	3191,	1325	},
{	639,	504,	3194,	1340	},
{	860,	504,	3201,	1348	},
{	859,	496,	3203,	1351	},
{	861,	491,	2430,	1349	},
{	865,	491,	3208,	1345	},
{	769,	820,	1343,	790	},
{	778,	800,	1355,	787	},
{	803,	792,	1360,	785	},
{	774,	789,	1345,	789	},
{	767,	788,	1349,	789	},
{	766,	782,	1355,	776	},
{	769,	791,	1360,	775	},
{	776,	767,	1370,	774	},
{	831,	761,	1441,	769	},
{	792,	758,	1905,	767	},
{	798,	502,	1352,	473	},
{	801,	503,	1336,	474	},
{	815,	511,	1334,	462	},
{	899,	726,	1386,	566	},
{	878,	718,	1393,	583	},
{	866,	711,	1400,	601	},
{	845,	697,	1415,	636	},
{	832,	690,	1421,	652	},
{	806,	682,	1433,	681	},
{	851,	670,	1444,	710	},
{	771,	1151,	1541,	735	},
{	875,	746,	1559,	728	},
{	818,	789,	1546,	725	},
{	768,	784,	1551,	723	},
{	767,	783,	1554,	720	},
{	767,	784,	1574,	722	},
{	770,	810,	1577,	718	},
{	773,	769,	2911,	713	},
{	786,	763,	2912,	711	},
{	797,	756,	2913,	709	},
{	879,	838,	1321,	528	},
{	816,	548,	1322,	524	},
{	812,	667,	1323,	518	},
{	811,	665,	1330,	519	},
{	814,	666,	1334,	519	},
{	817,	546,	1346,	520	},
{	837,	805,	1328,	509	},
{	835,	704,	1414,	683	},
{	806,	697,	1425,	701	},
{	791,	688,	1432,	719	},
{	1144,	2302,	1380,	2364	},
{	1325,	907,	1253,	522	},
{	1761,	902,	1247,	519	},
{	1070,	904,	2394,	5000	},
{	1052,	904,	1967,	1279	},
{	1036,	908,	2372,	1574	},
{	1018,	908,	2350,	1602	},
{	1001,	906,	2347,	1627	},
{	983,	910,	2783,	1631	},
{	967,	946,	2725,	1302	},
{	1629,	1412,	1677,	2047	},
{	1604,	1413,	1675,	2049	},
{	1603,	1413,	1675,	2050	},
{	1557,	1413,	1674,	2051	},
{	1556,	1413,	1673,	2053	},
{	1556,	1413,	1672,	2054	},
{	1558,	1413,	1673,	2055	},
{	1558,	1414,	1797,	2056	},
{	1558,	1413,	1782,	2058	},
{	1557,	1414,	1668,	2060	},
{	1276,	2253,	1447,	2199	},
{	1265,	1319,	1435,	2312	},
{	1254,	1324,	1423,	2299	},
{	1245,	1336,	1415,	2334	},
{	1234,	2293,	1405,	2364	},
{	1115,	2358,	1329,	2349	},
{	1098,	2365,	1323,	2431	},
{	1081,	2372,	1316,	2435	},
{	1014,	2401,	1289,	3486	},
{	997,	2407,	1283,	2480	},
{	1874,	1496,	1907,	1828	},
{	1855,	1492,	1912,	1846	},
{	1836,	1488,	1916,	1865	},
{	1817,	1485,	1921,	1884	},
{	1797,	1481,	1860,	1904	},
{	1779,	1481,	1930,	1923	},
{	1760,	1474,	1934,	1941	},
{	1742,	1473,	1938,	1959	},
{	1724,	1466,	1942,	1978	},
{	1706,	1466,	1947,	1996	},
{	1688,	1462,	1951,	2013	},
{	1671,	1459,	1748,	2030	},
{	1659,	1456,	1961,	2046	},
{	1641,	1457,	1710,	2060	},
{	1626,	1477,	1690,	2074	},
{	1612,	1485,	1649,	2088	},
{	1598,	1449,	1630,	2101	},
{	1584,	1446,	1614,	2114	},
{	1570,	1444,	1621,	2128	},
{	1557,	1442,	1605,	2141	},
{	1361,	491,	2852,	674	},
{	1354,	494,	2849,	683	},
{	1491,	460,	1768,	1080	},
{	1202,	458,	1763,	1073	},
{	1201,	456,	1829,	1040	},
{	1200,	455,	1926,	1033	},
{	1198,	454,	1836,	1033	},
{	1198,	455,	1924,	1034	},
{	1198,	455,	1835,	1035	},
{	1197,	456,	1835,	1039	},
{	1195,	448,	1776,	1004	},
{	1194,	448,	1779,	1032	},
{	1193,	449,	1776,	1006	},
{	1191,	449,	1780,	980	},
{	1191,	450,	1780,	981	},
{	1190,	451,	1781,	986	},
{	1570,	453,	1936,	992	},
{	1206,	454,	1839,	999	},
{	1558,	455,	1840,	1006	},
{	1549,	456,	1845,	897	},
{	1817,	341,	2180,	827	},
{	1817,	341,	2180,	827	},
{	1818,	341,	2180,	827	},
{	1817,	340,	2180,	827	},
{	1816,	340,	2180,	828	},
{	1813,	340,	2179,	830	},
{	1809,	341,	2178,	835	},
{	950,	341,	2177,	839	},
{	941,	345,	2174,	846	},
{	928,	356,	2662,	854	},
{	2598,	461,	2105,	989	},
{	2586,	469,	2094,	925	},
{	1542,	492,	1867,	1052	},
{	1542,	491,	1865,	1051	},
{	1545,	490,	2005,	1046	},
{	1754,	489,	2063,	1045	},
{	1754,	489,	1932,	1045	},
{	1753,	489,	1970,	1046	},
{	1753,	489,	1938,	1046	},
{	1754,	489,	1971,	1046	},
{	1114,	465,	1777,	569	},
{	1109,	466,	1775,	569	},
{	1103,	466,	1777,	1086	},
{	1104,	468,	1778,	1027	},
{	1504,	469,	1779,	1034	},
{	1496,	470,	1781,	1041	},
{	1485,	472,	1783,	566	},
{	1476,	473,	1784,	567	},
{	1468,	475,	1789,	564	},
{	1460,	476,	1790,	568	}};

static     int  labels[num_points];
static     int  c[number_of_clusters][feature_number];
static     int  c1[number_of_clusters][feature_number];
static int counts[number_of_clusters];
//k_means( num_points, feature_number,arr, number_of_clusters, 1e-4 );
  volatile  int * k_means( int n, int m,int data[][m], int k, int t ) {
        /* output cluster label for each data point */

   volatile     int h, i, j; /* loop counters, of course :) */
   volatile     int old_error, error = IMAX; /* sum of squared euclidean distance */

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
for (int i = 0; i < num_points; i++) {
      printf("data point %d is in cluster %d\n", i, z[i]);
    }


	FILE *myfile = fopen("result_kmeans_robot_200.txt", "w");
	for (int i = 0; i < num_points; i++) {
       fprintf(myfile, "data point %d is in cluster %d\n", i, z[i]);
	 }

    return 0;

	}
