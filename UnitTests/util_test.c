
/**
 * @\file	util_test.c
 * @\author	Sorabh Gandhi / Sanju Prakash Kannioth
 * @\brief	This file contains the unit test function for all the mem_utility commands
 * @\date	09/25/2018
 *
 */

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


/*-----------------------------------Allocate Function Test---------------------------------*/

void test_allocate_function(void)
{
	CU_ASSERT_PTR_NOT_EQUAL(NULL, g_blockptr);
	CU_ASSERT_EQUAL(10, g_nblock);
}

/*-------------------------------------Write Function Test---------------------------------*/

void test_write_function(void)
{
	char test_1[20];
	char test_2[20];
	snprintf(test_1, 20, "-a %p ABCD", g_blockptr);
	snprintf(test_2, 20, "-a %p FFFF", (g_blockptr + 1));

	/*test the write_memory function with valid set of parameters using block flag*/
	CU_ASSERT_EQUAL((write_memory("-b 2 FF32")), 1);
	CU_ASSERT_EQUAL((write_memory("-b 9 ABCD")), 1);

	/*test the write_memory function with valid set of parameters using address flag*/
	CU_ASSERT_EQUAL((write_memory(test_1)), 1);
	CU_ASSERT_EQUAL((write_memory(test_2)), 1);

	/*test the write_memory function with incorrect offset flag*/
    CU_ASSERT_NOT_EQUAL((write_memory("-c 2 FFFF")), 1);
    CU_ASSERT_NOT_EQUAL((write_memory("-b0 0 FFFF")), 1);
    
	/*test the write_memory function with incorrect offset number*/
	CU_ASSERT_NOT_EQUAL((write_memory("-b 11 FFFF")), 1);
	CU_ASSERT_NOT_EQUAL((write_memory("-b 100 FFFF")), 1);

	 /*test the write_memory function with out-of range 32bit data*/
    CU_ASSERT_NOT_EQUAL((write_memory("-b 2 AABBCCDDEE")), 1);
    CU_ASSERT_NOT_EQUAL((write_memory("-b 0 999999999")), 1);
	CU_ASSERT_NOT_EQUAL((write_memory("-b 2 FFFFFFFFF")), 1);
    CU_ASSERT_NOT_EQUAL((write_memory("-b 0 FFFFFFFF1")), 1);

	/*test the write_memory function with incorrect address flag*/
    CU_ASSERT_NOT_EQUAL((write_memory("-d FFFF AB")), 1);
    CU_ASSERT_NOT_EQUAL((write_memory("-a89 1234 AB")), 1);

	/*test the write_memory function with incorrect address*/
	CU_ASSERT_NOT_EQUAL((write_memory("-a FFFF AB")), 1);
	CU_ASSERT_NOT_EQUAL((write_memory("-a 1234 AB")), 1);

	/*test if global variables are not overwritten*/
	CU_ASSERT_PTR_NOT_EQUAL(NULL, g_blockptr);
	CU_ASSERT_EQUAL(10, g_nblock);
}

/*-------------------------------------Read Function Test---------------------------------*/

void test_read_function(void)
{
	char test_1[20];
    char test_2[20];
    snprintf(test_1, 20, "-a %p 6", g_blockptr);
    snprintf(test_2, 20, "-a %p 2", (g_blockptr + 1));

	/*test the read_memory function with valid set of parameters using block flag*/
	CU_ASSERT_EQUAL((read_memory("-b 1 3")), 1);
    CU_ASSERT_EQUAL((read_memory("-b 3 6")), 1);

	/*test the read_memory function with valid set of parameters using address flag*/
    CU_ASSERT_EQUAL((read_memory(test_1)), 1);
    CU_ASSERT_EQUAL((read_memory(test_2)), 1);

	/*test the read_memory function with incorrect offset flag*/
    CU_ASSERT_NOT_EQUAL((read_memory("-c 11 2")),1);
    CU_ASSERT_NOT_EQUAL((read_memory("-b0 100 11")),1);

    /*test the read_memory function with incorrect offset number*/
    CU_ASSERT_NOT_EQUAL((read_memory("-b 11 2")),1);
    CU_ASSERT_NOT_EQUAL((read_memory("-b 100 11")),1);

	/*test the read_memory function with incorrect address flag*/
    CU_ASSERT_NOT_EQUAL((read_memory("-d FFFF AB")), 1);
    CU_ASSERT_NOT_EQUAL((read_memory("-a00 1234 AB")), 1);

    /*test the read_memory function with incorrect address*/
    CU_ASSERT_NOT_EQUAL((read_memory("-a FFFF AB")), 1);
    CU_ASSERT_NOT_EQUAL((read_memory("-a 1234 AB")), 1);

    /*test if global variables are not overwritten*/
    CU_ASSERT_PTR_NOT_EQUAL(NULL, g_blockptr);
    CU_ASSERT_EQUAL(10, g_nblock);
}

