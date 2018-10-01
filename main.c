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
#include "help.h"
#include "exit.h"


typedef struct command_list_t {

        const char *cmd_name;

        mem_status (*function_name)(char arg[]);

} command_list_t;


int main ()
{
	struct command_list_t command_list[7] = {
		{"write", &write_memory},
		{"read", &read_memory},
                {"allocate", &allocate_memory},
		{"invert", &invert_memory},
                {"free", &free_memory},
                {"exit", &exit_util},
                {NULL, NULL}
        };
                
        char input[50];
	char cmd[10];
	char arg[40];

        memset(input, 0, sizeof(input));

	printf("Welcome to the memory utility\n");

        while(1)
        {
                printf("Enter a fuction to call\n");
                scanf(" %[^\n]%*c", input);

	       	uint32_t i = 0;

                memset(cmd, 0, sizeof(cmd));
                memset(arg, 0, sizeof(arg));

                sscanf(input, "%s %[^\n]%*c", cmd, arg);

                for (i = 0; command_list[i].function_name; i++)
                {
                        if (strcmp(cmd, command_list[i].cmd_name) == 0)
                                (*(command_list[i].function_name))(arg);
                }
        }

        exit(EXIT_SUCCESS);
}
