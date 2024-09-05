//
// Created by milesosborne on 8/20/24.
//

#ifndef CMOCKA_SETUP_GPIO_TESTS_H
#define CMOCKA_SETUP_GPIO_TESTS_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include "test_helpers.h"
#include "GPIO.h"

void gpio_init_test(void **state);

void gpio_port_enable_test_0(void **state);
void gpio_port_enable_test_1(void **state);
void gpio_port_enable_test_2(void **state);

void gpio_set_pin_type_test_0(void **state);
void gpio_set_pin_type_test_1(void **state);

void gpio_output_pin_set_test(void **state);
void gpio_output_pin_clear_test(void **state);

void gpio_input_pin_mode_pull_up_test(void **state);
void gpio_input_pin_mode_pull_down_test(void **state);

void gpio_output_pin_mode_open_drain_test(void **state);
void gpio_output_pin_mode_push_pull_test(void **state);


#endif //CMOCKA_SETUP_GPIO_TESTS_H
