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
*	This function writes a pseudo random generated value at the user specified memory location
*
* 	@\param arg		contains flag, Memory address/offset specified by the user and number of 
*                   next 'N' blocks and the seed value
*
* 	@\return		On success it returns SUCCESS,
*                   On failure it returns FAILED
*/
mem_status write_pattern (char arg[]);
