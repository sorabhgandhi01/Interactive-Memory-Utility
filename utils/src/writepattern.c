/**
 * @\file	writepattern.c
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
#include "writepattern.h"

/**
--------------------------------------------------------------------------------------------------
writePattern
--------------------------------------------------------------------------------------------------
*   This function writes a pseudo random generated value at the user specified memory location
*
*   @\param arg     contains flag, Memory address/offset specified by the user and number of 
*                   next 'N' blocks and the seed value
*
*   @\return        On success it returns SUCCESS,
*                   On failure it returns FAILED
*/
mem_status write_pattern(char arg[])
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

	sscanf(arg, "%s %s %s %s", flag, addr, r_bytes, r_seed); // Splits the user input into address, block size and seed value

	if ((flag[0] == '-') && (flag[1] == 'a')) {

		uint64_t useraddr = chtol(addr); // Converts string to long
		uint32_t block = chtoi(r_bytes); // Converts string to integer
		uint32_t seed = chtoi(r_seed); // Convert string to integer

		uint32_t i = 0,
				flag = 0,
				j = 0;
	
		/* Loop to write pseudo random numbers into the user specified memory blocks */
		for (i = 0; i < g_nblock; i++)
		{
			/*Check if the user specified address matches with the allocated 32bit word address*/
			if ((uint64_t *) &g_blockptr[i] == (uint64_t *) useraddr) {

				g_blockptr[i] = c_random((uint64_t *)&g_blockptr[i], seed); //Write the random number to user specified memory address
				
				print_msg("Random Pattern Data at memory address %p is %x\n", &g_blockptr[i], g_blockptr[i]);
			
				/*Check if the user has specified a valid number of next "N" blocks*/
				if ((block != 0) && (block <= (g_nblock - (i+1)))) 
				{
					for (j = (i+1); j < (block + i + 1); j++) {

						g_blockptr[j] = c_random((uint64_t *)&g_blockptr[j], seed);	//Write the random number to user specified memory address
					
						print_msg("Random Pattern Data at memory address %p is %x\n", &g_blockptr[j], g_blockptr[j]);
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
					print_msg("Invalid number of 32-bit words\n");
					return FAILED;
				}
			}
		}
	
		 /*Invalid addres if the user address does not match with any of the 32bit word*/
		if (flag != 1) {
			print_msg("Invalid memory address\n");
			return FAILED;
		}

		/*Calculate total time by subtracting t with present time*/
		t = clock() - t;
        print_msg("Time taken to perform this operation is %f\n", ((double)t/CLOCKS_PER_SEC));

		return SUCCESS;
	}
	/*Check for the address flag '-b' */
	else if ((flag[0] == '-') && (flag[1] == 'b')) {
        
		uint32_t offset = chtoi(addr);
        uint32_t block = chtoi(r_bytes);
		uint32_t seed = chtoi(r_seed);
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
			g_blockptr[i] = c_random((uint64_t *)&g_blockptr[i], seed);
			print_msg("Random Pattern Data at memory address %p is %x\n", &g_blockptr[i], g_blockptr[i]);
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
