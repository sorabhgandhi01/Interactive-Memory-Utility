#ifndef _GLOBAL_H
#define _GLOBAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef enum mem_status
{
	FAILED = 0,
	SUCCESS,

}mem_status;

uint32_t *g_blockptr;

uint32_t g_nblock;

uint64_t chtol(char str[]);

uint32_t chtoi(char str[]);

#endif
