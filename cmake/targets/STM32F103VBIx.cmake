####################################
# STM32F103VBIx mcu toolchain file #
####################################

# Include guard
if($ENV{STM32F103VBIx_TOOLCHAIN_INCLUDED})
        return()
endif()

set(ENV{STM32F103VBIx_TOOLCHAIN_INCLUDED})

# Get cortex-m3 defaults
include(${CMAKE_CURRENT_LIST_DIR}/../cross-compile/cortex-m3_softfloat.cmake)
include(CMakeDependentOption)

set(linker_file_name "STM32F103VBIx_FLASH.ld")
set(linker_file_path "${CMAKE_SOURCE_DIR}/cmake/")

# Default to ON/TRUE if the linker file name and path are not empty.
cmake_dependent_option(
        CUSTOM_LINKER_SCRIPT_ENABLE
        "Flag that represents if a custom linker script is used"
        ON
        "linker_file_name;linker_file_path"
        OFF
        )

# Set linker flag arguments
set( LD_FLAGS "-T${linker_file_name}, -L${linker_file_path}")