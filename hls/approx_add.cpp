#include <stdint.h>
#include <stdio.h>
#include "datapath.hpp"
/// Approximate function add8_000
///  Library = EvoApprox8b
///  Circuit = add8_000
///  Area   (180) = 820
///  Delay  (180) = 1.350
///  Power  (180) = 218.00
///  Area   (45) = 59
///  Delay  (45) = 0.500
///  Power  (45) = 21.53
///  Nodes = 10
///  HD = 138496
///  MAE = 1.71875
///  MSE = 6.00000
///  MRE = 0.88 %
///  WCE = 7
///  WCRE = 100 %
///  EP = 71.9 %
int32_t approx_add(int32_t a, int32_t b, uint8_t approx_add_size, uint8_t add_sub)
{
  int32_t c = 0;
  uint32_t n0 = (a >> 0) & 0x1;
  uint32_t n2 = (a >> 1) & 0x1;
  uint32_t n4 = (a >> 2) & 0x1;
  uint32_t n6 = (a >> 3) & 0x1;
  uint32_t n8 = (a >> 4) & 0x1;
  uint32_t n10 = (a >> 5) & 0x1;
  uint32_t n12 = (a >> 6) & 0x1;
  uint32_t n14 = (a >> 7) & 0x1;
  uint32_t n18 = (b >> 1) & 0x1;
  uint32_t n20 = (b >> 2) & 0x1;
  uint32_t n22 = (b >> 3) & 0x1;
  uint32_t n24 = (b >> 4) & 0x1;
  uint32_t n26 = (b >> 5) & 0x1;
  uint32_t n28 = (b >> 6) & 0x1;
  uint32_t n30 = (b >> 7) & 0x1;
  uint32_t n32;
  uint32_t n43;
  uint32_t n61;
  uint32_t n82;
  uint32_t n132;
  uint32_t n182;
  uint32_t n183;
  uint32_t n232;
  uint32_t n233;
  uint32_t n282;
  uint32_t n283;
  uint32_t n332;
  uint32_t n333;
  uint32_t n382;
  uint32_t n383;


  n32 = ~(n20 & n4 & n0);
  n43 = ~(n32 | n14 | n30);
  n61 = ~(n18 ^ n18);
  n82 = n2 | n18;
  n132 = n4 | n20;
  n182 = (n6 ^ n22) ^ n43;
  n183 = (n6 & n22) | (n22 & n43) | (n6 & n43);
  n232 = (n8 ^ n24) ^ n183;
  n233 = (n8 & n24) | (n24 & n183) | (n8 & n183);
  n282 = (n10 ^ n26) ^ n233;
  n283 = (n10 & n26) | (n26 & n233) | (n10 & n233);
  n332 = (n12 ^ n28) ^ n283;
  n333 = (n12 & n28) | (n28 & n283) | (n12 & n283);
  n382 = (n14 ^ n30) ^ n333;
  n383 = (n14 & n30) | (n30 & n333) | (n14 & n333);

  c |= (n61 & 0x1) << 0;
  c |= (n82 & 0x1) << 1;
  c |= (n132 & 0x1) << 2;
  c |= (n182 & 0x1) << 3;
  c |= (n232 & 0x1) << 4;
  c |= (n282 & 0x1) << 5;
  c |= (n332 & 0x1) << 6;
  c |= (n382 & 0x1) << 7;
  c |= (n383 & 0x1) << 8;
 // added to create 32-bits
  c |= (n61 & 0x1) << 9;
  c |= (n82 & 0x1) << 10;
  c |= (n82 & 0x1) << 11;
  c |= (n132 & 0x1) << 12;
  c |= (n182 & 0x1) << 13;
  c |= (n232 & 0x1) << 14;
  c |= (n282 & 0x1) << 15;
  c |= (n332 & 0x1) << 16;
  c |= (n382 & 0x1) << 17;
  c |= (n383 & 0x1) << 18;
  c |= (n383 & 0x1) << 19;
  c |= (n61 & 0x1) << 20;
  c |= (n82 & 0x1) << 21;
  c |= (n132 & 0x1) << 22;
  c |= (n182 & 0x1) << 23;
  c |= (n232 & 0x1) << 24;
  c |= (n282 & 0x1) << 25;
  c |= (n332 & 0x1) << 26;
  c |= (n382 & 0x1) << 27;
  c |= (n383 & 0x1) << 28;
  c |= (n383 & 0x1) << 29;
  c |= (n282 & 0x1) << 30;
  c |= (n383 & 0x1) << 31;

  c = c << approx_add_size + add_sub;


  return c;
}

