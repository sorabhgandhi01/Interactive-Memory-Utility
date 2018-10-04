/**
 * @\file	xorinvert.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of invert functionality of memory utils
 * @\date	09/25/2018
 *
 */

/* System headers */
#include <time.h>

/* Own headers */
#include <xorinvert.h>

/**
--------------------------------------------------------------------------------------------------
invert_memory
--------------------------------------------------------------------------------------------------
*   This function will invert the data of specified memory block
*
*   @\param arg     contains flag, Memory address/offset specified by the user and number of 
*                   next 'N' blocks
*
*   @\return        On success it returns SUCCESS,
*                   On failure it returns FAILED
*/	
mem_status invert_memory(char arg[])
{
	/*initialize the clock*/
	clock_t t;
	t = clock();

	char flag[3];
	char addr[15];
	char r_bytes[5];

	/*clear all the buffer*/
	memset(addr, 0, sizeof(addr));
    memset(r_bytes, 0, sizeof(r_bytes));
    memset(flag, 0, sizeof(flag));

	sscanf(arg, "%s %s %s", flag, addr, r_bytes); // Splits user input to into address, block size

	if ((flag[0] == '-') && (flag[1] == 'a')) {

		uint64_t useraddr = chtol(addr); // Converts string to long
		uint32_t block = chtoi(r_bytes); // Converts string to integer
		uint32_t i = 0, flag = 0, j = 0;
	
		/* Loop to invert the contents of the user specified memory blocks */
		for (i = 0; i < g_nblock; i++)
		{
			/*Check if the user specified address matches with the allocated 32bit word address*/
			if ((uint64_t *) &g_blockptr[i] == (uint64_t *) useraddr) 
			{
				printf("Inverted Data at memory address %p is %x\n", &g_blockptr[i], (g_blockptr[i]^0xFFFFFFFF));
				/*Check if the user has specified a valid number of next "N" blocks*/
				if ((block != 0) && (block <= (g_nblock - (i+1))))
				{
					for (j = (i+1); j < (block + i + 1); j++)
						printf("Inverted Data at memory address %p is %x\n", &g_blockptr[j], (g_blockptr[j]^0xFFFFFFFF));
				
					flag = 1;
					break;
				}
				else if(block == 0)
				{
					flag = 1;
					break;
				}
				else 
				{
					printf("Invalid number of 32-bit words\n");
					return FAILED;
				}
			}
		}

		/*Invalid addres if the user address does not match with any of the 32bit word*/
		if (flag != 1) {
			printf("Invalid memory address\n");
			return FAILED; 
		}

		/*Calculate total time by subtracting t with present time*/
		t = clock() - t;
		printf("Time taken to perform this operation is %f\n", ((double)t/CLOCKS_PER_SEC));

		return SUCCESS;
	}
	/*Check for the address flag '-b' */
	else if ((flag[0] == '-') && (flag[1] == 'b')) {

		uint32_t offset = chtoi(addr);
        uint32_t block = chtoi(r_bytes);
        uint32_t i = 0;

		/*Check for an out of range offset*/
        if (offset >= g_nblock) {
            printf("Invalid offset\n");
            return FAILED;
        }

		/*Check for an out of range 'N blocks' */
        if (block >= (g_nblock - offset)) {
            printf("Invalid number of next 32 bit words\n");
            return FAILED;
        }

        for (i = offset; i <= (offset + block); i++)
        {
			printf("Inverted Data at memory address %p is %x\n", &g_blockptr[i], (g_blockptr[i]^0xFFFFFFFF));
        }
		
		/*Calculate total time by subtracting t with present time*/
		t = clock() - t;
        printf("Time taken to perform this operation is %f\n", ((double)t/CLOCKS_PER_SEC));
		
		return SUCCESS;
    }
    else {
        printf("Invalid flag\n");
        return FAILED;
	}
}
