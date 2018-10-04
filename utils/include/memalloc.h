/**
 * @\file	memalloc.h
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the declaration of memory allocation functionality of 
 * 		memory utils software stack
 * @\date	09/25/2018
 *
 */											   

#ifndef _MEMALLOC_H
#define _MEMALLOC_H

#include "global.h"

/**
--------------------------------------------------------------------------------------------
allocate_memory
--------------------------------------------------------------------------------------------
*	This function will allocate specified number of memory blocks in heap segment
*
* 	@\param	arg		Number of 32-bit words to be allocated
*
* 	@\return		On success it returns SUCCESS, 
* 					On failure it returns FAILED
*
*/
mem_status allocate_memory(char arg[]);


#endif
