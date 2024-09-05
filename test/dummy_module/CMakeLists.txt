# Module01 Tests
add_executable(module01 dummy_module_tests_driver.c)

target_sources(module01 PRIVATE
        dummy_module_case_00.c
        dummy_module_case_01.c
                )

target_include_directories(module01 PRIVATE . ${CMAKE_CURRENT_SOURCE_DIR} )
target_include_directories(module01 SYSTEM PRIVATE ${CMOCKA_INCLUDE_DIR})

target_link_libraries(module01 PRIVATE cmocka test_helpers)

add_test(NAME dummy_module_test_case_0 COMMAND module01 0)
add_test(NAME dummy_module_test_case_1 COMMAND module01 1)

message("Module01 Test Found")