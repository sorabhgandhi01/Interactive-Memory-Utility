/**
 * @\file	memwrite.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of memory write functionality of memory utils
 * @\date	09/25/2018
 *
 */											   

/* Own headers */
#include <memwrite.h>

/**
 * @\brief write_memory()
 * This function takes a character array as argument and writes the value at the user specified memory location  
 * @\param arg[] Stores the address and the value to be stored at the user specified memory location
 * @\return SUCCESS or FAILED
**/										   

mem_status write_memory(char arg[])
{
	char flag[3];
	char addr[17];
	char hex_data[9];

	memset(addr, 0, sizeof(addr));
	memset(hex_data, 0, sizeof(hex_data));
	memset(flag, 0, sizeof(flag));

	sscanf(arg, "%s %s %s", flag, addr, hex_data); // Splits the user input into address and hexa decimal data

	if ((flag[0] == '-') && (flag[1] == 'a')) {

		uint64_t useraddr = chtol(addr); // Converts string to long
		uint32_t data = chtoi(hex_data); // Converts string to integer
		uint32_t i = 0, flag = 0;
    
		/* Loop to write data onto user specified memory location */
		for (i = 0; i < g_nblock; i++)
		{
			if ((uint64_t *) &g_blockptr[i] == (uint64_t *)useraddr) {
				g_blockptr[i] = data;
				printf("Data written at %p is %x\n", &g_blockptr[i], g_blockptr[i]);
				flag = 1;
				break;
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
		uint32_t data = chtoi(hex_data);
		
		if (offset > g_nblock) {
			printf("Invalid offset\n");
			return FAILED;
		}

		g_blockptr[offset] = data;

		printf("Data written at %p is %x\n", &g_blockptr[offset], g_blockptr[offset]); 	

		return SUCCESS;
	}
	else {
		printf("Invalid flag\n");

		return FAILED;
	}
}
