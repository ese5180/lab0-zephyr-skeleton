add_executable(LedDriverTest)

target_sources(LedDriverTest
        PRIVATE
        LedDriverTestDriver.c
        LedDriverTest.c
        RuntimeErrorStub.c
)

target_include_directories(LedDriverTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(LedDriverTest SYSTEM PRIVATE ${CMOCKA_INCLUDE_DIR})
target_include_directories(LedDriverTest PRIVATE ${unity_INCLUDE_DIR})

target_link_libraries(LedDriverTest PRIVATE test_helpers LedDriver UNITY)

add_test(LedDriverTest_suite LedDriverTest)