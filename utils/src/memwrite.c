#include<stdio.h>
#include<stdint.h>
//#include<memwrite.h>

void memWrite(uint32_t *ptr, uint32_t *addr, uint32_t n){
    uint32_t i, userNum;
    printf("Enter the number to be written :\n");
    scanf("%d", &userNum);
    printf("The user entered address is: %p\n",addr);
    addr =  (uint32_t*)addr;
    *addr = userNum;
    printf("The value at the address %p is: %d\n",addr,userNum);
    for(i=0;i<n;i++){      
 	printf("p[%d] = %d\n",i,ptr[i]);
    }
}
