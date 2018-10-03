/**
 * @\file	writepattern.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of write pattern functionality of memory utils
 * @\date	09/25/2018
 *
 */

#include "writepattern.h"

/**
 * @\brief write_pattern()
 * This function takes a character array as argument and writes a pseudo random generated value at the user specified memory location  
 * @\param arg[] Stores the address, number of blocks and seed value
 * @\return SUCCESS or FAILED
**/	

mem_status write_pattern(char arg[])
{
	char flag[3];
	char addr[17];
	char r_bytes[9];
	char r_seed[9];

	memset(flag, 0, sizeof(flag));
	memset(addr, 0, sizeof(addr));
	memset(r_bytes, 0, sizeof(r_bytes));
	memset(r_seed, 0, sizeof(r_seed));

	sscanf(arg, "%s %s %s %s", flag, addr, r_bytes, r_seed); // Splits the user input into address, block size and seed value

	if ((flag[0] == '-') && (flag[1] == 'a')) {

		uint64_t useraddr = chtol(addr); // Converts string to long
		uint32_t block = chtoi(r_bytes); // Converts string to integer
		uint32_t seed = chtoi(r_seed); // Convert string to integer

		uint32_t i = 0, flag = 0, j = 0;
	
		/* Loop to write pseudo random numbers into the user specified memory blocks */
		for (i = 0; i < g_nblock; i++)
		{
			if ((uint64_t *) &g_blockptr[i] == (uint64_t *) useraddr) {

				g_blockptr[i] = c_random((uint64_t *)&g_blockptr[i], seed);
				
				printf("Random Pattern Data at memory address %p is %x\n", &g_blockptr[i], g_blockptr[i]);
			
				if ((block != 0) && (block <= (g_nblock - (i+1)))) 
				{
					for (j = (i+1); j < (block + i + 1); j++) {

						g_blockptr[j] = c_random((uint64_t *)&g_blockptr[j], seed);
					
						printf("Random Pattern Data at memory address %p is %x\n", &g_blockptr[j], g_blockptr[j]);
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
			printf("Invalid memory address\n");
			return FAILED;
		}

		return SUCCESS;
	}
	else if ((flag[0] == '-') && (flag[1] == 'b')) {
        
		uint32_t offset = chtoi(addr);
        uint32_t block = chtoi(r_bytes);
		uint32_t seed = chtoi(r_seed);
        uint32_t i = 0;

        if (offset >= g_nblock) {
            printf("Invalid offset\n");
            return FAILED;
        }

        if (block >= (g_nblock - offset)) {
            printf("Invalid number of next 32 bit words\n");
            return FAILED;
        }

        for (i = offset; i <= (offset + block); i++)
        {
			g_blockptr[i] = c_random((uint64_t *)&g_blockptr[i], seed);
			printf("Random Pattern Data at memory address %p is %x\n", &g_blockptr[i], g_blockptr[i]);
        }

        return SUCCESS;
    }
    else {
        printf("Invalid flag\n");

        return FAILED;
    }

}
