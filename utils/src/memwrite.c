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
 * @\file	memwrite.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of memory write functionality of memory utils
 * @\date	09/25/2018
 *
 */											   

/* Own headers */
#include <memwrite.h>


mem_status write_memory(char arg1[], char arg2[])
{
	uint64_t useraddr = atol(arg1);
	uint32_t data = atoi(arg2);

	uint32_t i = 0, flag = 0;

	//printf("user addr = %lx	data = %d	nblock --> %d	bloackptr --> %p\n", useraddr, data, g_nblock, &g_blockptr[0]);

	for (i = 0; i < g_nblock; i++)
	{
		uint64_t *temp = (uint64_t *)&g_blockptr[i];

		if (temp == useraddr) {
			g_blockptr[i] = data;
			printf("Data successfully written at %p\n", &g_blockptr[i]);
			flag = 1;
			break;
		}
	}

	if (flag != 1) {
		printf("Invalid memory address\n");
		return FAILED;
	}

	return SUCCESS;
}