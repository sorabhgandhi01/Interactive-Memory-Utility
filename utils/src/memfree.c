#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<assert.h>


uint32_t *memFree(uint32_t *ptr){
    free(ptr);
    ptr = NULL;
    if(!ptr) 
    printf("The memory block allocated has been successfully freed!\n");
    return ptr;
}
