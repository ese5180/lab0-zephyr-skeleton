//
// Created by milesosborne on 8/21/24.
//

#include "gpio_tests.h"

int main(int argc, char **argv) {
    /* Local variables */
    test_info test_case_ref;

    /* Get test case info */
    test_case_ref = get_test_case(atoi(argv[1]));

    const struct CMUnitTest tests[] = {
            cmocka_unit_test(test_case_ref.test_case_ptr)
    };

    return cmocka_run_group_tests_name(test_case_ref.test_group_msg, tests, NULL, NULL);
}

test_info get_test_case(uint32_t test_case) {
    test_info test_info_buf;
    switch (test_case) {
        case TEST_CASE_0:
            test_info_buf.test_case_ptr = &gpio_init_test;
            sprintf(test_info_buf.test_group_msg, "gpio_init_test", NULL);
            break;

        case TEST_CASE_1:
            test_info_buf.test_case_ptr = &gpio_port_enable_test_0;
            sprintf(test_info_buf.test_group_msg, "gpio_port_enable_test_0", NULL);
            break;

        case TEST_CASE_2:
            test_info_buf.test_case_ptr = &gpio_port_enable_test_1;
            sprintf(test_info_buf.test_group_msg, "gpio_port_enable_test_1", NULL);
            break;

        case TEST_CASE_3:
            test_info_buf.test_case_ptr = &gpio_port_enable_test_2;
            sprintf(test_info_buf.test_group_msg, "gpio_port_enable_test_2", NULL);
            break;

        case TEST_CASE_4:
            test_info_buf.test_case_ptr = &gpio_set_pin_type_test_0;
            sprintf(test_info_buf.test_group_msg, "gpio_set_pin_type_test (OUTPUT)", NULL);
            break;

        case TEST_CASE_5:
            test_info_buf.test_case_ptr = &gpio_set_pin_type_test_1;
            sprintf(test_info_buf.test_group_msg, "gpio_set_pin_type_test (INPUT)", NULL);
            break;

        case TEST_CASE_6:
            test_info_buf.test_case_ptr = &gpio_output_pin_set_test;
            sprintf(test_info_buf.test_group_msg, "gpio_pin_set_test", NULL);
            break;

        case TEST_CASE_7:
            test_info_buf.test_case_ptr = &gpio_output_pin_clear_test;
            sprintf(test_info_buf.test_group_msg, "gpio_pin_clear_test", NULL);
            break;

        case TEST_CASE_8:
            test_info_buf.test_case_ptr = &gpio_input_pin_mode_pull_up_test;
            sprintf(test_info_buf.test_group_msg,  "gpio_input_pin_mode_pull_up_test");
            break;

        case TEST_CASE_9:
            test_info_buf.test_case_ptr = &gpio_input_pin_mode_pull_down_test;
            sprintf(test_info_buf.test_group_msg,  "gpio_input_pin_mode_pull_down_test");
            break;

        case TEST_CASE_10:
            test_info_buf.test_case_ptr = &gpio_output_pin_mode_open_drain_test;
            sprintf(test_info_buf.test_group_msg,  "gpio_output_pin_mode_open_drain_test");
            break;

        case TEST_CASE_11:
            test_info_buf.test_case_ptr = &gpio_output_pin_mode_push_pull_test;
            sprintf(test_info_buf.test_group_msg,  "gpio_output_pin_mode_push_pull_test");
            break;

        case TEST_CASE_12:

            break;

        case TEST_CASE_13:

            break;

        case TEST_CASE_14:

            break;

        case TEST_CASE_15:

            break;

        case TEST_CASE_16:

            break;
        default:
            /* ERROR - Test ID not detected or invalid! Did you assign an ID in the respective CMakeLists.txt */
            test_info_buf.test_case_ptr = NULL;
            memset(test_info_buf.test_group_msg, 0, sizeof(test_info_buf.test_group_msg));
    }

    return test_info_buf;
}