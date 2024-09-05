####################################
# cortex-m33 toolchain config      #
####################################
# Processor specific toolchain file for cortex-m33 devices/targets

####################################
# Include guard                    #
####################################

if ($ENV{ARM_CORTEX_M33_TOOLCHAIN_INCLUDED})
    return()
endif ()

set(ENV{ARM_CORTEX_M33_TOOLCHAIN_INCLUDED})

####################################
# Common Compiler Flags            #
####################################

####################################
# TODO: Set CPU name               #
####################################
set(CPU_NAME "" CACHE INTERNAL "CPU_NAME")

####################################
# TODO: Set CPU flag               #
####################################
set(CPU_FLAGS "" CACHE INTERNAL "CPU_FLAGS")

####################################
# TODO: Set VFP flags              #
# (Vector Floating Point)         # 
####################################
set(VFP_FLAGS "" CACHE INTERNAL "VFP_FLAGS")

# NOTE: We are setting the compiler flags to be cache variable to ensure that it is available 
# to the lower-level toolchain files. 

include(${CMAKE_CURRENT_LIST_DIR}/arm-none-eabi-gcc.cmake)