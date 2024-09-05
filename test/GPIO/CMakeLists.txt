
add_executable(gpio_module_tests gpio_tests_driver.c)

target_sources(gpio_module_tests
        PRIVATE
        gpio_init_test.c
        gpio_port_enable_tests.c
        gpio_pin_type_cfg_tests.c
        gpio_output_pin_tests.c
        gpio_input_mode_tests.c
        gpio_output_mode_tests.c
)

target_include_directories(gpio_module_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(gpio_module_tests SYSTEM PRIVATE ${CMOCKA_INCLUDE_DIR})

target_link_libraries(gpio_module_tests PRIVATE test_helpers cmocka GPIO)

# Add tests to CTEST harness:
add_test(NAME gpio_init_test COMMAND gpio_module_tests 0)
add_test(NAME gpio_port_en_test_0 COMMAND gpio_module_tests 1)
add_test(NAME gpio_port_en_test_1 COMMAND gpio_module_tests 2)
add_test(NAME gpio_port_en_test_2 COMMAND gpio_module_tests 3)

add_test(NAME gpio_set_pin_type_output_test COMMAND gpio_module_tests 4)
add_test(NAME gpio_set_pin_type_input_test COMMAND gpio_module_tests 5)

add_test(NAME gpio_output_pin_set_test COMMAND gpio_module_tests 6)
add_test(NAME gpio_output_pin_clear_test COMMAND gpio_module_tests 7)

add_test(NAME gpio_input_pin_pull_up_test COMMAND gpio_module_tests 8)
add_test(NAME gpio_input_pin_pull_down_test COMMAND gpio_module_tests 9)

add_test(NAME gpio_output_pin_mode_open_drain_test COMMAND gpio_module_tests 10)
add_test(NAME gpio_output_pin_mode_pull_drain_test COMMAND gpio_module_tests 11)


