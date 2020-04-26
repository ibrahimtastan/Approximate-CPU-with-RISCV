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


 #define num_points  300
 #define feature_number  4
 #define number_of_clusters  2
static int arr [300][4] = {
{	616	,	3894	,	4727	,	4394	},
{	5441	,	7236	,	109	,	7564	},
{	300	,	173	,	1754	,	489	},
{	1340	,	4132	,	4701	,	2598	},
{	268	,	4987	,	5150	,	6391	},
{	6523	,	9601	,	253	,	6964	},
{	4067	,	2495	,	795	,	1103	},
{	2564	,	1705	,	1502	,	327	},
{	1341	,	1916	,	155	,	119	},
{	238	,	2087	,	3352	,	665	},
{	621	,	3677	,	4077	,	2071	},
{	778	,	3401	,	3485	,	3556	},
{	4124	,	3790	,	653	,	4180	},
{	7042	,	9200	,	259	,	4683	},
{	4946	,	3571	,	827	,	1495	},
{	3535	,	304	,	656	,	295	},
{	2066	,	169	,	1005	,	829	},
{	887	,	2808	,	3143	,	1203	},
{	1094	,	2307	,	2523	,	1445	},
{	2445	,	1628	,	885	,	1480	},
{	3551	,	1895	,	186	,	2440	},
{	2281	,	856	,	2718	,	44	},
{	3605	,	5974	,	10091	,	828	},
{	5067	,	5187	,	10426	,	867	},
{	3920	,	4072	,	236	,	2115	},
{	1130	,	1845	,	1357	,	1380	},
{	2456	,	4556	,	6453	,	56	},
{	4477	,	13030	,	17083	,	3034	},
{	4195	,	8181	,	12129	,	1601	},
{	3380	,	707	,	2532	,	718	},
{	2436	,	3602	,	1416	,	2894	},
{	776	,	130	,	31	,	353	},
{	2708	,	6826	,	7533	,	590	},
{	4553	,	12585	,	15441	,	1498	},
{	3889	,	7832	,	9820	,	474	},
{	2508	,	227	,	1488	,	1206	},
{	2165	,	3021	,	2413	,	2424	},
{	1897	,	3507	,	1784	,	3849	},
{	620	,	558	,	385	,	664	},
{	1838	,	6301	,	5650	,	195	},
{	25	,	3399	,	4432	,	4265	},
{	4396	,	4960	,	648	,	5471	},
{	2456	,	244	,	1404	,	458	},
{	2620	,	6855	,	6216	,	622	},
{	2966	,	10325	,	8784	,	2113	},
{	714	,	4444	,	2224	,	498	},
{	600	,	999	,	2212	,	97	},
{	2790	,	5713	,	5953	,	459	},
{	1998	,	6607	,	4825	,	419	},
{	154	,	117	,	1682	,	595	},
{	1208	,	4074	,	4763	,	2612	},
{	295	,	4885	,	5149	,	6232	},
{	6424	,	9531	,	22	,	6851	},
{	3993	,	2621	,	628	,	1159	},
{	2659	,	1605	,	1364	,	164	},
{	1409	,	2125	,	103	,	192	},
{	110	,	1974	,	3366	,	652	},
{	523	,	3644	,	4074	,	1990	},
{	767	,	3459	,	3440	,	3427	},
{	3969	,	3681	,	600	,	4013	},
{	7036	,	9293	,	165	,	4539	},
{	4944	,	3300	,	1063	,	1444	},
{	3593	,	229	,	712	,	333	},
{	2167	,	124	,	1046	,	862	},
{	960	,	2696	,	3122	,	1312	},
{	1080	,	2199	,	2586	,	1275	},
{	2327	,	1438	,	821	,	1286	},
{	3724	,	1903	,	35	,	2509	},
{	2572	,	956	,	2707	,	166	},
{	3929	,	6081	,	10095	,	1014	},
{	5294	,	5146	,	10333	,	1118	},
{	3895	,	4039	,	301	,	2183	},
{	1224	,	1748	,	1480	,	1418	},
{	2640	,	4415	,	5983	,	139	},
{	4633	,	12750	,	16716	,	3216	},
{	4288	,	7863	,	11838	,	1897	},
{	3345	,	504	,	2632	,	537	},
{	1118	,	3335	,	1345	,	1957	},
{	559	,	310	,	183	,	446	},
{	1507	,	7319	,	7898	,	1228	},
{	3506	,	12566	,	15160	,	752	},
{	2949	,	8273	,	10264	,	1162	},
{	1602	,	389	,	1620	,	1910	},
{	1266	,	2818	,	2426	,	1886	},
{	492	,	3060	,	1835	,	2834	},
{	663	,	45	,	187	,	234	},
{	720	,	6758	,	5840	,	623	},
{	1996	,	9500	,	9682	,	128	},
{	973	,	6416	,	5602	,	1032	},
{	25	,	173	,	113	,	1219	},
{	62	,	2930	,	3546	,	2673	},
{	5525	,	6325	,	897	,	6624	},
{	1294	,	2673	,	840	,	2032	},
{	240	,	1783	,	2135	,	1241	},
{	1396	,	9669	,	9465	,	348	},
{	2967	,	13286	,	13472	,	2627	},
{	1100	,	7250	,	6013	,	368	},
{	224	,	521	,	403	,	1201	},
{	904	,	3370	,	4498	,	3696	},
{	2861	,	4519	,	581	,	4262	},
{	1083	,	312	,	1281	,	412	},
{	1568	,	7244	,	6553	,	127	},
{	2054	,	10867	,	9492	,	1411	},
{	234	,	4515	,	2119	,	1444	},
{	1581	,	869	,	2313	,	824	},
{	1551	,	3801	,	4914	,	3748	},
{	4147	,	7122	,	83	,	6417	},
{	2262	,	99	,	2812	,	486	},
{	1747	,	5823	,	5869	,	1212	},
{	959	,	6712	,	4985	,	328	},
{	1345	,	235	,	1878	,	1325	},
{	2227	,	4095	,	4803	,	2111	},
{	1257	,	4873	,	5286	,	5874	},
{	5385	,	9121	,	419	,	5918	},
{	2978	,	2344	,	526	,	401	},
{	1585	,	2156	,	1708	,	901	},
{	218	,	2203	,	95	,	564	},
{	1318	,	1901	,	3311	,	65	},
{	1489	,	3428	,	4030	,	1425	},
{	115	,	3221	,	3430	,	2845	},
{	3392	,	3356	,	720	,	3523	},
{	6163	,	8709	,	216	,	3634	},
{	4078	,	2923	,	870	,	653	},
{	2589	,	391	,	934	,	429	},
{	1011	,	190	,	905	,	3	},
{	66	,	2491	,	2940	,	621	},
{	247	,	1936	,	2469	,	805	},
{	1573	,	1063	,	712	,	838	},
{	2166	,	1593	,	45	,	1678	},
{	1166	,	1423	,	2924	,	661	},
{	2839	,	6630	,	10484	,	421	},
{	4504	,	5812	,	10886	,	528	},
{	2410	,	3743	,	402	,	1295	},
{	406	,	1349	,	1450	,	559	},
{	1388	,	4877	,	6477	,	341	},
{	3750	,	13458	,	17593	,	2777	},
{	3563	,	8382	,	12393	,	1282	},
{	2541	,	658	,	2684	,	1195	},
{	1666	,	300	,	1423	,	24	},
{	2096	,	7105	,	6618	,	337	},
{	2668	,	10451	,	9113	,	1732	},
{	474	,	4349	,	1990	,	751	},
{	1055	,	1185	,	2641	,	110	},
{	1164	,	3809	,	4940	,	4090	},
{	4477	,	7370	,	312	,	6775	},
{	2733	,	455	,	2439	,	217	},
{	2286	,	5448	,	5803	,	882	},
{	1624	,	6344	,	4657	,	169	},
{	508	,	477	,	1980	,	577	},
{	1640	,	4250	,	4902	,	2662	},
{	2741	,	11403	,	2539	,	5579	},
{	3366	,	5185	,	3693	,	1142	},
{	4559	,	2421	,	2641	,	1616	},
{	5112	,	498	,	628	,	1118	},
{	3339	,	4614	,	3982	,	237	},
{	4202	,	227	,	961	,	972	},
{	3543	,	1239	,	1997	,	2154	},
{	2313	,	10665	,	3528	,	4767	},
{	1858	,	7886	,	1664	,	1838	},
{	3106	,	9541	,	4253	,	4003	},
{	2916	,	10830	,	3343	,	4122	},
{	3992	,	4467	,	3730	,	109	},
{	1518	,	5694	,	94	,	26	},
{	3235	,	9647	,	3207	,	2594	},
{	4218	,	6816	,	1280	,	760	},
{	1781	,	6917	,	1274	,	1575	},
{	2533	,	2913	,	822	,	122	},
{	3896	,	7416	,	1824	,	140	},
{	2108	,	6795	,	170	,	490	},
{	2896	,	707	,	2290	,	1866	},
{	929	,	3797	,	4642	,	295	},
{	3464	,	10687	,	3407	,	4109	},
{	4071	,	10402	,	4172	,	4758	},
{	1457	,	9121	,	1742	,	5124	},
{	1507	,	1922	,	7146	,	891	},
{	917	,	9988	,	1180	,	5226	},
{	2994	,	7201	,	1215	,	321	},
{	2343	,	12951	,	3328	,	5942	},
{	3781	,	2884	,	2255	,	157	},
{	4668	,	1309	,	55	,	1909	},
{	3466	,	1111	,	1742	,	1338	},
{	3269	,	4341	,	3688	,	298	},
{	5130	,	8670	,	2891	,	1508	},
{	2013	,	6141	,	379	,	569	},
{	433	,	5539	,	2033	,	404	},
{	1040	,	9398	,	859	,	5333	},
{	4160	,	11219	,	3613	,	4081	},
{	5438	,	9466	,	4941	,	3920	},
{	5032	,	8202	,	2625	,	1034	},
{	5241	,	10538	,	4117	,	4279	},
{	206	,	9220	,	3704	,	6810	},
{	2091	,	943	,	4551	,	1234	},
{	1731	,	347	,	4190	,	991	},
{	4173	,	3333	,	1424	,	604	},
{	3923	,	3246	,	3457	,	837	},
{	3848	,	10153	,	3856	,	4222	},
{	519	,	3263	,	3089	,	984	},
{	3858	,	784	,	1103	,	1700	},
{	1749	,	175	,	5182	,	1292	},
{	3627	,	982	,	688	,	634	},
{	2739	,	7401	,	71	,	2530	},
{	4544	,	8227	,	2416	,	1587	},
{	1759	,	11921	,	2675	,	3324	},
{	5069	,	213	,	202	,	1209	},
{	3459	,	11112	,	4203	,	5093	},
{	1935	,	8165	,	23	,	2258	},
{	2486	,	995	,	5340	,	154	},
{	2422	,	4575	,	5947	,	215	},
{	3947	,	3772	,	2883	,	19	},
{	2263	,	4486	,	3655	,	612	},
{	1356	,	4235	,	2134	,	321	},
{	5045	,	3896	,	1430	,	862	},
{	3549	,	8616	,	3279	,	1200	},
{	173	,	7869	,	268	,	3788	},
{	2400	,	9359	,	3356	,	3352	},
{	4885	,	1599	,	0	,	1640	},
{	4192	,	3267	,	2583	,	217	},
{	1116	,	8649	,	962	,	1811	},
{	1023	,	6901	,	2006	,	2712	},
{	1803	,	11881	,	2045	,	5272	},
{	117	,	6276	,	1549	,	2474	},
{	570	,	24	,	1242	,	562	},
{	4055	,	2458	,	2280	,	1032	},
{	1695	,	1065	,	8829	,	949	},
{	1119	,	10727	,	2093	,	5650	},
{	1879	,	2470	,	2493	,	376	},
{	3583	,	3797	,	3439	,	125	},
{	190	,	9129	,	3725	,	5822	},
{	3658	,	5686	,	1715	,	237	},
{	131	,	1777	,	8331	,	352	},
{	2392	,	9798	,	3036	,	2822	},
{	1642	,	3014	,	228	,	147	},
{	117	,	1578	,	8030	,	28	},
{	695	,	8616	,	1841	,	4328	},
{	2942	,	7410	,	977	,	884	},
{	1755	,	11945	,	3094	,	4897	},
{	1253	,	10880	,	1931	,	4323	},
{	3258	,	4461	,	3802	,	150	},
{	1831	,	6367	,	36	,	49	},
{	4564	,	3627	,	2868	,	277	},
{	2736	,	5032	,	6660	,	578	},
{	929	,	3797	,	4642	,	295	},
{	3966	,	10168	,	4113	,	4605	},
{	1457	,	84	,	4178	,	591	},
{	4827	,	3068	,	686	,	807	},
{	2341	,	12378	,	704	,	7583	},
{	1858	,	7886	,	1664	,	1838	},
{	4145	,	7257	,	1915	,	860	},
{	1915	,	6081	,	237	,	2011	},
{	4021	,	2191	,	2464	,	1140	},
{	5886	,	5874	,	2816	,	300	},
{	2089	,	10826	,	2360	,	3419	},
{	4002	,	3594	,	3557	,	268	},
{	786	,	9566	,	3786	,	7503	},
{	4175	,	10261	,	3855	,	4305	},
{	832	,	7540	,	650	,	925	},
{	4807	,	2232	,	263	,	1553	},
{	5306	,	5268	,	2890	,	527	},
{	2560	,	9268	,	3591	,	1356	},
{	2105	,	7604	,	477	,	1846	},
{	2172	,	738	,	5467	,	723	},
{	4289	,	9181	,	4606	,	4326	},
{	3515	,	10189	,	4275	,	4978	},
{	2614	,	8008	,	3725	,	1306	},
{	680	,	2325	,	4908	,	549	},
{	4196	,	744	,	832	,	753	},
{	6091	,	2967	,	1326	,	1455	},
{	1323	,	3296	,	236	,	119	},
{	1326	,	1032	,	5656	,	413	},
{	167	,	7627	,	1206	,	3624	},
{	1300	,	10267	,	2953	,	5863	},
{	2226	,	12539	,	2943	,	3525	},
{	2419	,	6466	,	756	,	228	},
{	1098	,	639	,	5989	,	582	},
{	4646	,	10532	,	4585	,	4206	},
{	360	,	4115	,	3114	,	371	},
{	1356	,	3213	,	4346	,	786	},
{	570	,	24	,	1242	,	562	},
{	2647	,	10137	,	1331	,	5470	},
{	3121	,	3137	,	1925	,	374	},
{	5494	,	1547	,	41	,	1928	},
{	1338	,	1552	,	7080	,	1031	},
{	2336	,	11960	,	3083	,	5443	},
{	2259	,	33	,	4735	,	277	},
{	469	,	633	,	7384	,	365	},
{	2729	,	2870	,	511	,	509	},
{	2046	,	2030	,	2176	,	83	},
{	1327	,	9498	,	2440	,	5268	},
{	3890	,	2152	,	2630	,	1104	},
{	3999	,	904	,	1169	,	1689	},
{	2395	,	9508	,	3178	,	3008	},
{	3270	,	6932	,	1045	,	234	},
{	1393	,	1566	,	7538	,	784	},
{	1640	,	3548	,	1396	,	364	},
{	2774	,	6857	,	1067	,	75	},
{	2428	,	9382	,	3247	,	1454	},
{	4213	,	2806	,	2011	,	674	},
{	1647	,	482	,	4744	,	1225	},
{	2059	,	993	,	5211	,	293	},
{	379	,	709	,	757	,	444	}
};

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

volatile	int * z = k_means( num_points, feature_number,arr, number_of_clusters, 100 );
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
