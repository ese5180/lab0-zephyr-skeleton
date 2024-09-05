
add_library(GPIO)

target_sources(GPIO
        PUBLIC
        GPIO.c)

target_include_directories(
        GPIO
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)