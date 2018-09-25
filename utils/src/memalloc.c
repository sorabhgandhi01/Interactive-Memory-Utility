#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
//#include<memalloc.h>

uint32_t *memAlloc (uint32_t *size, uint32_t *n){
    uint32_t i;
    printf("Enter the number of blocks to be allocated :\n");
    scanf("%d", n);
    *size = (*n)*sizeof(uint32_t);
    uint32_t *ptr =(uint32_t*) malloc(*size);
/*    for(i=0,j=12313;i<(*n);i++,j++){
	ptr[i] = j;
    }*/
    for(i=0;i<(*n);i++){
	scanf("%d", &ptr[i]);
    }

    for(i=0;i<(*n);i++){
	printf("p[%d] = %d\n",i,ptr[i]);
    }
    return ptr;
}
