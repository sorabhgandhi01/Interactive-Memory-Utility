#include<stdio.h>
#include<time.h>
#include<stdint.h>
//#include<xorinvert.h>

double xorInvert(uint32_t *ptr, uint32_t n){
    uint32_t i;
    clock_t t;
    t = clock();
    printf("Inverting the given inputs using XOR gates we get: \n");
    for(i=0;i<n;i++){
        printf("NOT of p[%d] is : %d\n",i,(ptr[i]^0xFFFFFFFF));
	//printf("NOT of p[%d] is : %d\n",i,~(ptr[i]));
    }
    t = clock() - t;
    double time_taken = ((double)t/CLOCKS_PER_SEC);
    return time_taken;
}
