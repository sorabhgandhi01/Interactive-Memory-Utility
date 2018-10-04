/**
 * @\file	memfree.h
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the declaration of memory free functionality for memory utils
 * @\date	09/25/2018
 *
 */											   

#ifndef _MEMFREE_H
#define _MEMFREE_H

/*own header*/
#include "global.h"

/**
--------------------------------------------------------------------------------------------------
free_memory
--------------------------------------------------------------------------------------------------
* This function releases the specified memory block in the heap segment
*
* 	@\param		None
*
* 	@\return	"SUCCESS"
*
*/
mem_status free_memory();


#endif
