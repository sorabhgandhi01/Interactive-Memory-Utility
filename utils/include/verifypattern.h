/**
 * @\file	verifypattern.h
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the declaration of verify pattern functionality for memory utils
 * @\date	09/25/2018
 *
 */	

/*own header*/
#include "global.h"

/**
--------------------------------------------------------------------------------------------------
verifyPattern
--------------------------------------------------------------------------------------------------
*	This function verifies if the pseudo random generated value at the user specified memory location is correct
*
* 	@\param arg		contains flag, Memory address/offset specified by the user and number of 
*                   next 'N' blocks and the seed value
*
* 	@\return		On success it returns SUCCESS,
*                   On failure it returns FAILED
*/
mem_status verify_pattern(char arg[]);
