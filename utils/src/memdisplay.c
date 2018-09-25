#include<stdio.h>
#include<stdint.h>
//#include<memdisplay.h>

void displayMem(uint32_t *ptr, uint32_t *userAddr, uint32_t size, uint32_t n, uint32_t numBytes){
    uint32_t i, index;//, dummy;
/*    uint32_t shifter = 1;
    for(i=0;i<(numBytes*4);i++){
	shifter *= 2;
    }*/
  //  printf("Shifter value :%d\n",shifter);
    printf("The first address of the allocated block is : %p\n",&ptr[0]);
    printf("The last address of the allocated block is : %p\n", &ptr[n-1]);
    for(i=0;i<n;i++){
//	dummy = ptr[i];
//	dummy = (dummy & (shifter-1));
	printf("The contents of the memory in hexadecimal format is as follows: %0x\n", ptr[i]);
    }
    for(i=0;i<n;i++){
	if(ptr[i] == (int)(*userAddr)){
	    index = i;
	    break;
	}
    }
    printf("The index of the user entered value is :%d\n", index);
    printf("User entered address is :%x\n", *userAddr);
    for(i=index;i<=numBytes;i++){
	printf("%x\n", ptr[i]);
    }
    printf("The amount of memory allocated is : %d\n",size);
}
   
