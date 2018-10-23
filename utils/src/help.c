/**
 * @\file	help.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of help functionality for memory utils
 * @\date	09/25/2018
 *
 */
						   
/*system headers*/
#include <stdio.h>

/* Own headers */
#include "help.h"

/**
--------------------------------------------------------------------------------------------
help
--------------------------------------------------------------------------------------------
*   This function will list the available commands and how to invoke them
*
*   @\param     void
*
*   @\return    "SUCCESS"
*
*/
mem_status help()
{
	print_msg("Usage: [Command] [argument] \n\n The following commands are supported \n \
		allocate <N block> - To allocate the new memory block\n	\
	free - To free the previously allocated memory \n	\
	read <flag> <arg> <next N blocks> - To read the data present in the memory\n	\
	write <flag> <arg> <data> - To write data in the memory\n	\
	invert <flag> <arg> <next N blocks> - To invert the data in the memory\n	\
	wpattern <flag> <arg> <next N blocks> <seed> - To generate a random pattern\n	\
	vpattern <flag> <arg> <next N blocks> <seed> - To verify the random pattern\n	\
	exit - To exit the utility\n\n	\
	Use Flag --> '-a' to specify address and '-b' to specify offset\n\
	\tUse arg --> Offset value if '-b' is flag and Address if '-a' is flag\n\n\
	\tNote: allocate, read, write, invert, wpattern and vpattern take hexadecimal inputs for the N blocks field and data field\n"); 	
	return SUCCESS;
}
