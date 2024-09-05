####################################
# ARM CMSIS 6 driver package       #
####################################
include(FetchContent)

# Get CMSIS 6 package - nrfx drivers have a dependency on this
fetchcontent_declare(
       CMSIS_6
       GIT_REPOSITORY https://github.com/ARM-software/cmsis_6.git
       GIT_TAG v6.1.0
)

fetchcontent_makeavailable(CMSIS_6)

FetchContent_GetProperties(CMSIS_6)
message("cmsis_6 source dir: ${cmsis_6_SOURCE_DIR}")

add_library(CMSIS_6_PKG INTERFACE)

# NOTE: For this project, we are not using any of the cortex-m or cortex-r processors
target_include_directories(
       CMSIS_6_PKG
       INTERFACE
       ${cmsis_6_SOURCE_DIR}/CMSIS/Core
       ${cmsis_6_SOURCE_DIR}/CMSIS/Core/Include
       # ${cmsis_6_SOURCE_DIR}/CMSIS/Core/Include/a-profile
       ${cmsis_6_SOURCE_DIR}/CMSIS/Core/Include/m-profile
       # ${cmsis_6_SOURCE_DIR}/CMSIS/Core/Include/r-profile
)

target_sources(
       CMSIS_6_PKG
       PRIVATE
       ${cmsis_6_SOURCE_DIR}/CMSIS/Core/Source/irq_ctrl_gic.c
       ${cmsis_6_SOURCE_DIR}/CMSIS/Core/Template/Device_M/Source/startup_Device.c
       ${cmsis_6_SOURCE_DIR}/CMSIS/Core/Template/Device_M/Source/system_Device.c
)
