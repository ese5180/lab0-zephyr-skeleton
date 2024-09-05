####################################
# cortex-m7 toolchain config       #
####################################
# Processor specific toolchain file for cortex-m7 devices/targets

####################################
# Include guard                   #
####################################

if ($ENV{ARM_CORTEX_M7_TOOLCHAIN_INCLUDED})
    return()
endif ()

set(ENV{ARM_CORTEX_M7_TOOLCHAIN_INCLUDED})

set(CPU_NAME cortex-m7)
set(CPU_FLAGS "-mcpu=cortex-m7 -mthumb")
set(VFP_FLAGS "-mfloat-abi=hard -mfpu=fpv4-sp-d16")

include(${CMAKE_CURRENT_LIST_DIR}/arm-none-eabi-gcc.cmake)