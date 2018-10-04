/**
 * @\file	memwrite.h
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the declaration of memory write functionality for memory utils
 * @\date	09/25/2018
 *
 */											   

#ifndef _MEMWRITE_H
#define _MEMWRITE_H

/*own header*/
#include "global.h"

/**
--------------------------------------------------------------------------------------------------
write_memory
--------------------------------------------------------------------------------------------------
*	This function will write data into the specified memory block
*
* 	@\param	addr	contains flag, Memory address/offset specified by the user and the value to be 
*					written in the memory
*
* 	@\return		On success it returns SUCCESS,
*                   On failure it returns FAILED
*/
mem_status write_memory(char arg[]);


#endif
