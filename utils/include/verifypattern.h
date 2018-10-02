/**
 * @\file	verifypattern.h
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the declaration of verify pattern functionality of memory utils
 * @\date	09/25/2018
 *
 */	


#include "global.h"

/**
--------------------------------------------------------------------------------------------------
verifyPattern
--------------------------------------------------------------------------------------------------
* This function verifies if the pseudo random generated value at the user specified memory location is correct
*
* 	@\param arg	Stores the address, number of blocks and seed value
*
* 	@\return	SUCCESS or FAILED
*
*/
mem_status verify_pattern(char arg[]);
