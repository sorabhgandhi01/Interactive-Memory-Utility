
#include "writepattern.h"

mem_status write_pattern(char arg[])
{
	char addr[17];
	char r_bytes[9];
	char r_seed[9];

	memset(addr, 0, sizeof(addr));
	memset(r_bytes, 0, sizeof(r_bytes));
	memset(r_seed, 0, sizeof(r_seed));

	sscanf(arg, "%s %s %s", addr, r_bytes, r_seed);

	uint64_t useraddr = chtol(addr);
	uint32_t block = chtoi(r_bytes);
	uint32_t seed = chtoi(r_seed);

	uint32_t i = 0, flag = 0, j = 0;

        for (i = 0; i < g_nblock; i++)
        {
                if ((uint64_t *) &g_blockptr[i] == (uint64_t *) useraddr) {

			g_blockptr[i] = c_random((uint64_t *)&g_blockptr[i], seed);
                        
                        printf("Random Pattern Data at memory address %p is %x\n", &g_blockptr[i], g_blockptr[i]);

                        if ((block != 0) && (block <= (g_nblock - (i+1))))
                        {
                                for (j = (i+1); j < (block + i); j++)
				{
					g_blockptr[j] = c_random((uint64_t *)&g_blockptr[j], seed);

                                        printf("Random Pattern Data at memory address %p is %x\n", &g_blockptr[j], g_blockptr[j]);
				}

                                flag = 1;
                                break;
                        }
                        else if(block == 0)
                        {
                                flag = 1;
                                break;
                        }
                        else {
                                printf("Invalid number of 32-bit words\n");
                                return FAILED;
                        }
                }
        }

        if (flag != 1) {
                printf("Invalid memory address\n");
                return FAILED;
        }

	return SUCCESS;
}
