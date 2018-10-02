/**
 * @\file	global.h
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This header file contains the prototypes for the funtions of character to long, character to integer and 
 *              pseudo random number generation functionality of memory utils
 * @\date	09/25/2018
 *
 */

#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef enum mem_status
{
	FAILED = 0,
	SUCCESS,

}mem_status;

uint32_t *g_blockptr;

uint32_t g_nblock;

/**
--------------------------------------------------------------------------------------------
chtol
--------------------------------------------------------------------------------------------
* This function takes a character array as argument and converts it into a long datatype
*
* 	@\param str[] Stores the string to be converted to long
*
* 	@\return ret_value Returns the converted long variable
*
**/

uint64_t chtol(char str[]);

/**
--------------------------------------------------------------------------------------------
chtoi
--------------------------------------------------------------------------------------------
* This function takes a character array as argument and converts it into integer
* 
* 	@\param str[] Stores the string to be converted to integer
*
* 	@\return ret_value Returns the converted integer variable
*
**/

uint32_t chtoi(char str[]);

/**
--------------------------------------------------------------------------------------------
c_random
--------------------------------------------------------------------------------------------
* This function takes a the address and seed value as arguments and generates a pseudo random number
*
* 	@\param addr Stores the address of the current block
* 	@\param seed Stores the user entered seed value
*
* 	@\return ret_value Returns the pseudo random number that is generated
**/

uint32_t c_random(uint64_t *addr, uint32_t seed);

#endif
