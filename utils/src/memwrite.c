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
 * @\file	memwrite.c
 * @\author	Sorabh Gandhi / Sanju Prakash
 * @\brief	This file contains the definition of memory write functionality of memory utils
 * @\date	09/25/2018
 *
 */											   

/* System headers */
#include <stdio.h>
#include <stdint.h>

/* Own headers */
#include <memwrite.h>

void memWrite(uint32_t addr, uint32_t data)
{
#if 0
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
#endif
}
