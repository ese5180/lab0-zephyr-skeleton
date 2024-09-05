//
// Created by milesosborne on 8/20/24.
//

#include "gpio_tests.h"
#if 0
///* TODO: Move the test_port initialization to test setup. We can reduce some of the duplicated code! */
#endif
/* Test port enable output type */
/* NOTE: All pins of the respective port should be in output mode */
void gpio_port_enable_test_0(void **state) {

    /* Initialize test port */
    gpio_port test_port;
    test_port.pin_type_config = malloc(REG_SIZE_IN_BYTES);
    test_port.output_data_register = malloc(REG_SIZE_IN_BYTES);
    test_port.output_mode_config = malloc(REG_SIZE_IN_BYTES);
    test_port.pull_up_pull_down_config = malloc(REG_SIZE_IN_BYTES);
    test_port.input_data_register = malloc(REG_SIZE_IN_BYTES);
    gpio_init(&test_port);

    /* NOTE: For this test, we shall set the value to a non-nominal state. If the UUT is implemented correctly
     * it shall place the pins in the correct state */
    memset(test_port.pin_type_config, 0xFF, REG_SIZE_IN_BYTES);

    /* Initialize expected register state */
    uint32_t expected_pin_type_reg_state = 0xFFFFFFFF;

    /* Invoke unit under test */
    gpio_enable_port(&test_port);

    return assert_int_equal(*test_port.pin_type_config, expected_pin_type_reg_state);
}

/* Test port enable output value */
/* NOTE: All pins of the respective port should have a register value of 0 */
void gpio_port_enable_test_1(void **state) {

    /* Initialize test port */
    gpio_port test_port;
    test_port.pin_type_config = malloc(REG_SIZE_IN_BYTES);
    test_port.output_data_register = malloc(REG_SIZE_IN_BYTES);
    test_port.output_mode_config = malloc(REG_SIZE_IN_BYTES);
    test_port.pull_up_pull_down_config = malloc(REG_SIZE_IN_BYTES);
    test_port.input_data_register = malloc(REG_SIZE_IN_BYTES);
    gpio_init(&test_port);

    /* NOTE: For this test, we shall set the value to a non-nominal state. If the UUT is implemented correctly
     * it shall place the pins in the correct state */
    memset(test_port.output_mode_config, 0xAA, REG_SIZE_IN_BYTES);

    /* Initialize expected register state */
    uint32_t expected_output_mode_register_state = 0;

    /* Invoke unit under test */
    gpio_enable_port(&test_port);
    return assert_int_equal(*test_port.output_mode_config, expected_output_mode_register_state);
}

/* Test port enable pin config type */
/* NOTE: All pins of the respective port should be in push-pull mode */
void gpio_port_enable_test_2(void **state) {

    /* Initialize test port */
    gpio_port test_port;
    test_port.pin_type_config = malloc(REG_SIZE_IN_BYTES);
    test_port.output_data_register = malloc(REG_SIZE_IN_BYTES);
    test_port.output_mode_config = malloc(REG_SIZE_IN_BYTES);
    test_port.pull_up_pull_down_config = malloc(REG_SIZE_IN_BYTES);
    test_port.input_data_register = malloc(REG_SIZE_IN_BYTES);
    gpio_init(&test_port);

    /* NOTE: For this test, we shall set the value to a non-nominal state. If the UUT is implemented correctly
     * it shall place the pins in the correct state */
    memset(test_port.output_data_register, 0xAA, REG_SIZE_IN_BYTES);

    /* Initialize expected register state */
    uint32_t expected_output_data_register_state = 0;

    /* Invoke unit under test */
    gpio_enable_port(&test_port);
    return assert_int_equal(*test_port.output_data_register, expected_output_data_register_state);
}