#include <string.h>

#include "global.h"


uint64_t chtol(char str[])
{
	uint64_t ret_value = 0;
        uint64_t hex_base = 1;
        int i = 0;

	uint32_t digit = strlen(str);

        for (i = (digit-1); i >= 0; i--)
        {
                if ((str[i] >= '0') && (str[i] <= '9')) {
                        ret_value += (str[i] - 48)*hex_base;

                        hex_base = hex_base * 16;
                }
                else if ((str[i] >= 'A') && (str[i] <= 'F')) {
                        ret_value += (str[i] - 55)*hex_base;

                        hex_base = hex_base * 16;
                }
                else if ((str[i] >= 'a') && (str[i] <= 'f')) {
                        ret_value += (str[i] - 87)*hex_base;

                        hex_base = hex_base * 16;
                }
        }

        return ret_value;
}

uint32_t chtoi(char str[])
{
        uint32_t ret_value = 0;
        uint32_t hex_base = 1;
        int i = 0;

        uint32_t digit = strlen(str);

        for (i = (digit-1); i >= 0; i--)
        {
                if ((str[i] >= '0') && (str[i] <= '9')) {
                        ret_value += (str[i] - 48)*hex_base;

                        hex_base = hex_base * 16;
                }
                else if ((str[i] >= 'A') && (str[i] <= 'F')) {
                        ret_value += (str[i] - 55)*hex_base;

                        hex_base = hex_base * 16;
                }
                else if ((str[i] >= 'a') && (str[i] <= 'f')) {
                        ret_value += (str[i] - 87)*hex_base;

                        hex_base = hex_base * 16;
                }
        }

        return ret_value;
}

uint32_t c_random(uint64_t *addr, uint32_t seed)
{
        uint32_t ret;
        ret = (uintptr_t)(addr);

        ret = ret ^ seed;

        return ret;
}
