/*------------------------------------------------------------------------------------------
MIT License

Copyright (c) 2018 Sorabh Gandhi / Sanju Prakash

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
 * @\file	memalloc.h
 * @\author	Sorabh Gandhi / Sanju Prakash
 * @\brief	This file contains the declaration of memory allocation functionality of 
 * 		memory utils software stack
 * @\date	09/25/2018
 *
 */											   

#ifndef _MEMALLOC_H
#define _MEMALLOC_H

/**
--------------------------------------------------------------------------------------------
memAlloc
--------------------------------------------------------------------------------------------
* This function will allocate specified number of memory blocks in heap segment
*
* 	@\param	n	Number of blocks of memory to be allocated
*
* 	@\return	On success it return 1, On failure the function return -1
*
*/
int memAlloc(uint32_t n);

#endif
