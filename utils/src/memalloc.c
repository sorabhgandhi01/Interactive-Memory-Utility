/**
 * @\file	memalloc.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of memeory allocation functionality of memory utils
 * @\date	09/25/2018
 *
 */											   

/* Own headers */
#include "memalloc.h"

/**
--------------------------------------------------------------------------------------------
allocate_memory
--------------------------------------------------------------------------------------------
*   This function will allocate specified number of memory blocks in heap segment
*
*   @\param arg     Number of 32-bit words to be allocated
*
*   @\return        On success it returns SUCCESS, 
*                   On failure it returns FAILED
*
*/
mem_status allocate_memory(char arg[])
{
	uint32_t digit = strlen(arg);

    /* Print invalid if user enters 32bit words greater than 99999 */
	if (digit > 5) {
		printf("Invalid number of 32bit words\n");
		return FAILED;
	}

	/* Print invalid if user does not enter 32bit words*/
	if (arg == NULL) {
		printf("Number of 32bit words to allocate is not specified\n");
		return FAILED;
	}

	g_nblock = atoi(arg);			//convert the input data into decimal

	/*dynamically allocate specified 32bit words in the heap segment*/
	g_blockptr = (uint32_t *) malloc( (g_nblock) * sizeof(uint32_t));

	if (g_blockptr != NULL) {
		printf("%ld bytes of Memory Allocated and the starting address of the block is %p \n", ((g_nblock) * sizeof(uint32_t)), (void *)g_blockptr);
		return SUCCESS;
	} else {
		printf("Memory allocation failed\n");
		return FAILED;
	}
}
