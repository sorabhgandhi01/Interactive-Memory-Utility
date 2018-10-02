/**
 * @\file	memfree.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of memory free functionality for memory utils
 * @\date	09/25/2018
 *
 */		

/* Own headers */
#include "memfree.h"

/**
 * @\brief free_memory()
 * This function frees the dynamically allocated memory  
 * @\return SUCCESS or FAILED
**/										   
									   
mem_status free_memory()
{
	free(g_blockptr);
	
	return SUCCESS;
}
