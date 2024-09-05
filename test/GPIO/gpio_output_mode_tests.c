//
// Created by milesosborne on 8/22/24.
//

#include "gpio_tests.h"

/* Set pin 0 to output open-drain mode */
void gpio_output_pin_mode_open_drain_test(void **state)
{
    /* Initialize test port */
    gpio_port test_port;
    test_port.pin_type_config = malloc(REG_SIZE_IN_BYTES);
    test_port.output_data_register = malloc(REG_SIZE_IN_BYTES);
    test_port.output_mode_config = malloc(REG_SIZE_IN_BYTES);
    test_port.pull_up_pull_down_config = malloc(REG_SIZE_IN_BYTES);
    test_port.input_data_register = malloc(REG_SIZE_IN_BYTES);
    gpio_init(&test_port);

    /* NOTE: ALl pins are set to output mode, push-pull when port is enabled */
    gpio_enable_port(&test_port);

    /* Set pin 0 to output mode (open-drain) */
    gpio_set_output_mode(&test_port, GPIO_PIN_0, OPEN_DRAIN);

    /* Initialize expected register state */
    uint32_t expected_register_state = 0x1;

    return assert_int_equal(*test_port.output_mode_config, expected_register_state);
}

/* Set pin 0 to output push-pull mode */
void gpio_output_pin_mode_push_pull_test(void **state)
{
    /* Initialize test port */
    gpio_port test_port;
    test_port.pin_type_config = malloc(REG_SIZE_IN_BYTES);
    test_port.output_data_register = malloc(REG_SIZE_IN_BYTES);
    test_port.output_mode_config = malloc(REG_SIZE_IN_BYTES);
    test_port.pull_up_pull_down_config = malloc(REG_SIZE_IN_BYTES);
    test_port.input_data_register = malloc(REG_SIZE_IN_BYTES);
    gpio_init(&test_port);

    /* NOTE: ALl pins are set to output mode, push-pull when port is enabled */
    gpio_enable_port(&test_port);

    /* Manually set pin 0 to output, open-drain */
    *test_port.output_mode_config = 1;

    /* Set pin 0 to output mode (open-drain) */
    gpio_set_output_mode(&test_port, GPIO_PIN_0, PUSH_PULL);

    /* Initialize expected register state */
    uint32_t expected_register_state = 0x0;

    return assert_int_equal(*test_port.output_mode_config, expected_register_state);
}

