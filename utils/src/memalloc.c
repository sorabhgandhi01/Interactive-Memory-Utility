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
 * @\brief allocate_memory()
 * This function takes a character array as arguments and dynamically allocates memory blocks 
 * @\param arg[] Stores the number of blocks to be allocated
 * @\return SUCCESS or FAILED
**/

mem_status allocate_memory(char arg[])
{
	uint32_t digit = strlen(arg);
    /* Print invalid if user entered block size is greater than 6 */
	if (digit > 6) {
		printf("Invalid number of 32bit words\n");
		return FAILED;
	}

	g_nblock = atoi(arg);
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
