#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#define XLEN 32

uint32_t fast_clz32(uint32_t rs1)
{
if (rs1 == 0)
return XLEN;
assert(sizeof(int) == 4);
return __builtin_clz(rs1);
}

// int main(){

	// uint32_t a = 234567;
	// uint32_t b = 0;

	// b =fast_clz32(a);
	// printf("number of leading zero is = %d\n", b);
// return 0;
// }
