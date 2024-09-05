####################################
# cortex-m3 toolchain config       #
####################################
# Processor specific toolchain file for cortex-m3 devices/targets

####################################
# Include guard                   #
####################################

if ($ENV{ARM_CORTEX_M3_TOOLCHAIN_INCLUDED})
    return()
endif ()

set(ENV{ARM_CORTEX_M3_TOOLCHAIN_INCLUDED})

set(CPU_NAME cortex-m3)
set(CPU_FLAGS "-mcpu=cortex-m3 -mthumb")
set(VFP_FLAGS "-mfloat-abi=soft")

include(${CMAKE_CURRENT_LIST_DIR}/arm-none-eabi-gcc.cmake)