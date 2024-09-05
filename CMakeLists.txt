######################################
# ESE 5180 Lab 0 Project             #
######################################
cmake_minimum_required(VERSION 3.18.0)
project(ESE_5180_Lab_0 VERSION 1.0 LANGUAGES C CXX ASM)
set(CMAKE_C_STANDARD 11)

######################################
# Get libraries from subdirectories  #
######################################
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/GPIO)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/LedDriver)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/util)

######################################
# Hello World Starter Application    #
######################################
add_executable(HelloWorld)
target_sources(HelloWorld PRIVATE src/main.c)

######################################
# Building embedded application      #
######################################
if(CMAKE_CROSSCOMPILING)
    message("Cross compilation enabled")  
    add_executable(application)

    # Functions that convert compiler output files to *.bin and *.hex formats
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/cross-compile/Conversions.cmake)

######################################
# Setup application for target       #
######################################
if(DEFINED ENV{nRF7002DK_TOOLCHAIN_INCLUDED})
    message("nRF7002DK toolchain included")
    message("${nrfx-drivers_SOURCE_DIR}")

    # Add target definitions for nrfx drivers
    # This informs the compiler which header files to include
    target_compile_definitions(nrfx_driver_package PUBLIC NRF5340_XXAA_APPLICATION)
    target_compile_definitions(nrfx_driver_package PUBLIC NRF5340_XXAA) 
    target_compile_definitions(nrfx_driver_package PUBLIC NRF_APPLICATION)

    # Link application with nrfx drivers
    target_link_libraries(application nrfx_driver_package CMSIS_6_PKG)

    # Set output directories
    set_target_properties(application
            PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
            LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/nRF7002DK/bin"
    )
endif()

    target_sources(application PRIVATE src/turnOnLEDs.c)
    # Export .elf and .bin files if cross-compilation is enabled
    convert_elf_to_bin(application "nRF7002DK/bin")
    convert_elf_to_hex(application "nRF7002DK/bin")
endif(CMAKE_CROSSCOMPILING)

######################################
# Build testing suite                #
######################################
if(NOT CMAKE_CROSSCOMPILING)
# TODO: Add testing subdirectory!
endif(NOT CMAKE_CROSSCOMPILING)
