####################################
# cortex-m4 toolchain config       #
####################################
# Processor specific toolchain file for cortex-m4 devices/targets

####################################
# Include guard                   #
####################################

if ($ENV{ARM_CORTEX_M4_TOOLCHAIN_INCLUDED})
    return()
endif ()

set(ENV{ARM_CORTEX_M4_TOOLCHAIN_INCLUDED})

####################################
# CPU, Linker, Floating point conf #
####################################
# Set the CPU, linker, and floating point flags

set(CPU_NAME cortex-m4)
set(CPU_FLAGS "-mcpu=cortex-m4 -mthumb")
set(VFP_FLAGS "-mfloat-abi=hard -mfpu=fpv4-sp-d16")

message(${CMAKE_CURRENT_LIST_DIR}/arm-none-eabi-gcc.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/arm-none-eabi-gcc.cmake) # Get base toolchain defaults
