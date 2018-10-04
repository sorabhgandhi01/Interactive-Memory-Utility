/**
 * @\file	global.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of character to long, character to integer and pseudo random number generation functionality of memory utils
 * @\date	09/25/2018
 *
 */

#include <string.h>

/*own header*/
#include "global.h"

/**
--------------------------------------------------------------------------------------------
chtol
--------------------------------------------------------------------------------------------
* This function converts 8 byte hex array to 8 byte decimal number
*
*   @\param str[]   hexamdecimal number in a character array
*
*   @\return        Returns the converted decimal number
*
**/
uint64_t chtol(char str[])
{
	uint64_t ret_value = 0;

	/*Initializing hex base value to 1*/
    uint64_t hex_base = 1;

    int i = 0;

	uint32_t digit = strlen(str);

	/*Extract char as digit from last char*/
	for (i = (digit-1); i >= 0; i--)
	{
		/*For '0' - '9', subtract 48 from the ASCII value*/
		if ((str[i] >= '0') && (str[i] <= '9')) {
			ret_value += (str[i] - 48)*hex_base;
			
			hex_base = hex_base * 16;		//incrementing base by power
		}
		/*For 'A' to 'Z', subtract 55 from the ASCII value*/
		else if ((str[i] >= 'A') && (str[i] <= 'F')) {
			ret_value += (str[i] - 55)*hex_base;
			hex_base = hex_base * 16;		//incrementing base by power
		}
		/*For 'a' to 'z', subtract 87 from the ASCII value*/
		else if ((str[i] >= 'a') && (str[i] <= 'f')) {
			ret_value += (str[i] - 87)*hex_base;
			hex_base = hex_base * 16;		//incrementing base by power
		}
	}
	return ret_value;
}


/**
--------------------------------------------------------------------------------------------
chtoi
--------------------------------------------------------------------------------------------
*   This function converts 4 byte hex array to 4 byte decimal number
* 
*   @\param str[]   hexadecimal number in a character array
*
*   @\return        Returns the converted decimal number
*
**/
uint32_t chtoi(char str[])
{
	uint32_t ret_value = 0;

	/*initializing hex base to 1*/
	uint32_t hex_base = 1;

	int i = 0; 
	
	uint32_t digit = strlen(str);
	
	/*Extract char as digit from last char*/
	for (i = (digit-1); i >= 0; i--)
	{
		/*For '0' to '9', subtract 48 from the ASCII value*/
		if ((str[i] >= '0') && (str[i] <= '9')) {
			ret_value += (str[i] - 48)*hex_base;
			hex_base = hex_base * 16;			//incrementing base by power
		}
		/*For 'A' to 'Z', subtract 55 from the ASCII value*/
		else if ((str[i] >= 'A') && (str[i] <= 'F')) {
			ret_value += (str[i] - 55)*hex_base;
			hex_base = hex_base * 16;			//incrementing base by power
		}
		/*For 'a' to 'z', subtract 87 from the ASCII value*/
		else if ((str[i] >= 'a') && (str[i] <= 'f')) {
			ret_value += (str[i] - 87)*hex_base;
			hex_base = hex_base * 16;			//incrementing base by power
		}
	}
	return ret_value;
}


/**
--------------------------------------------------------------------------------------------
c_random
--------------------------------------------------------------------------------------------
*   This function takes a the address and seed value as arguments and generates a pseudo random number
*
*   @\param addr    Memory address in hexadecimal format
*   @\param seed    Seed value in hexadecimal format
*
*   @\return         Returns the pseudo random number
**/
uint32_t c_random(uint64_t *addr, uint32_t seed)
{
	uint32_t ret;

	ret = (uintptr_t)(addr);		//Extract the four higher bytes of the memory address

	ret = ret ^ seed;				// xor ret and seed
	
	return ret;
}
