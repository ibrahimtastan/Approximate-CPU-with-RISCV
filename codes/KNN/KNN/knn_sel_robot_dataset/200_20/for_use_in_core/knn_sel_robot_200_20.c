// C++ program to find groups of unknown
// Points using K nearest neighbour algorithm.
// Dataset of wall-following-robot 200 data and 20 test data.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _Point
{
    int distance; // Distance from test point
    int x, y, z, k;     // Co-ordinate of point
    int val;     // Group of point
} Point;


int* knn(){


//arr = 0x200;
static Point arr [200] = {  {0,	1298,	504,	2816,	730,	1	},
							{0,	1285,	507,	2810,	742,	1	},
							{0,	1271,	511,	2800,	756,	1	},
							{0,	1256,	515,	2789,	771,	1	},
							{0,	1239,	520,	2777,	787,	1	},
							{0,	1223,	525,	2766,	807,	1	},
							{0,	1206,	530,	2753,	611,	1	},
							{0,	1188,	535,	2741,	621,	1	},
							{0,	1170,	541,	2727,	859,	1	},
							{0,	1152,	548,	2713,	878,	1	},
							{0,	981,	780,	2387,	1703,	1	},
							{0,	980,	780,	2391,	1606,	1	},
							{0,	979,	779,	2388,	1610,	1	},
							{0,	978,	779,	2385,	1614,	1	},
							{0,	978,	779,	2388,	1704,	1	},
							{0,	977,	779,	2388,	1708,	1	},
							{0,	976,	778,	2392,	1709,	1	},
							{0,	974,	778,	2392,	1710,	1	},
							{0,	972,	777,	2391,	1616,	1	},
							{0,	968,	777,	2390,	1624,	1	},
							{0,	961,	776,	2393,	1628,	1	},
							{0,	952,	775,	2387,	1642,	1	},
							{0,	937,	773,	2392,	2247,	1	},
							{0,	924,	775,	2398,	1669,	1	},
							{0,	910,	774,	2402,	1685,	1	},
							{0,	1815,	746,	2217,	926,	1	},
							{0,	1824,	835,	2150,	874,	1	},
							{0,	919,	747,	2241,	868,	1	},
							{0,	912,	746,	2663,	893,	1	},
							{0,	905,	742,	2160,	882,	1	},
							{0,	961,	500,	3177,	1228,	1	},
							{0,	951,	499,	3179,	1235,	1	},
							{0,	943,	498,	3181,	1245,	1	},
							{0,	1389,	497,	1595,	1265,	1	},
							{0,	1315,	499,	1600,	1271,	1	},
							{0,	1304,	502,	1606,	1280,	1	},
							{0,	1299,	504,	1618,	856,	1	},
							{0,	1358,	508,	1631,	865,	1	},
							{0,	1349,	512,	1640,	1076,	1	},
							{0,	1339,	516,	1653,	1323,	1	},
							{0,	1569,	791,	1331,	497,	1	},
							{0,	1566,	792,	1333,	502,	1	},
							{0,	1696,	788,	1337,	511,	1	},
							{0,	1685,	780,	1343,	521,	1	},
							{0,	1669,	775,	1349,	533,	1	},
							{0,	902,	616,	1355,	547,	1	},
							{0,	1637,	632,	1362,	562,	1	},
							{0,	1620,	753,	1370,	577,	1	},
							{0,	1596,	745,	1378,	594,	1	},
							{0,	1569,	737,	1385,	611,	1	},
							{0,	711,	540,	3166,	1255,	2	},
							{0,	679,	530,	3176,	1272,	2	},
							{0,	658,	521,	3199,	1291,	2	},
							{0,	650,	515,	3185,	1309,	2	},
							{0,	644,	509,	3191,	1325,	2	},
							{0,	639,	504,	3194,	1340,	2	},
							{0,	860,	504,	3201,	1348,	2	},
							{0,	859,	496,	3203,	1351,	2	},
							{0,	861,	491,	2430,	1349,	2	},
							{0,	865,	491,	3208,	1345,	2	},
							{0,	769,	820,	1343,	790,	2	},
							{0,	778,	800,	1355,	787,	2	},
							{0,	803,	792,	1360,	785,	2	},
							{0,	774,	789,	1345,	789,	2	},
							{0,	767,	788,	1349,	789,	2	},
							{0,	766,	782,	1355,	776,	2	},
							{0,	769,	791,	1360,	775,	2	},
							{0,	776,	767,	1370,	774,	2	},
							{0,	831,	761,	1441,	769,	2	},
							{0,	792,	758,	1905,	767,	2	},
							{0,	798,	502,	1352,	473,	2	},
							{0,	801,	503,	1336,	474,	2	},
							{0,	815,	511,	1334,	462,	2	},
							{0,	899,	726,	1386,	566,	2	},
							{0,	878,	718,	1393,	583,	2	},
							{0,	866,	711,	1400,	601,	2	},
							{0,	845,	697,	1415,	636,	2	},
							{0,	832,	690,	1421,	652,	2	},
							{0,	806,	682,	1433,	681,	2	},
							{0,	851,	670,	1444,	710,	2	},
							{0,	771,	1151,	1541,	735,	2	},
							{0,	875,	746,	1559,	728,	2	},
							{0,	818,	789,	1546,	725,	2	},
							{0,	768,	784,	1551,	723,	2	},
							{0,	767,	783,	1554,	720,	2	},
							{0,	767,	784,	1574,	722,	2	},
							{0,	770,	810,	1577,	718,	2	},
							{0,	773,	769,	2911,	713,	2	},
							{0,	786,	763,	2912,	711,	2	},
							{0,	797,	756,	2913,	709,	2	},
							{0,	879,	838,	1321,	528,	2	},
							{0,	816,	548,	1322,	524,	2	},
							{0,	812,	667,	1323,	518,	2	},
							{0,	811,	665,	1330,	519,	2	},
							{0,	814,	666,	1334,	519,	2	},
							{0,	817,	546,	1346,	520,	2	},
							{0,	837,	805,	1328,	509,	2	},
							{0,	835,	704,	1414,	683,	2	},
							{0,	806,	697,	1425,	701,	2	},
							{0,	791,	688,	1432,	719,	2	},
							{0,	1144,	2302,	1380,	2364,	3	},
							{0,	1325,	907,	1253,	522,	3	},
							{0,	1761,	902,	1247,	519,	3	},
							{0,	1070,	904,	2394,	5000,	3	},
							{0,	1052,	904,	1967,	1279,	3	},
							{0,	1036,	908,	2372,	1574,	3	},
							{0,	1018,	908,	2350,	1602,	3	},
							{0,	1001,	906,	2347,	1627,	3	},
							{0,	983,	910,	2783,	1631,	3	},
							{0,	967,	946,	2725,	1302,	3	},
							{0,	1629,	1412,	1677,	2047,	3	},
							{0,	1604,	1413,	1675,	2049,	3	},
							{0,	1603,	1413,	1675,	2050,	3	},
							{0,	1557,	1413,	1674,	2051,	3	},
							{0,	1556,	1413,	1673,	2053,	3	},
							{0,	1556,	1413,	1672,	2054,	3	},
							{0,	1558,	1413,	1673,	2055,	3	},
							{0,	1558,	1414,	1797,	2056,	3	},
							{0,	1558,	1413,	1782,	2058,	3	},
							{0,	1557,	1414,	1668,	2060,	3	},
							{0,	1276,	2253,	1447,	2199,	3	},
							{0,	1265,	1319,	1435,	2312,	3	},
							{0,	1254,	1324,	1423,	2299,	3	},
							{0,	1245,	1336,	1415,	2334,	3	},
							{0,	1234,	2293,	1405,	2364,	3	},
							{0,	1115,	2358,	1329,	2349,	3	},
							{0,	1098,	2365,	1323,	2431,	3	},
							{0,	1081,	2372,	1316,	2435,	3	},
							{0,	1014,	2401,	1289,	3486,	3	},
							{0,	997,	2407,	1283,	2480,	3	},
							{0,	1874,	1496,	1907,	1828,	3	},
							{0,	1855,	1492,	1912,	1846,	3	},
							{0,	1836,	1488,	1916,	1865,	3	},
							{0,	1817,	1485,	1921,	1884,	3	},
							{0,	1797,	1481,	1860,	1904,	3	},
							{0,	1779,	1481,	1930,	1923,	3	},
							{0,	1760,	1474,	1934,	1941,	3	},
							{0,	1742,	1473,	1938,	1959,	3	},
							{0,	1724,	1466,	1942,	1978,	3	},
							{0,	1706,	1466,	1947,	1996,	3	},
							{0,	1688,	1462,	1951,	2013,	3	},
							{0,	1671,	1459,	1748,	2030,	3	},
							{0,	1659,	1456,	1961,	2046,	3	},
							{0,	1641,	1457,	1710,	2060,	3	},
							{0,	1626,	1477,	1690,	2074,	3	},
							{0,	1612,	1485,	1649,	2088,	3	},
							{0,	1598,	1449,	1630,	2101,	3	},
							{0,	1584,	1446,	1614,	2114,	3	},
							{0,	1570,	1444,	1621,	2128,	3	},
							{0,	1557,	1442,	1605,	2141,	3	},
							{0,	1361,	491,	2852,	674,	4	},
							{0,	1354,	494,	2849,	683,	4	},
							{0,	1491,	460,	1768,	1080,	4	},
							{0,	1202,	458,	1763,	1073,	4	},
							{0,	1201,	456,	1829,	1040,	4	},
							{0,	1200,	455,	1926,	1033,	4	},
							{0,	1198,	454,	1836,	1033,	4	},
							{0,	1198,	455,	1924,	1034,	4	},
							{0,	1198,	455,	1835,	1035,	4	},
							{0,	1197,	456,	1835,	1039,	4	},
							{0,	1195,	448,	1776,	1004,	4	},
							{0,	1194,	448,	1779,	1032,	4	},
							{0,	1193,	449,	1776,	1006,	4	},
							{0,	1191,	449,	1780,	980,	4	},
							{0,	1191,	450,	1780,	981,	4	},
							{0,	1190,	451,	1781,	986,	4	},
							{0,	1570,	453,	1936,	992,	4	},
							{0,	1206,	454,	1839,	999,	4	},
							{0,	1558,	455,	1840,	1006,	4	},
							{0,	1549,	456,	1845,	897,	4	},
							{0,	1817,	341,	2180,	827,	4	},
							{0,	1817,	341,	2180,	827,	4	},
							{0,	1818,	341,	2180,	827,	4	},
							{0,	1817,	340,	2180,	827,	4	},
							{0,	1816,	340,	2180,	828,	4	},
							{0,	1813,	340,	2179,	830,	4	},
							{0,	1809,	341,	2178,	835,	4	},
							{0,	950,	341,	2177,	839,	4	},
							{0,	941,	345,	2174,	846,	4	},
							{0,	928,	356,	2662,	854,	4	},
							{0,	2598,	461,	2105,	989,	4	},
							{0,	2586,	469,	2094,	925,	4	},
							{0,	1542,	492,	1867,	1052,	4	},
							{0,	1542,	491,	1865,	1051,	4	},
							{0,	1545,	490,	2005,	1046,	4	},
							{0,	1754,	489,	2063,	1045,	4	},
							{0,	1754,	489,	1932,	1045,	4	},
							{0,	1753,	489,	1970,	1046,	4	},
							{0,	1753,	489,	1938,	1046,	4	},
							{0,	1754,	489,	1971,	1046,	4	},
							{0,	1114,	465,	1777,	569,	4	},
							{0,	1109,	466,	1775,	569,	4	},
							{0,	1103,	466,	1777,	1086,	4	},
							{0,	1104,	468,	1778,	1027,	4	},
							{0,	1504,	469,	1779,	1034,	4	},
							{0,	1496,	470,	1781,	1041,	4	},
							{0,	1485,	472,	1783,	566,	4	},
							{0,	1476,	473,	1784,	567,	4	},
							{0,	1468,	475,	1789,	564,	4	},
							{0,	1460,	476,	1790,	568,	4	} };


//test = 0x100;

static Point test [20] = {  {0,	1355,	484,	1829,	579,	0	},
							{0,	1687,	449,	2332,	429,	0	},
							{0,	1522,	488,	1823,	1264,	0	},
							{0,	684,	740,	2949,	1673,	0	},
							{0,	1647,	1394,	1790,	1968,	0	},
							{0,	1355,	689,	2226,	901,	0	},
							{0,	1336,	684,	1431,	920,	0	},
							{0,	1318,	677,	2254,	939,	0	},
							{0,	1195,	2202,	1488,	2228,	0	},
							{0,	815,	662,	2464,	1226,	0	},
							{0,	801,	667,	2454,	1241,	0	},
							{0,	1415,	494,	1798,	830,	0	},
							{0,	5000,	427,	1439,	396,	0	},
							{0,	787,	723,	1541,	747,	0	},
							{0,	786,	722,	1543,	744,	0	},
							{0,	1511,	490,	1820,	1270,	0	},
							{0,	1501,	492,	1816,	1280,	0	},
							{0,	1271,	511,	2800,	756,	0	},
							{0,	1011,	771,	2323,	1827,	0	},
							{0,	1005,	933,	1233,	2326,	0	}};

    int n = 200; // Number of data points

    /*Testing Point*/

    // Parameter to decide groups of the testing point
    int k = 3;
    int class[20] ;
    //int* class = ;
    for (int z = 0; z < 20; z++){
		   // class[z] = 1 ;
			class[z] = classifyAPoint(arr, n, k, test[z]) ;
			//printf("\n Classified as %d\n", class[z]);


	}
	return class;

}

