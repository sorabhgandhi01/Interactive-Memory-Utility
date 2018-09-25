#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdint.h>

#include"memalloc.h"
#include"memfree.h"
#include"memdisplay.h"
#include"memwrite.h"
#include"xorinvert.h"
#include"help.h"

#if 0
int main(){
    uint32_t n;
    char inp[20];
    uint32_t numBytes;
    uint32_t *addr = NULL,*p = NULL;
    double timeTaken;
    uint32_t size; 
    char ans;
    do{
        printf("Enter function you want to perform :\n");
	scanf("%s", inp);
 	if(strcmp("memalloc", inp) == 0){
	    p = memAlloc(&size, &n);
	}
	else if(strcmp("displaymem", inp) == 0){
	    printf("Enter the number of 32 bit words to display :\n");
	    scanf("%d", &numBytes); //Input number of words to be displayed
	    displayMem(p, p+1, size, n, numBytes);
	}
	else if(strcmp("writemem", inp) == 0){
	    addr = p;
	    memWrite(p, addr+1, n);
	}
	else if(strcmp("invert", inp) == 0){
	    timeTaken = xorInvert(p, n);
	    printf("The time taken for the invert is: %f seconds\n", timeTaken);
	}
	else if(strcmp("memfree", inp) == 0){
	    p = memFree(p);
	    if(p == NULL) printf("P IS NULL\n");
	}
	else{
	    printf("Invalid selection\n");
	}
	printf("Do you want to continue? \n");
	scanf(" %c", &ans);
    }while(ans == 'y');

    if(p != NULL){
	printf("Freeing allocated memory because you forgot to!\n");
	memFree(p);
    }
return(0);
}
#endif

int main ()
{
	printf("Welcome \n");

	help();

	return 0;
}
