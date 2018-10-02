/**
 * @\file	xorinvert.h
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the declaration of invert functionality for memory utils
 * @\date	09/25/2018
 *
 */											   

#ifndef _XORINVERT_H
#define _XORINVERT_H

#include "global.h"

/**
--------------------------------------------------------------------------------------------------
xorInvert
--------------------------------------------------------------------------------------------------
* This function will invert the data of specified memory block
*
* 	@\param	arg	memory address specified by the user
*
* 	@\return	None
*
*/
mem_status invert_memory(char arg[]);

#endif
