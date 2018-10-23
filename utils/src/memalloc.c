/**
 * @\file	memalloc.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of memeory allocation functionality of memory utils
 * @\date	09/25/2018
 *
 */											   

/*system headers*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


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

	/* Print invalid if user does not enter 32bit words*/
	if (arg == NULL) {
		print_msg("Number of 32bit words to allocate is not specified\n");
		return FAILED;
	}

	g_nblock = chtoi(arg);			//convert the input data into decimal

    /* Print invalid if user enters 32bit words greater than 1000 */
    if ((g_nblock >= 1001) || (g_nblock == 0)) {
        print_msg("Invalid number of 32bit words. Only use 32bit words in the range of 1 to 3E8\n");
        return FAILED;
    }

	/* Check if previously allocated memory is free*/
	if (g_blockptr != NULL) {
		print_msg("Free the previously allocated memory first and then continue with new allocation\n");
		return FAILED;
	}

	/*dynamically allocate specified 32bit words in the heap segment*/
	g_blockptr = (uint32_t *) malloc( (g_nblock) * sizeof(uint32_t));

	if (g_blockptr != NULL) {
		print_msg("%ld bytes of Memory Allocated and the starting address of the block is %p \n", ((g_nblock) * sizeof(uint32_t)), (void *)g_blockptr);
		return SUCCESS;
	} else {
		print_msg("Memory allocation failed\n");
		return FAILED;
	}
}
