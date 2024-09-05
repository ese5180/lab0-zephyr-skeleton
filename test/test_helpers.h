//
// Created by milesosborne on 8/20/24.
//

#ifndef CMOCKA_SETUP_TEST_HELPERS_H
#define CMOCKA_SETUP_TEST_HELPERS_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define TEST_CASE_0 0
#define TEST_CASE_1 1
#define TEST_CASE_2 2
#define TEST_CASE_3 3
#define TEST_CASE_4 4
#define TEST_CASE_5 5
#define TEST_CASE_6 6
#define TEST_CASE_7 7
#define TEST_CASE_8 8
#define TEST_CASE_9 9
#define TEST_CASE_10 10
#define TEST_CASE_11 11
#define TEST_CASE_12 12
#define TEST_CASE_13 13
#define TEST_CASE_14 14
#define TEST_CASE_15 15
#define TEST_CASE_16 16

typedef struct
{
    char test_group_msg[64];    /* Short message indicating the test case */
    void * test_case_ptr;       /* Function pointer for the unit under test */
}test_info;

test_info get_test_case(uint32_t test_case);

#endif //CMOCKA_SETUP_TEST_HELPERS_H
