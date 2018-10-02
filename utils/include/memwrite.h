/**
 * @\file	memwrite.h
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the declaration of memory write functionality for memory utils
 * @\date	09/25/2018
 *
 */											   

#ifndef _MEMWRITE_H
#define _MEMWRITE_H

#include "global.h"

/**
--------------------------------------------------------------------------------------------------
memWrite
--------------------------------------------------------------------------------------------------
* This function will write data into the specified memory block
*
* 	@\param	addr	Memory address specified by the user
*
* 	@\return	None
*
*/
mem_status write_memory(char arg[]);

#endif