// http://www.bytecraft.com/Fixed_Point_Converter

//int* a; a = 0x100;    256
//int* b; b = 0x200;	512

// Used to sort an array of points by increasing
// order of distance


void selectionsort(Point* arr, int size, int amount)

{

    for (int i = 0; i < amount; i++)

    {

        int min = i;

        for (int j = i; j <= size-1; j++)

        {

            if (arr[j].distance < arr[min].distance)

            {

                min = j;

            }

        }

	Point temp = arr[i] ;
	arr[i] = arr[min] ;
	 arr[min]  = temp;
       // swap(arr[i], );

    }


}

// This function finds classification of point p using
// k nearest neighbour algorithm. It assumes only two
// groups and returns 0 if p belongs to group 0, else
// 1 (belongs to group 1).
int classifyAPoint(Point* arr, int n, int k, Point p)
{
    // Fill distances of all points from p
    for (int i = 0; i < n; i++){
        arr[i].distance =
            	(arr[i].x - p.x) * (arr[i].x - p.x) +
                 (arr[i].z - p.z) * (arr[i].z - p.z) + //sqrt
                 (arr[i].k - p.k) * (arr[i].k - p.k) +
                 (arr[i].y - p.y) * (arr[i].y - p.y);

                 //printf(" %d ", arr[i].distance);
    }

    // Sort the Points by distance from p
    selectionsort(arr, n,k);
    //   printf("\n as \n");

   //  for (int i = 0; i < n; i++){
     //  printf("%d ", arr[i].distance);
     //  printf(": %d / ", arr[i].x);


   // }
           // printf("\n");

    // Now consider the first k elements and only
    // 4 groups
    int freq1 = 0;     // Frequency of group 1
    int freq2 = 0;     // Frequency of group 2
    int freq3 = 0;     // Frequency of group 3
    int freq4 = 0;     // Frequency of group 4
    for (int i = 0; i < k; i++)
    {
        if (arr[i].val == 1)
            freq1++;
           // printf("freq1 = %d\n",freq1);
        else if (arr[i].val == 2)
            freq2++;
           // printf("freq2 = %d\n",freq2);
	    else if (arr[i].val == 3)
            freq3++;
          //  printf("freq3 = %d\n",freq3);
        else if (arr[i].val == 4)
            freq4++;
         //   printf("freq4 = %d\n",freq4);
    }
	//	return 1;

	if (freq1 >= freq3 && freq1 >= freq2 && freq1 >= freq4)
		return 1;
	if (freq2 >= freq1 && freq2 >= freq3 && freq2 >= freq4)
		return 2;
	if (freq3 >= freq2 && freq3 >= freq1 && freq3 >= freq4)
		return 3;
    if (freq4 >= freq2 && freq4 >= freq1 && freq4 >= freq3)
		return 4;
}

// Driver code
int main()
{

int* i;
i = knn();

    return 0;
}
