/**
 * @\file	global.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of character to long, character to integer and pseudo random number generation functionality of memory utils
 * @\date	09/25/2018
 *
 */

#include <string.h>

#include "global.h"

/**
 * @\brief chtol()
 * This function takes a character array as argument and converts it into a long datatype
 * @\param str[] Stores the string to be converted to long
 * @\return ret_value Returns the converted long variable
**/	

uint64_t chtol(char str[])
{
	uint64_t ret_value = 0;
    uint64_t hex_base = 1;
    int i = 0;

	uint32_t digit = strlen(str);

	for (i = (digit-1); i >= 0; i--)
	{
		if ((str[i] >= '0') && (str[i] <= '9')) {
			ret_value += (str[i] - 48)*hex_base;
			
			hex_base = hex_base * 16;
		}
		else if ((str[i] >= 'A') && (str[i] <= 'F')) {
			ret_value += (str[i] - 55)*hex_base;
			hex_base = hex_base * 16;
		}
		else if ((str[i] >= 'a') && (str[i] <= 'f')) {
			ret_value += (str[i] - 87)*hex_base;
			hex_base = hex_base * 16;
		}
	}
	return ret_value;
}

/**
 * @\brief chtoi()
 * This function takes a character array as argument and converts it into integer datatype
 * @\param str[] Stores the string to be converted to integer
 * @\return ret_value Returns the converted integer variable
**/	


uint32_t chtoi(char str[])
{
	uint32_t ret_value = 0;
	uint32_t hex_base = 1;
	int i = 0; 
	
	uint32_t digit = strlen(str);
	
	for (i = (digit-1); i >= 0; i--)
	{
		if ((str[i] >= '0') && (str[i] <= '9')) {
			ret_value += (str[i] - 48)*hex_base;
			hex_base = hex_base * 16;
		}
		else if ((str[i] >= 'A') && (str[i] <= 'F')) {
			ret_value += (str[i] - 55)*hex_base;
			hex_base = hex_base * 16;
		}
		else if ((str[i] >= 'a') && (str[i] <= 'f')) {
			ret_value += (str[i] - 87)*hex_base;
			hex_base = hex_base * 16;
		}
	}
	return ret_value;
}

/**
 * @\brief c_random()
 * This function takes a the address and seed value as arguments and generates a pseudo random number
 * @\param addr Stores the address of the current block
 * @\param seed Stores the user entered seed value
 * @\return ret_value Returns the pseudo random number that is generated
**/	

uint32_t c_random(uint64_t *addr, uint32_t seed)
{
	uint32_t ret;
	ret = (uintptr_t)(addr);
	ret = ret ^ seed;
	
	return ret;
}
