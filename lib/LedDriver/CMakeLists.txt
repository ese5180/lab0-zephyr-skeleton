
add_library(LedDriver)

target_sources(
        LedDriver
        PUBLIC
        LedDriver.c
)

target_include_directories(
        LedDriver
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        .
)

target_link_libraries(LedDriver PUBLIC util)