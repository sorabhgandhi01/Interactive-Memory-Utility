/**
 * @\file	help.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of help functionality for memory utils
 * @\date	09/25/2018
 *
 */											   

/* Own headers */
#include "help.h"

/**
 * @\brief help()
 * This function displays all the available commands that the program can perform  
 * @\return SUCCESS or FAILED
**/

mem_status help()
{
	printf("Usage: [Command] [argument] \n \
			The following commands are supported \n	\
				allocate <block size> \n 	\
				free \n	\
				read <address> <block size> \n	\
				write <address> <data in hexadecimal> \n	\
				invert <address> <block size> \n 	\
				wpattern <address> <block size> <seed> \n 	\
				vpattern <address> <block size> <seed> \n 	\
				exit \n ");
	
	return SUCCESS;
}
