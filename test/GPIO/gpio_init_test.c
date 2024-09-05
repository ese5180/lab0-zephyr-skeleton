//
// Created by milesosborne on 8/20/24.
//

#include "gpio_tests.h"

void gpio_init_test(void **state) {
    /* Initialize test port */
    gpio_port test_port;
    test_port.pin_type_config = malloc(REG_SIZE_IN_BYTES);
    test_port.output_data_register = malloc(REG_SIZE_IN_BYTES);
    test_port.output_mode_config = malloc(REG_SIZE_IN_BYTES);
    test_port.pull_up_pull_down_config = malloc(REG_SIZE_IN_BYTES);
    test_port.input_data_register = malloc(REG_SIZE_IN_BYTES);

    /* NOTE: For this test, we shall set the port to a non-nominal state. If the UUT is implemented correctly
     * it shall place the pins in the correct state */
    memset(test_port.pin_type_config, 0x10, REG_SIZE_IN_BYTES);
    memset(test_port.output_data_register, 0x32, REG_SIZE_IN_BYTES);
    memset(test_port.output_mode_config, 0x65, REG_SIZE_IN_BYTES);
    memset(test_port.pull_up_pull_down_config, 0x87, REG_SIZE_IN_BYTES);
    memset(test_port.input_data_register, 0x98, REG_SIZE_IN_BYTES);

    /* Invoke unit under test */
    gpio_init(&test_port);

    /* Initialize expected port state */
    uint32_t expected_port_state = 0;

    uint32_t test_port_state;
    test_port_state =
            *test_port.pin_type_config |
            *test_port.output_mode_config |
            *test_port.output_data_register |
            *test_port.input_data_register |
            *test_port.pull_up_pull_down_config;

    return assert_int_equal(test_port_state, expected_port_state);
}