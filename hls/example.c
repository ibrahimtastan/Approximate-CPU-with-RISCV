#include <stdio.h>

int main(void) { 

int* a;
int* b ;

a = 0x200;
b = 0x100 ;

int sum = 0;
for(int i = 0;i<8 ; i++){
	a[i] = (2*i+2);
	b[i] =  (2*i+1);
	
}

for(int i = 0;i<8 ; i++){
	sum += a[i] * b[i] ;
	
}

//printf("sum %d\n",sum);
sum /= 8;

//printf("sum %d\n",sum);

return 0; }
