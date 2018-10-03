/**
 * @\file	verifypattern.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of write pattern functionality of memory utils
 * @\date	09/25/2018
 *
 */

#include "verifypattern.h"

/**
 * @\brief verify_pattern()
 * This function takes a character array as argument and verifies if the pseudo random generated value at the user specified memory location is correct  
 * @\param arg[] Stores the address, number of blocks and seed value
 * @\return SUCCESS or FAILED
**/	

mem_status verify_pattern(char arg[])
{
	char addr[17];
	char r_bytes[9];
	char r_seed[9];
	
	memset(addr, 0, sizeof(addr));
	memset(r_bytes, 0, sizeof(r_bytes));
	memset(r_seed, 0, sizeof(r_seed));
	
	sscanf(arg, "%s %s %s", addr, r_bytes, r_seed); // Splits the user input into address, block size and seed value
	
	uint64_t useraddr = chtol(addr); // Converts string to long
	uint32_t block = chtoi(r_bytes); // Converts string to integer
	uint32_t seed = chtoi(r_seed); // COnverts string to integer
	
	uint32_t i = 0, flag = 0, j = 0;
	
	/* Loop to verify if pseudo random pattern wriiten into memory location is valid */
	for (i = 0; i < g_nblock; i++)
	{
		if ((uint64_t *) &g_blockptr[i] == (uint64_t *) useraddr) {
			if (g_blockptr[i] == c_random((uint64_t *)&g_blockptr[i], seed)) {
				printf("Pattern Matched\n");
			}
			else
				printf("Expected value is %x	Actual value is %x	Address is %p\n", g_blockptr[i], c_random((uint64_t *)&g_blockptr[i], seed), &g_blockptr[i]);
			if ((block != 0) && (block <= (g_nblock - (i+1))))
			{
				for (j = (i+1); j < (block + i + 1); j++){
					if (g_blockptr[i] == c_random((uint64_t *)&g_blockptr[i], seed)) {
						printf("Pattern Matched\n");
					}
					else
						printf("Expected value is %x    Actual value is %x      Address is %p\n", g_blockptr[i], c_random((uint64_t *)&g_blockptr[i], seed), &g_blockptr[i]);
				
				}
				
				flag = 1;
				break;
			}
			else if(block == 0)
			{
				flag = 1;
				break;
			}
			else {
				printf("Invalid number of 32-bit words\n");
				return FAILED;
			}
		}
	}

	if (flag != 1) {
		printf("Invalid Memory address\n");
		return FAILED;
	}
	return SUCCESS;
}
