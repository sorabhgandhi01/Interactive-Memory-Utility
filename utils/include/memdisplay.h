/**
 * @\file	displaymem.h
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the declaration of memory display functionality of memory utils
 * @\date	09/25/2018
 *
 */											   

#ifndef _MEMDISPLAY_H
#define _MEMDISPLAY_H

#include "global.h"

/**
--------------------------------------------------------------------------------------------------
displaymem
--------------------------------------------------------------------------------------------------
* This function will display the data stored in the memory block
*
* 	@\param userAddr	Memory address specified by the user
* 	@\param n_block		Number of memory blocks to read
*
* 	@\return	None
*
*/
mem_status read_memory(char arg[]);

#endif                                                                                            
