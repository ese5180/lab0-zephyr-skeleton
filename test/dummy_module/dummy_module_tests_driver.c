//
// Created by milesosborne on 8/20/24.
//

#include "dummy_module_tests.h"

test_info get_test_case(uint32_t test_case);

int main(int argc, char **argv) {
    /* Local variables */
    test_info test_case_ref;

    /* Get test case info */
    test_case_ref = get_test_case(atoi(argv[1]));

    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_case_ref.test_case_ptr)
    };

    return cmocka_run_group_tests_name(test_case_ref.test_group_msg, tests, NULL, NULL);
    return 0;
}

test_info get_test_case(uint32_t test_case) {
    test_info test_info_buf;

    switch (test_case) {
        case TEST_CASE_0:
            test_info_buf.test_case_ptr = &dummy_module_test_case_00;
            sprintf(test_info_buf.test_group_msg, "Dummy module - Test Case 00", NULL);
            break;

        case TEST_CASE_1:
            test_info_buf.test_case_ptr = &dummy_module_test_case_01;
            sprintf(test_info_buf.test_group_msg, "Dummy module - Test Case 01", NULL);
            break;

        default:
            test_info_buf.test_case_ptr = NULL;
            memset(test_info_buf.test_group_msg, 0, sizeof(test_info_buf.test_group_msg));
    }

    return test_info_buf;
}