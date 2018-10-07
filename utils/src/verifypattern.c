/**
 * @\file	verifypattern.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of write pattern functionality of memory utils
 * @\date	09/25/2018
 *
 */
/*system headers*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>


/*Own header */
#include "verifypattern.h"

/**
--------------------------------------------------------------------------------------------------
verifyPattern
--------------------------------------------------------------------------------------------------
*   This function verifies if the pseudo random generated value at the user specified memory location is correct
*
*   @\param arg     contains flag, Memory address/offset specified by the user and number of 
*                   next 'N' blocks and the seed value
*
*   @\return        On success it returns SUCCESS,
*                   On failure it returns FAILED
*/
mem_status verify_pattern(char arg[])
{
	/*initialize the clock*/
	clock_t t;
	t = clock();

	char flag[3];
	char addr[17];
	char r_bytes[9];
	char r_seed[9];
	
	/*clear all the buffer*/
	memset(flag, 0, sizeof(flag));
	memset(addr, 0, sizeof(addr));
	memset(r_bytes, 0, sizeof(r_bytes));
	memset(r_seed, 0, sizeof(r_seed));
	
	sscanf(arg, "%s %s %s %s", flag, addr, r_bytes, r_seed); 	// Splits the user input into address, block size and seed value
	
	/*Check if memory is not allocate before write call*/
    if ((g_blockptr == NULL) || (g_nblock == 0)) {
        print_msg("No memory block allocated. First allocate a memory using allocate command\n");
        return FAILED;
    }

	/*check for the address flag = '-a' */
	if ((flag[0] == '-') && (flag[1] == 'a')) {

		uint64_t useraddr = chtol(addr); // Converts string to long
		uint32_t block = chtoi(r_bytes); // Converts string to integer
		uint32_t seed = chtoi(r_seed); // COnverts string to integer
	
		uint32_t i = 0,
				flag = 0,
				j = 0;
	
		/* Loop to verify if pseudo random pattern wriiten into memory location is valid */
		for (i = 0; i < g_nblock; i++)
		{
			/*Check if the user specified address matches with the allocated 32bit word address*/
			if ((uint64_t *) &g_blockptr[i] == (uint64_t *) useraddr) {

				/*Check if 32bit address contains the same random number generated for a particular seed */
				if (g_blockptr[i] == c_random((uint64_t *)&g_blockptr[i], seed)) {
					print_msg("Pattern Matched\n");
				} else {
					print_msg("Expected value is %x	Actual value is %x	Address is %p\n", g_blockptr[i], c_random((uint64_t *)&g_blockptr[i], seed), &g_blockptr[i]);
				}

				/*Check if the user has specified a valid number of next "N" blocks*/
				if ((block != 0) && (block <= (g_nblock - (i+1))))
				{
					for (j = (i+1); j < (block + i + 1); j++) {

						/*Check if 32bit address contains the same random number generated for a particular seed */
						if (g_blockptr[j] == c_random((uint64_t *)&g_blockptr[j], seed)) {
							print_msg("Pattern Matched\n");
						} else {
							print_msg("Expected value is %x    Actual value is %x      Address is %p\n", g_blockptr[i], c_random((uint64_t *)&g_blockptr[i], seed), &g_blockptr[i]);
						}
					}
				
					flag = 1;
					break;
				}
				/*For '0' next block*/
				else if(block == 0)
				{
					flag = 1;
					break;
				}
				else {
					print_msg("Invalid number of 32-bit words\n");
					return FAILED;
				}
			}
		}

		/*Invalid addres if the user address does not match with any of the 32bit word*/
		if (flag != 1) {
			print_msg("Invalid Memory address\n");
			return FAILED;
		}
		
		/*Calculate total time by subtracting t with present time*/
		t = clock() - t;
        print_msg("Time taken to perform this operation is %f seconds\n", ((double)t/CLOCKS_PER_SEC));

		return SUCCESS;
	}
	/*Check for the address flag '-b' */
	else if ((flag[0] == '-') && (flag[1] == 'b')) {
        
		uint32_t offset = chtoi(addr);		//Convert string to long
        uint32_t block = chtoi(r_bytes);	//Convert string to int
		uint32_t seed = chtoi(r_seed);		//COnvert string to int
        uint32_t i = 0;

		/*Check for an out of range offset*/
        if (offset >= g_nblock) {
            print_msg("Invalid offset\n");
            return FAILED;
        }

		/*Check for an out of range 'N blocks' */
        if (block >= (g_nblock - offset)) {
            print_msg("Invalid number of next 32 bit words\n");
            return FAILED;
        }

        for (i = offset; i <= (offset + block); i++)
        {
			/*Check if 32bit address contains the same random number generated for a particular seed */
			if (g_blockptr[i] == c_random((uint64_t *)&g_blockptr[i], seed)) {                                                                                                   
 				print_msg("Pattern Matched\n");
 			} else {
 				print_msg("Expected value is %x    Actual value is %x      Address is %p\n", g_blockptr[i], c_random((uint64_t *)&g_blockptr[i], seed), &g_blockptr[i]);
			}
        }
		
		/*Calculate total time by subtracting t with present time*/
		t = clock() - t;
        print_msg("Time taken to perform this operation is %f\n", ((double)t/CLOCKS_PER_SEC));		

        return SUCCESS;

    }
    else {
        print_msg("Invalid flag\n");

        return FAILED;
    }
}
