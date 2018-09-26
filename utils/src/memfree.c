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
 * @\file	memfree.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the definition of memory free functionality for memory utils
 * @\date	09/25/2018
 *
 */											   

/* System Headers */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

/* Own headers */
#include "memfree.h"

void memFree(uint32_t *ptr){
#if 0
    free(ptr);
    ptr = NULL;
    if(!ptr) 
    printf("The memory block allocated has been successfully freed!\n");
#endif
}
