/**
 * @\file	writepattern.h
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the declaration of write pattern functionality of memory utils
 * @\date	09/25/2018
 *
 */

#include "global.h"

/**
--------------------------------------------------------------------------------------------------
writePattern
--------------------------------------------------------------------------------------------------
* This function writes a pseudo random generated value at the user specified memory location
*
* 	@\param arg	Stores the address, number of blocks and seed value
*
* 	@\return	SUCCESS or FAILED
*
*/
mem_status write_pattern (char arg[]);