/*-------------------------------------Invert Function Test---------------------------------*/

void test_invert_function(void)
{
	char test_1[20];
    char test_2[20];
    snprintf(test_1, 20, "-a %p 6", g_blockptr);
    snprintf(test_2, 20, "-a %p 2", (g_blockptr + 1));	

    /*test the invert_memory function with valid set of parameters using block flag*/
    CU_ASSERT_EQUAL((invert_memory("-b 1 3")), 1);
    CU_ASSERT_EQUAL((invert_memory("-b 3 6")), 1);

	/*test the invert_memory function with valid set of parameters using address flag*/
    CU_ASSERT_EQUAL((invert_memory(test_1)), 1);
    CU_ASSERT_EQUAL((invert_memory(test_2)), 1);

	/*test the invert_memory function with incorrect offset flag*/
    CU_ASSERT_NOT_EQUAL((invert_memory("-z 11 2")), 1);
    CU_ASSERT_NOT_EQUAL((invert_memory("-0b0 100 11")), 1);

    /*test the invert_memory function with incorrect offset number*/
    CU_ASSERT_NOT_EQUAL((invert_memory("-b 11 2")), 1);
    CU_ASSERT_NOT_EQUAL((invert_memory("-b 100 11")), 1);

	/*test the invert_memory function with incorrect address flag*/
    CU_ASSERT_NOT_EQUAL((invert_memory("-p FFFF AB")), 1);
    CU_ASSERT_NOT_EQUAL((invert_memory("-3a 1234 AB")), 1);

    /*test the invert_memory function with incorrect address*/
    CU_ASSERT_NOT_EQUAL((invert_memory("-a FFFF AB")), 1);
    CU_ASSERT_NOT_EQUAL((invert_memory("-a 1234 AB")), 1);

    /*test if global variables are not overwritten*/
    CU_ASSERT_PTR_NOT_EQUAL(NULL, g_blockptr);
    CU_ASSERT_EQUAL(10, g_nblock);
}

/*-------------------------------------Write Pattern Function Test---------------------------------*/

