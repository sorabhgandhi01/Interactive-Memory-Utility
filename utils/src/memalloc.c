/*----------------------------------------------------------------------------------------
MIT License

Copyright (c) 2018 Sorabh Gandhi / Sanju Prakash

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
 * @\file	memalloc.c
 * @\author	Sorabh Gandhi / Sanju Prakash
 * @\brief	This file contains the definition of memeory allocation functionality of memory utils
 * @\date	09/25/2018
 *
 */											   

/* System headers */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Own headers */
#include "memalloc.h"

int memAlloc (uint32_t n)
{
#if 0
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
#endif
    return 0;
}
