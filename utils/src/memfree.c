/**
 * @\file	memfree.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of memory free functionality for memory utils
 * @\date	09/25/2018
 *
 */		
/*system headers*/
#include <stdio.h>
#include <stdlib.h>

/* Own headers */
#include "memfree.h"

/**
--------------------------------------------------------------------------------------------------
free_memory
--------------------------------------------------------------------------------------------------
* This function releases the specified memory block in the heap segment
*
*   @\param     None
*
*   @\return    "SUCCESS"
*
*/									   
mem_status free_memory()
{
	if (g_blockptr != NULL)
	{
		free(g_blockptr);

		g_blockptr = NULL;
		g_nblock = 0;

		print_msg("Freeing the allocated memory\n");
	}
	else {
		print_msg("No allocated memory found! First allocate the memory then call free command\n");
	}
	
	return SUCCESS;
}
