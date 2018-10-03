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

/**
 * @\brief invert_memory()
 * This function takes a character array as argument and inverts the value at the user specified memory location  
 * @\param arg[] Stores the address and number of blocks
 * @\return SUCCESS or FAILED
**/										   
	
mem_status invert_memory(char arg[])
{
	clock_t t;
	t = clock();

	char addr[15];
	char r_bytes[5];

	sscanf(arg, "%s %s", addr, r_bytes); // Splits user input to into address, block size

	uint64_t useraddr = chtol(addr); // Converts string to long
	uint32_t block = chtoi(r_bytes); // Converts string to integer
	uint32_t i = 0, flag = 0, j = 0;
	
	/* Loop to invert the contents of the user specified memory blocks */
	for (i = 0; i < g_nblock; i++)
	{
		if ((uint64_t *) &g_blockptr[i] == (uint64_t *) useraddr) 
		{
			printf("Inverted Data at memory address %p is %x\n", &g_blockptr[i], (g_blockptr[i]^0xFFFFFFFF));
			if ((block != 0) && (block <= (g_nblock - (i+1))))
			{
				for (j = (i+1); j < (block + i + 1); j++)
					printf("Inverted Data at memory address %p is %x\n", &g_blockptr[j], (g_blockptr[j]^0xFFFFFFFF));
				
				flag = 1;
				break;
			}
			else if(block == 0)
			{
				flag = 1;
				break;
			}
			else 
			{
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
