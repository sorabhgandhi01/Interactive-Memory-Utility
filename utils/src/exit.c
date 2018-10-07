/**
 * @\file	exit.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of exit functionality of memory utils
 * @\date	09/25/2018
 *
 */
/*system headers*/
#include <stdio.h>
#include <stdlib.h>

/*own header file*/
#include "exit.h"

/**
--------------------------------------------------------------------------------------------
exit_util
--------------------------------------------------------------------------------------------
* This function exits the memory util
*
*   @\param     void
*
*   @\return    None
**/
mem_status exit_util()
{	

	exit(EXIT_SUCCESS);
}

