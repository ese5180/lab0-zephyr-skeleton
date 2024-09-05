//
// Created by milesosborne on 8/21/24.
//

#include "gpio_tests.h"

/* Test if a single GPIO pin can set it's respective output data register to 1 */
void gpio_output_pin_set_test(void **state)
{
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

    /* Set pin 0 output data register to 1 */
    gpio_set_output_pin(&test_port, 0);

    /* Initialize expected register state */
    uint32_t expected_output_data_register = 0x1;

    return assert_int_equal(*test_port.output_data_register, expected_output_data_register);
}

void gpio_output_pin_clear_test(void ** state)
{
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

    /* Manually set pin 0 ODR value to 1 */
    *test_port.output_data_register = 1;

    /* Clear pin 0 output data register */
    gpio_clear_output_pin(&test_port, 0);

    /* Initialize expected register state */
    uint32_t expected_output_data_register = 0x0;

    return assert_int_equal(*test_port.output_data_register, expected_output_data_register);
}