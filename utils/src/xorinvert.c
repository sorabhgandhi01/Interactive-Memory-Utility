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
 * @\file	xorinvert.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of invert functionality of memory utils
 * @\date	09/25/2018
 *
 */											   

/* System headers */
#include <time.h>

/* Own headers */
#include <xorinvert.h>

#if 0
void xorInvert(uint32_t ptr, uint32_t data)
{
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
#endif

mem_status invert_memory(char arg[], char arg2[])
{
	uint64_t useraddr = atol(arg);
        uint32_t i = 0, flag = 0;

	clock_t t;
	t = clock();

        for (i = 0; i < g_nblock; i++)
        {
                uint64_t *temp = (uint64_t *)&g_blockptr[i];

                if (temp == useraddr) {
			//g_blockptr[i] = (g_blockptr[i]^0xFFFFFFFF);
                        printf("Inverted Data at memory address %p is %x\n", temp, (g_blockptr[i]^0xFFFFFFFF));
                        flag = 1;
                        break;
                }
        }

        if (flag != 1) {
                printf("Invalid memory address\n");
                return FAILED;
        }

	t = clock() - t;
	printf("Time taken to perform this operation is %f\n", ((double)t/CLOCKS_PER_SEC));

	return SUCCESS;
}
