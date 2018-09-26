/*----------------------------------------------------------------------------------------
MIT License

Copyright (c) 2018 Sorabh Gandhi / Sanju Prakash Kannioth

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE
-----------------------------------------------------------------------------------------*/

/**
 * @\file	memdisplay.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of memory display functionality for memory utils
 * @\date	09/25/2018
 *
 */											   

/* System headers */
#include <stdio.h>
#include <stdint.h>

/* Own headers */
#include <memdisplay.h>

void displayMem(uint32_t *userAddr, uint32_t n_block)
{
#if 0
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
#endif
}
   
