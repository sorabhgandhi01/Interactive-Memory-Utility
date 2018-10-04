/**
 * @\file	xorinvert.h
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the declaration of invert functionality for memory utils
 * @\date	09/25/2018
 *
 */											   

#ifndef _XORINVERT_H
#define _XORINVERT_H

/*own header*/
#include "global.h"

/**
--------------------------------------------------------------------------------------------------
invert_memory
--------------------------------------------------------------------------------------------------
*	This function will invert the data of specified memory block
*
* 	@\param	arg		contains flag, Memory address/offset specified by the user and number of 
*                   next 'N' blocks
*
* 	@\return		On success it returns SUCCESS,
*                   On failure it returns FAILED
*/
mem_status invert_memory(char arg[]);


#endif
