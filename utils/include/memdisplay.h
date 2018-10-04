/**
 * @\file	displaymem.h
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the declaration of memory display functionality of memory utils
 * @\date	09/25/2018
 *
 */											   

#ifndef _MEMDISPLAY_H
#define _MEMDISPLAY_H

/*own header*/
#include "global.h"

/**
--------------------------------------------------------------------------------------------------
read_memory
--------------------------------------------------------------------------------------------------
*	This function will display the data stored in the memory block
*
* 	@\param arg			contains flag, Memory address/offset specified by the user and number of 
*						next 'N' blocks
*
* 	@\return			On success it returns SUCCESS,
*                       On failure it returns FAILED
*/
mem_status read_memory(char arg[]);

#endif                                                                                            
