/**
 * @\file	memdisplay.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of memory display functionality for memory utils
 * @\date	09/25/2018
 *
 */	
/*system headers*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/* Own headers */
#include <memdisplay.h>

/**
 * @\brief read_memory()
 * This function takes a character array as argument and reads the value at the user specified memory location  
 * @\param arg[] Stores the address and number of blocks to be read
 * @\return SUCCESS or FAILED
**/										   

mem_status read_memory(char arg[])
{
    char flag[3];
	char addr[15];
	char r_bytes[5];

	memset(addr, 0, sizeof(addr));
	memset(r_bytes, 0, sizeof(r_bytes));
    memset(flag, 0, sizeof(flag));

	sscanf(arg, "%s %s %s", flag, addr, r_bytes); //Splits user input to address and block size

    if ((flag[0] == '-') && (flag[1] == 'a')) {

	    uint64_t useraddr = chtol(addr); // Converts string to long
	    uint32_t block = chtoi(r_bytes); // Converts string to integer
	    uint32_t i = 0, flag = 0, j = 0;
	
	    /* Loop to display the contents from the user specified memory */
	    for (i = 0; i < g_nblock; i++)
	    {
		    if ((uint64_t *) &g_blockptr[i] == (uint64_t *) useraddr) {
			    print_msg("Data at memory address %p is %x\n", &g_blockptr[i], g_blockptr[i]);
			    if ((block != 0) && (block <= (g_nblock - (i+1))))
			    {
				    for (j = (i+1); j < (block + i + 1); j++)
					print_msg("Data at memory address %p is %x\n", &g_blockptr[j], g_blockptr[j]);
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
	
		if (flag != 1) {
			print_msg("Invalid memory address\n");
			return FAILED;
		}
		return SUCCESS;
	}
	else if ((flag[0] == '-') && (flag[1] == 'b')) {
		uint32_t offset = chtoi(addr);
		uint32_t block = chtoi(r_bytes);
		uint32_t i = 0;

		if (offset >= g_nblock) {
			print_msg("Invalid offset\n");
			return FAILED;
		}

		if (block >= (g_nblock - offset)) {
			print_msg("Invalid number of next 32 bit words\n");
			return FAILED;
		}
        
        for (i = offset; i <= (offset + block); i++)
        {
			print_msg("Data at memory address %p is %x\n", &g_blockptr[i], g_blockptr[i]);
		}

		return SUCCESS;
	}
	else {
		print_msg("Invalid flag\n");

		return FAILED;
	}
}
