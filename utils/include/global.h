#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum mem_status
{
	MEMORY_INIT_FAILED = 0,
	MEMORY_INIT_SUCCESS,

	MEMORY_CLEAR_SUCCESS,
	MEMORY_CLEAR_FAILED,

	MEMORY_WRITE_SUCCESS,
	MEMORY_WRITE_FAILED,

	MEMORY_READ_SUCCESS,
	MEMORY_READ_FAILED,

	MEMORY_INVERT_SUCCESS,
	MEMORY_INVERT_FAILED
}mem_status;

uint32_t *g_memblock;


#endif

