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
 * @\file	memwrite.h
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the declaration of memory write functionality for memory utils
 * @\date	09/25/2018
 *
 */											   

#ifndef _MEMWRITE_H
#define _MEMWRITE_H

/**
--------------------------------------------------------------------------------------------------
memWrite
--------------------------------------------------------------------------------------------------
* This function will write data into the specified memory block
*
* 	@\param	addr	Memory address specified by the user
* 	@\param data	Data specified by the user to write in the memory block
*
* 	@\return	None
*
*/
void memWrite(uint32_t addr, uint32_t data);

#endif
