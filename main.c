/*----------------------------------------------------------------------------------------
MIT License

Copyright (c) 2018 Sorabh Gandhi / Sanju Prakash Kannioth

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE
-----------------------------------------------------------------------------------------*/

/**
 * @\file	main.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains registration and invoking of memory utils
 * @\date	09/25/2018
 * 
 */                                                                                     

/* System headers */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdint.h>

/* Own headers */
#include "memalloc.h"
#include "memfree.h"
#include "memdisplay.h"
#include "memwrite.h"
#include "xorinvert.h"
#include "writepattern.h"
#include "verifypattern.h"
#include "help.h"
#include "exit.h"

/*Structure defined to store command name and the function invoking that command*/
typedef struct command_list_t {
	const char *cmd_name;

	mem_status (*function_name)(char arg[]);

} command_list_t;


int main ()
{

	/*populate the structure with all the supporting commands and respective function*/
	struct command_list_t command_list[10] = {
		{"write", &write_memory},
		{"read", &read_memory},
        {"allocate", &allocate_memory},
		{"invert", &invert_memory},
		{"wpattern", &write_pattern},
		{"vpattern", &verify_pattern},
        {"free", &free_memory},
		{"help", &help},
        {"exit", &exit_util},
        {NULL, NULL}
	};
                
    char input[50];			//Declare the input buffer to get the user input
	char cmd[10];			//Declare the cmd buffer to store the input command name
	char arg[40];			//Declare the arg buffer to store the command arguments given by the user
	int cmd_flag = 0;		// Flag to indicate the invalid commands

    memset(input, 0, sizeof(input));			//Clear the input buffer

	print_msg("Welcome to the memory utility\n\tType 'help' to get the list of supported commands\n\n");

	/*Run the loop till user enters exit command or ctrl-c*/
	while(1) {

		printf("\n>>");
        scanf(" %[^\n]%*c", input);			//get the user input

      	uint32_t i = 0;

		/*Clear the cmd buffer and arg buffer*/
        memset(cmd, 0, sizeof(cmd));
        memset(arg, 0, sizeof(arg));

        sscanf(input, "%s %[^\n]%*c", cmd, arg);			//Parse the user command and argument
		cmd_flag = 0;

		/*search the input command in list of commands populated in the structure*/
        for (i = 0; command_list[i].function_name; i++) {

			/*Check if the particular input command matches with a command name in the structure*/
			 if (strcmp(cmd, command_list[i].cmd_name) == 0) {
				 (*(command_list[i].function_name))(arg);			//Invoke appropriate function for the input command
				cmd_flag = 1;
			}
		}

		/*Notify the user for the invalid command*/
		if (cmd_flag == 0)
			print_msg("Invalid Command! Type help to get the list of supported commands\n");
    }
	
	exit(EXIT_SUCCESS);
}
