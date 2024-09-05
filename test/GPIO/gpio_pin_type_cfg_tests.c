//
// Created by milesosborne on 8/21/24.
//

#include "gpio_tests.h"

/* Set pin type to output */
void gpio_set_pin_type_test_0(void **state) {
    /* Initialize test port */
    gpio_port test_port;
    test_port.pin_type_config = malloc(REG_SIZE_IN_BYTES);
    test_port.output_data_register = malloc(REG_SIZE_IN_BYTES);
    test_port.output_mode_config = malloc(REG_SIZE_IN_BYTES);
    test_port.pull_up_pull_down_config = malloc(REG_SIZE_IN_BYTES);
    test_port.input_data_register = malloc(REG_SIZE_IN_BYTES);
    gpio_init(&test_port);

    /* Enable test port */
    gpio_enable_port(&test_port);

    /* Manually set pin 0 on respective port to input.  */
    /* NOTE: This is done because upon port initialization, each GPIO pin is set to output */
    memset(test_port.pin_type_config, INPUT, REG_SIZE_IN_BYTES);

    /* Set pin 0 to output type */
    gpio_set_pin_type(&test_port, GPIO_PIN_0, OUTPUT);

    /* Define expected port state */
    uint32_t expected_port_state = 0x1;

    return assert_int_equal(*test_port.pin_type_config, expected_port_state);
}

void gpio_set_pin_type_test_1(void **state) {
    /* Initialize test port */
    gpio_port test_port;
    test_port.pin_type_config = malloc(REG_SIZE_IN_BYTES);
    test_port.output_data_register = malloc(REG_SIZE_IN_BYTES);
    test_port.output_mode_config = malloc(REG_SIZE_IN_BYTES);
    test_port.pull_up_pull_down_config = malloc(REG_SIZE_IN_BYTES);
    test_port.input_data_register = malloc(REG_SIZE_IN_BYTES);
    gpio_init(&test_port);

    /* Enable test port */
    /* NOTE: Upon enabling the port, the pin is set to output mode so no need to manually set pin type*/
    gpio_enable_port(&test_port);

    /* Set pin 0 to input type */
    gpio_set_pin_type(&test_port, GPIO_PIN_0, INPUT);

    /* Define expected port state */
    uint32_t expected_port_state = ~(1 << 0);

    return assert_int_equal(*test_port.pin_type_config, expected_port_state);
}