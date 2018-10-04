/**
 * @\file	global.h
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This header file contains the prototypes for the funtions of character to long, character to integer and 
 *          pseudo random number generation functionality for memory utils
 * @\date	09/25/2018
 *
 */

#ifndef _GLOBAL_H
#define _GLOBAL_H

/*system headers*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*
**	status code
*/
typedef enum mem_status
{
	FAILED = 0,			//failure case
	SUCCESS,			//success case

}mem_status;

/*Declare a global block pointer to store the starting address of the dynamically allocated memory*/
uint32_t *g_blockptr;

/*Declare a global variable to store the number of 32 bit words allocated*/
uint32_t g_nblock;

/**
--------------------------------------------------------------------------------------------
chtol
--------------------------------------------------------------------------------------------
*	This function converts 8 byte hex array to 8 byte decimal number
*
* 	@\param	str[]	hexamdecimal number in a character array
*
* 	@\return		Returns the converted decimal number
*
**/
uint64_t chtol(char str[]);


/**
--------------------------------------------------------------------------------------------
chtoi
--------------------------------------------------------------------------------------------
*	This function converts 4 byte hex array to 4 byte decimal number
* 
* 	@\param	str[]	hexadecimal number in a character array
*
* 	@\return		Returns the converted decimal number
*
**/
uint32_t chtoi(char str[]);


/**
--------------------------------------------------------------------------------------------
c_random
--------------------------------------------------------------------------------------------
*	This function takes a the address and seed value as arguments and generates a pseudo random number
*
* 	@\param	addr	Memory address in hexadecimal format
* 	@\param seed	Seed value in hexadecimal format
*
* 	@\return		 Returns the pseudo random number
**/
uint32_t c_random(uint64_t *addr, uint32_t seed);


#endif
