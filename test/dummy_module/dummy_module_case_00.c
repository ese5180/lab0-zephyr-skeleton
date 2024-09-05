//
// Created by milesosborne on 7/29/24.
//

#include "dummy_module_tests.h"

void dummy_module_test_case_00(void **state)
{
    int i = 4;
    assert_int_equal(i, 4);
}