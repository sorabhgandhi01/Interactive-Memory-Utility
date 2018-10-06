#include <CUnit/Automated.h>
#include <CUnit/Basic.h>

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

extern uint32_t *g_blockptr;
extern uint32_t g_nblock;

extern mem_status allocate_memory (char arg[]);
extern mem_status free_memory (char arg[]);
extern mem_status write_memory (char arg[]);
extern mem_status read_memory (char arg[]);
extern mem_status invert_memory (char arg[]);
extern mem_status write_pattern (char arg[]);
extern mem_status verify_pattern (char arg[]);
extern mem_status help (char arg[]);
extern mem_status exit_util (char arg[]);


int init_test (void)
{
	char block[2] = "5";
	allocate_memory(block);

	return 0;
}


int deinit_test (void)
{
	free(g_blockptr);

	return 0;
}


void test_allocate_function(void)
{
	CU_ASSERT_PTR_NOT_EQUAL(NULL, g_blockptr);
	CU_ASSERT_EQUAL(5, g_nblock);
}

void test_write_function(void)
{

}


void test_read_function(void)
{

}

void test_invert_function(void)
{

}

void test_wrpattern_function(void)
{

}

void test_vpattern_function(void)
{

}

int register_test_suite(void) {

    CU_pSuite pSuite = NULL;

   	pSuite = CU_add_suite("Functionality Test", init_test, deinit_test);
    if (NULL == pSuite) {
        return -1;
    }

    if ((NULL == CU_add_test(pSuite, "Allocate functionality test", test_allocate_function)))
    {
        return -1;
    }
    return 0;
}

int main()
{
    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

 	//register_test_suite will add a test suite to the CUnit test registry
    if (register_test_suite() == -1) {
        CU_cleanup_registry();
        return CU_get_error();
    }

	/* Run all tests using CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

    /* Run all tests using the CUnit Automated interface */
	//CU_set_output_filename("test");
	//CU_automated_run_tests();

    CU_cleanup_registry();
    return CU_get_error();
}

