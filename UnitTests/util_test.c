/*CUnit library headers */
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

int init_test (void)
{
	char block[3] = "A";
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
	CU_ASSERT_EQUAL(10, g_nblock);
}

void test_write_function(void)
{
	/*test the write_memory function with valid set of parameters*/
	CU_ASSERT_EQUAL((write_memory("-b 2 FF32")), 1);
	CU_ASSERT_EQUAL((write_memory("-b 9 ABCD")), 1);
    
	/*test the write_memory function with incorrect offset number*/
	CU_ASSERT_NOT_EQUAL((write_memory("-b 11 FFFF")), 1);
	CU_ASSERT_NOT_EQUAL((write_memory("-b 100 FFFF")), 1);

	/*test the write_memory function with incorrect address*/
	CU_ASSERT_NOT_EQUAL((write_memory("-a FFFF AB")), 1);
	CU_ASSERT_NOT_EQUAL((write_memory("-a 1234 AB")), 1);

	/*test if global variables are not overwritten*/
	CU_ASSERT_PTR_NOT_EQUAL(NULL, g_blockptr);
	CU_ASSERT_EQUAL(10, g_nblock);
}


void test_read_function(void)
{
	/*test the read_memory function with valid set of parameters*/
	CU_ASSERT_EQUAL((read_memory("-b 1 3")),1);
    CU_ASSERT_EQUAL((read_memory("-b 3 6")),1);

    /*test the read_memory function with incorrect offset number*/
    CU_ASSERT_NOT_EQUAL((read_memory("-b 11 2")),1);
    CU_ASSERT_NOT_EQUAL((read_memory("-b 100 11")),1);

    /*test the read_memory function with incorrect address*/
    CU_ASSERT_NOT_EQUAL((read_memory("-a FFFF AB")), 1);
    CU_ASSERT_NOT_EQUAL((read_memory("-a 1234 AB")), 1);

    /*test if global variables are not overwritten*/
    CU_ASSERT_PTR_NOT_EQUAL(NULL, g_blockptr);
    CU_ASSERT_EQUAL(10, g_nblock);
}

void test_invert_function(void)
{
    /*test the invert_memory function with valid set of parameters*/
    CU_ASSERT_EQUAL((invert_memory("-b 1 3")),1);
    CU_ASSERT_EQUAL((invert_memory("-b 3 6")),1);

    /*test the invert_memory function with incorrect offset number*/
    CU_ASSERT_NOT_EQUAL((invert_memory("-b 11 2")),1);
    CU_ASSERT_NOT_EQUAL((invert_memory("-b 100 11")),1);

    /*test the invert_memory function with incorrect address*/
    CU_ASSERT_NOT_EQUAL((invert_memory("-a FFFF AB")), 1);
    CU_ASSERT_NOT_EQUAL((invert_memory("-a 1234 AB")), 1);

    /*test if global variables are not overwritten*/
    CU_ASSERT_PTR_NOT_EQUAL(NULL, g_blockptr);
    CU_ASSERT_EQUAL(10, g_nblock);
}

void test_wrpattern_function(void)
{
    /*test the write_pattern function with valid set of parameters*/
    CU_ASSERT_EQUAL((write_pattern("-b 1 3 102")),1);
    CU_ASSERT_EQUAL((write_pattern("-b 3 6 102")),1);

    /*test the write_pattern function with incorrect offset number*/
    CU_ASSERT_NOT_EQUAL((write_pattern("-b 11 2 102")),1);
    CU_ASSERT_NOT_EQUAL((write_pattern("-b 100 11 102")),1);

    /*test the write_pattern function with incorrect address*/
    CU_ASSERT_NOT_EQUAL((write_pattern("-a FFFF AB")), 1);
    CU_ASSERT_NOT_EQUAL((write_pattern("-a 1234 AB")), 1);

    /*test if global variables are not overwritten*/
    CU_ASSERT_PTR_NOT_EQUAL(NULL, g_blockptr);
    CU_ASSERT_EQUAL(10, g_nblock);
}

void test_vpattern_function(void)
{
	/*test the verify_pattern function with valid set of parameters*/
    CU_ASSERT_EQUAL((verify_pattern("-b 1 3 102")),1);
    CU_ASSERT_EQUAL((verify_pattern("-b 3 6 102")),1);

    /*test the verify_pattern function with incorrect offset number*/
    CU_ASSERT_NOT_EQUAL((verify_pattern("-b 11 2 102")),1);
    CU_ASSERT_NOT_EQUAL((verify_pattern("-b 100 11 102")),1);

    /*test the verify_pattern function with incorrect address*/
    CU_ASSERT_NOT_EQUAL((verify_pattern("-a FFFF AB")), 1);
    CU_ASSERT_NOT_EQUAL((verify_pattern("-a 1234 AB")), 1);

    /*test the verify_pattern function with incorrect seed value*/
    CU_ASSERT_NOT_EQUAL((verify_pattern("-b 11 2 111")),1);
    CU_ASSERT_NOT_EQUAL((verify_pattern("-b 100 11 12")),1);

    /*test if global variables are not overwritten*/
    CU_ASSERT_PTR_NOT_EQUAL(NULL, g_blockptr);
    CU_ASSERT_EQUAL(10, g_nblock);
}

int register_test_suite(void) {

    CU_pSuite pSuite = NULL;

   	pSuite = CU_add_suite("Functionality Test", init_test, deinit_test);
    if (NULL == pSuite) {
        return -1;
    }
    /*Adding tests to the suite */
    if ((NULL == CU_add_test(pSuite, "Allocate functionality test", test_allocate_function)) ||
    	(NULL == CU_add_test(pSuite, "Write functionality test", test_write_function)) ||
    	(NULL == CU_add_test(pSuite, "Read functionality test", test_read_function)) ||
    	(NULL == CU_add_test(pSuite, "Invert functionality test", test_invert_function)) ||
    	(NULL == CU_add_test(pSuite, "Write pattern functionality test", test_wrpattern_function)) ||
    	(NULL == CU_add_test(pSuite, "Verify pattern functionality test", test_vpattern_function))) 
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
	CU_set_output_filename("test");
	CU_automated_run_tests();

    CU_cleanup_registry();
    return CU_get_error();
}
