//
// Created by milesosborne on 8/19/24.
//

#include "dummy_module_tests.h"

void dummy_module_test_case_01(void **state)
{
    int i = 5;
    assert_int_equal(i, 5);
}