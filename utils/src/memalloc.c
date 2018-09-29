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
 * @\file	memalloc.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of memeory allocation functionality of memory utils
 * @\date	09/25/2018
 *
 */											   

/* Own headers */
#include "memalloc.h"

mem_status allocate_memory(char arg[], char  arg1[])
{
	g_nblock = atoi(arg);

	printf("n = %d\n", g_nblock);

        g_blockptr = (uint32_t *) malloc( (g_nblock) * sizeof(uint32_t));

        if (g_blockptr != NULL) {
                printf("%ld bytes of Memory Allocated and the starting address of the block is %p \n", ((g_nblock) * sizeof(uint32_t)), (void *)g_blockptr);
                return SUCCESS;
        }
        else {
                printf("Memory allocation failed\n");
                return FAILED;
        }
}
