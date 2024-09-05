####################################
# nrfx driver package             #
####################################
include(FetchContent)

# Get nrfx drivers
fetchcontent_declare(
        nrfx-drivers
        GIT_REPOSITORY https://github.com/NordicSemiconductor/nrfx.git
        GIT_TAG v3.6.0
)
fetchcontent_makeavailable(nrfx-drivers)
message("nrfx_drivers found: ${nrfx-drivers_SOURCE_DIR}")

#Create nrfx driver library target
add_library(nrfx_driver_package)

# NOTE: Manually changing the environemnt variable that stores the driver 
# location should only be used for debugging or testing with manual package install
# set(nrfx-drivers_SOURCE_DIR "lib/nrfx")

target_include_directories(nrfx_driver_package
       PUBLIC
       ${nrfx-drivers_SOURCE_DIR}
       ${nrfx-drivers_SOURCE_DIR}/src
       ${nrfx-drivers_SOURCE_DIR}/hal
       ${nrfx-drivers_SOURCE_DIR}/haly
       ${nrfx-drivers_SOURCE_DIR}/templates
       ${nrfx-drivers_SOURCE_DIR}/soc
       ${nrfx-drivers_SOURCE_DIR}/drivers
       ${nrfx-drivers_SOURCE_DIR}/drivers/include
       ${nrfx-drivers_SOURCE_DIR}/mdk
       ${nrfx-drivers_SOURCE_DIR}/include
)

target_sources(nrfx_driver_package
       PUBLIC
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_adc.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_bellboard.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_clock.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_comp.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_dppi.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_egu.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_gpiote.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_grtc.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_i2s.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_ipc.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_lpcomp.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_nfct.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_nvmc.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_pdm.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_power.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_ppi.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_pwm.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_qdec.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_qspi.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_rng.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_rramc.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_rtc.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_saadc.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_spi.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_spim.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_spis.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_systick.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_tbm.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_temp.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_timer.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_twi_twim.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_twi.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_twis.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_uart.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_uarte.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_usbd.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_usbreg.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_vevif.c
       ${nrfx-drivers_SOURCE_DIR}/drivers/src/nrfx_wdt.c

       # System startup sources DO NOT DELETE
       ${nrfx-drivers_SOURCE_DIR}/mdk/gcc_startup_nrf5340_application.S
       # ${nrfx-drivers_SOURCE_DIR}/mdk/startup_nrf_common.c
       ${nrfx-drivers_SOURCE_DIR}/mdk/system_nrf5340_application.c
)

target_link_libraries(nrfx_driver_package CMSIS_6_PKG)