void test_wrpattern_function(void)
{
	char test_1[20];
    char test_2[20];
    snprintf(test_1, 20, "-a %p 6 FF", g_blockptr);
    snprintf(test_2, 20, "-a %p 2 AB", (g_blockptr + 1));

    /*test the write_pattern function with valid set of parameters using block flag*/
    CU_ASSERT_EQUAL((write_pattern("-b 1 3 102")), 1);
    CU_ASSERT_EQUAL((write_pattern("-b 3 6 102")), 1);

	/*test the write_pattern function with valid set of parameters using address flag*/
    CU_ASSERT_EQUAL((write_pattern(test_1)), 1);
    CU_ASSERT_EQUAL((write_pattern(test_2)), 1);

	/*test the write_pattern function with incorrect offset flag*/
    CU_ASSERT_NOT_EQUAL((write_pattern("-k 11 2 102")), 1);
    CU_ASSERT_NOT_EQUAL((write_pattern("-b' 100 11 102")), 1);

    /*test the write_pattern function with incorrect offset number*/
    CU_ASSERT_NOT_EQUAL((write_pattern("-b 11 2 102")), 1);
    CU_ASSERT_NOT_EQUAL((write_pattern("-b 100 11 102")), 1);

	/*test the write_pattern function with out-of-range seed value*/
    CU_ASSERT_NOT_EQUAL((write_pattern("-b 1 2 FFFFFFFFF")), 1);
    CU_ASSERT_NOT_EQUAL((write_pattern("-b 2 0 AABBCCDDEE")), 1);
    CU_ASSERT_NOT_EQUAL((write_pattern("-b 1 2 999999999")), 1);
    CU_ASSERT_NOT_EQUAL((write_pattern("-b 2 0 AABBCCDD01")), 1);

	/*test the write_pattern function with incorrect address flag*/
    CU_ASSERT_NOT_EQUAL((write_pattern("-q FFFF AB")), 1);
    CU_ASSERT_NOT_EQUAL((write_pattern("-a= 1234 AB")), 1);

    /*test the write_pattern function with incorrect address*/
    CU_ASSERT_NOT_EQUAL((write_pattern("-a FFFF AB")), 1);
    CU_ASSERT_NOT_EQUAL((write_pattern("-a 1234 AB")), 1);

    /*test if global variables are not overwritten*/
    CU_ASSERT_PTR_NOT_EQUAL(NULL, g_blockptr);
    CU_ASSERT_EQUAL(10, g_nblock);
}

/*-----------------------------------Verify Pattern Function Test---------------------------------*/

void test_vpattern_function(void)
{
	char test_1[20];
    char test_2[20];
    snprintf(test_1, 20, "-a %p 6 FF", g_blockptr);
    snprintf(test_2, 20, "-a %p 2 AB", (g_blockptr + 1));

	/*test the verify_pattern function with valid set of parameters using block flag*/
    CU_ASSERT_EQUAL((verify_pattern("-b 1 3 102")), 1);
    CU_ASSERT_EQUAL((verify_pattern("-b 3 6 102")), 1);

	/*test the verify_pattern function with valid set of parameters using address flag*/
    CU_ASSERT_EQUAL((verify_pattern(test_1)), 1);
    CU_ASSERT_EQUAL((verify_pattern(test_2)), 1);

	/*test the verify_pattern function with incorrect offset flag*/
    CU_ASSERT_NOT_EQUAL((verify_pattern("-v 11 2 102")), 1);
    CU_ASSERT_NOT_EQUAL((verify_pattern("=b 100 11 102")), 1);

    /*test the verify_pattern function with incorrect offset number*/
    CU_ASSERT_NOT_EQUAL((verify_pattern("-b 11 2 102")), 1);
    CU_ASSERT_NOT_EQUAL((verify_pattern("-b 100 11 102")), 1);

	/*test the verify_pattern function with out-of-range seed value*/
    CU_ASSERT_NOT_EQUAL((verify_pattern("-b 1 2 FFFFFFFFF")), 1);
    CU_ASSERT_NOT_EQUAL((verify_pattern("-b 2 0 AABBCCDDEE")), 1);
	CU_ASSERT_NOT_EQUAL((verify_pattern("-b 1 2 999999999")), 1);
    CU_ASSERT_NOT_EQUAL((verify_pattern("-b 2 0 AABBCCDD01")), 1);

	/*test the verify_pattern function with incorrect address flag*/
    CU_ASSERT_NOT_EQUAL((verify_pattern("~a FFFF AB")), 1);
    CU_ASSERT_NOT_EQUAL((verify_pattern("-A 1234 AB")), 1);

    /*test the verify_pattern function with incorrect address*/
    CU_ASSERT_NOT_EQUAL((verify_pattern("-a FFFF AB")), 1);
    CU_ASSERT_NOT_EQUAL((verify_pattern("-a 1234 AB")), 1);

    /*test the verify_pattern function with incorrect seed value*/
    CU_ASSERT_NOT_EQUAL((verify_pattern("-b 11 2 111")), 1);
    CU_ASSERT_NOT_EQUAL((verify_pattern("-b 100 11 12")), 1);

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
