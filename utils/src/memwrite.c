/**
 * @\file	memwrite.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of memory write functionality of memory utils
 * @\date	09/25/2018
 *
 */											   
/*system headers*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


/* Own headers */
#include <memwrite.h>

/**
--------------------------------------------------------------------------------------------------
write_memory
--------------------------------------------------------------------------------------------------
* This function will write data into the specified memory block
*
*   @\param addr    contains flag, Memory address/offset specified by the user and the value to be 
*                   written in the memory
*
*   @\return        On success it returns SUCCESS,
*                   On failure it returns FAILED
*/
mem_status write_memory(char arg[])
{
	char flag[3];
	char addr[17];
	char hex_data[9];

	/*clear all the buffer*/
	memset(addr, 0, sizeof(addr));
	memset(hex_data, 0, sizeof(hex_data));
	memset(flag, 0, sizeof(flag));

	sscanf(arg, "%s %s %s", flag, addr, hex_data);		// Splits the user input into address and hexadecimal data

	/*Check if memory is not allocate before write call*/
	if ((g_blockptr == NULL) || (g_nblock == 0)) {
		print_msg("No memory block allocated. First allocate a memory using allocate command\n");	
		return FAILED;
	}

	if ((strcmp(flag, "-a")) == 0) {

		uint64_t useraddr = chtol(addr);			// Converts string to long
		uint32_t data = chtoi(hex_data); 			// Converts string to integer
		uint32_t i = 0, flag = 0;
    
		/* Loop to write data onto user specified memory location */
		for (i = 0; i < g_nblock; i++)
		{
			/*Check if the user specified address matches with an address of the 32bit allocated word*/
			if ((uint64_t *) &g_blockptr[i] == (uint64_t *)useraddr) {

				g_blockptr[i] = data;			//write the user data to the specified memory block

				print_msg("Data written at %p is %x\n", &g_blockptr[i], g_blockptr[i]);
				flag = 1;
				break;
			}
		}

		if (flag != 1) {
			print_msg("Invalid memory address\n");
			return FAILED;
		}

		return SUCCESS;

	} 
	else if ((strcmp(flag, "-b")) == 0) {

		uint32_t offset = chtoi(addr);		//Converts string to long
		uint32_t data = chtoi(hex_data);	//Converts string to int
		
		if (offset >= g_nblock) {
			print_msg("Invalid offset\n");
			return FAILED;
		}

		g_blockptr[offset] = data;			//write the user data to the specified memory block

		print_msg("Data written at %p is %x\n", &g_blockptr[offset], g_blockptr[offset]); 	

		return SUCCESS;
	}
	else {
		print_msg("Invalid flag\n");

		return FAILED;
	}
}
