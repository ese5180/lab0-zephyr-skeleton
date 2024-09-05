####################################
# nRF7002DK Toolchain File         #
####################################

# NOTE: This is a wrapper for invoking the nrf5340 toolchain file. 
# The nRF7002DK development board features two nrf5340 MCUs but 
# referring to the nRF7002DK as the intended target might make more sense. 

# Include guard
if($ENV{nRF7002DK_TOOLCHAIN_INCLUDED})
        return()
endif()

set(ENV{nRF7002DK_TOOLCHAIN_INCLUDED} TRUE)

# Include nrf5340 toolchain
include(${CMAKE_CURRENT_LIST_DIR}/nrf5340.cmake)

# Include nrfx and ARM CMSIS driver dependencies
include(${CMAKE_CURRENT_LIST_DIR}/../drivers/arm_cmsis_6.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/../drivers/nrfx_driver_package.cmake)