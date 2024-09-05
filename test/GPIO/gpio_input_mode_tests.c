//
// Created by milesosborne on 8/22/24.
//

#include "gpio_tests.h"

/* Set pin 0 to input with pull-up resistor enabled */
void gpio_input_pin_mode_pull_up_test(void **state) {

    /* Initialize test port */
    gpio_port test_port;
    test_port.pin_type_config = malloc(REG_SIZE_IN_BYTES);
    test_port.output_data_register = malloc(REG_SIZE_IN_BYTES);
    test_port.output_mode_config = malloc(REG_SIZE_IN_BYTES);
    test_port.pull_up_pull_down_config = malloc(REG_SIZE_IN_BYTES);
    test_port.input_data_register = malloc(REG_SIZE_IN_BYTES);
    gpio_init(&test_port);

    /* NOTE: ALl pins are set to output mode when port is enabled */
    gpio_enable_port(&test_port);

    /* Manually set pin 0 to enable pull-down resistor */
    *test_port.pull_up_pull_down_config = 0;

    /* Set pin 0 to input mode with pull-up */
    gpio_set_input_mode(&test_port, GPIO_PIN_0, PULL_UP);

    /* Initialize expected register state */
    uint32_t expected_register_state = 0x1;

    return assert_int_equal(*test_port.pull_up_pull_down_config, expected_register_state);
}

/* Set pin 0 to input with pull-down resistor enabled */
void gpio_input_pin_mode_pull_down_test(void **state) {

    /* Initialize test port */
    gpio_port test_port;
    test_port.pin_type_config = malloc(REG_SIZE_IN_BYTES);
    test_port.output_data_register = malloc(REG_SIZE_IN_BYTES);
    test_port.output_mode_config = malloc(REG_SIZE_IN_BYTES);
    test_port.pull_up_pull_down_config = malloc(REG_SIZE_IN_BYTES);
    test_port.input_data_register = malloc(REG_SIZE_IN_BYTES);
    gpio_init(&test_port);

    /* NOTE: ALl pins are set to output mode when port is enabled */
    gpio_enable_port(&test_port);

    /* Manually set pin 0 to enable pull-up resistor */
    *test_port.pull_up_pull_down_config = 1;

    /* Set pin 0 to input mode with pull-down */
    gpio_set_input_mode(&test_port, GPIO_PIN_0, PULL_DOWN);

    /* Initialize expected register state */
    uint32_t expected_register_state = 0x0;

    return assert_int_equal(*test_port.pull_up_pull_down_config, expected_register_state);
}
