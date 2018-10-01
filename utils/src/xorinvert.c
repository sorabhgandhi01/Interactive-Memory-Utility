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

mem_status invert_memory(char arg[])
{
	clock_t t;
	t = clock();

	char addr[15];
	char r_bytes[5];

	sscanf(arg, "%s %s", addr, r_bytes);

	uint64_t useraddr = chtol(addr);
	uint32_t block = chtoi(r_bytes);
        uint32_t i = 0, flag = 0, j = 0;

        for (i = 0; i < g_nblock; i++)
        {
                if ((uint64_t *) &g_blockptr[i] == (uint64_t *) useraddr) {
			//g_blockptr[i] = (g_blockptr[i]^0xFFFFFFFF);
                        printf("Inverted Data at memory address %p is %x\n", &g_blockptr[i], (g_blockptr[i]^0xFFFFFFFF));
			
			if ((block != 0) && (block <= (g_nblock - (i+1))))
			{
				for (j = (i+1); j < (block + i); j++)
					printf("Inverted Data at memory address %p is %x\n", &g_blockptr[j], (g_blockptr[j]^0xFFFFFFFF));
				
				flag = 1;
                        	break;
			}
			else if(block == 0)
			{
				flag = 1;
				break;
			}
			else {
				printf("Invalid number of 32-bit words\n");
				return FAILED;
			}
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
