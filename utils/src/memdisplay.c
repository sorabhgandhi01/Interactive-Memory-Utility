/**
 * @\file	memdisplay.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of memory display functionality for memory utils
 * @\date	09/25/2018
 *
 */	

/* Own headers */
#include <memdisplay.h>

/**
 * @\brief read_memory()
 * This function takes a character array as argument and reads the value at the user specified memory location  
 * @\param arg[] Stores the address and number of blocks to be read
 * @\return SUCCESS or FAILED
**/										   

mem_status read_memory(char arg[])
{
	char addr[15];
	char r_bytes[5];

	memset(addr, 0, sizeof(addr));
	memset(r_bytes, 0, sizeof(r_bytes));

	sscanf(arg, "%s %s" addr, r_bytes); //Splits user input to address and block size

	uint64_t useraddr = chtol(addr); // Converts string to long
	uint32_t block = chtoi(r_bytes); // Converts string to integer
	uint32_t i = 0, flag = 0, j = 0;
	
	/* Loop to display the contents from the user specified memory */
	for (i = 0; i < g_nblock; i++)
	{
		if ((uint64_t *) &g_blockptr[i] == (uint64_t *) useraddr) {
			printf("Data at memory address %p is %x\n", &g_blockptr[i], g_blockptr[i]);
			if ((block != 0) && (block <= (g_nblock - (i+1))))
			{
				for (j = (i+1); j < (block + i + 1); j++)
					printf("Data at memory address %p is %x\n", &g_blockptr[j], g_blockptr[j]);
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
	
#if 0
	if (flag != 1) {
		printf("Invalid memory address\n");
		return FAILED;
	}
	return SUCCESS;
	}
	else {
		uint32_t offset = chtoi(addr);
		uint32_t block = chtoi(r_bytes);
		uint32_t i = 0;

		if (offset > g_nblock) {
			printf("Invalid offset\n");
			return FAILED;
		}

		if (block <= (g_nblock - offset)) {
			printf("Invalid number of next 32 bit words\n");
			return FAILED;
		}
	}	
#endif
}
