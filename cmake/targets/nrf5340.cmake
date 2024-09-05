####################################
# nrf5340 mcu toolchain file #
####################################

# Include guard
if($ENV{nrf5340_TOOLCHAIN_INCLUDED})
        return()
endif()

set(ENV{nrf5340_TOOLCHAIN_INCLUDED} TRUE)

# Set linker script paths

####################################
# TODO: Set linker file name       #
####################################
set(LINKER_SCRIPT "")

####################################
# TODO: Set linker file path       #
####################################
set(LINKER_SCRIPT_PATH "")

# Set linker flag arguments
set(LD_FLAGS "-T${LINKER_FILE_PATH}/${LINKER_FILE_NAME}" CACHE INTERNAL "LD_FLAGS")

# NOTE: We are making LD_FLAGS a cache variable to ensure that it is available 
# to the lower-level toolchain files. 

# Include cortex m33 toolchain
include(${CMAKE_CURRENT_LIST_DIR}/../cross-compile/cortex-m33_hardfloat.cmake)


