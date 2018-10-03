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
	printf("Usage: [Command] [argument] \n\n The following commands are supported \n	\
    allocate <N block>\n 	\
	free \n	\
	read <flag> <arg> <next N blocks>\n	\
	write <flag> <arg> <data> \n	\
	invert <flag> <arg> <next N blocks> \n 	\
	wpattern <flag> <arg> <next N blocks> <seed> \n 	\
	vpattern <flag> <arg> <next N blocks> <seed> \n 	\
	exit \n ");
	
	return SUCCESS;
}
