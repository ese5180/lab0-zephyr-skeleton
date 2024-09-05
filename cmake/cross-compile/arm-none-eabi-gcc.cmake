####################################
# arm-none-eabi-gcc Base Toolchain #
####################################
# To include this file as a base toolchain file,
# include it at the bottom of the derived toolchain file.
#
# You can define CPU_FLAGS that will be passed to CMAKE_*_FLAGS to select the CPU
# (and any other necessary CPU-specific flags)
# You can define VFP_FLAGS to select the desired floating-point configuration
# You can define LD_FLAGS to control linker flags for your target


####################################
# System Config                    #
####################################
set(CMAKE_SYSTEM_NAME Generic)  # Represents the target/host OS
#NOTE: For embedded devices, a common convention is to use generic

set(CMAKE_SYSTEM_PROCESSOR arm) # Represents the name of the processor type (e.g Cortex M4 => ARM,  Nvidia => RiscV)

if (NOT CPU_NAME)
    set(CPU_NAME generic)
endif ()

####################################
# Toolchain Config                 #
####################################

set(CMAKE_C_COMPILER    arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER  arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER  arm-none-eabi-gcc)
set(AS                  arm-none-eabi-as) #NOTE: The "AS" is likely referring to the assembler
set(CMAKE_AR            arm-none-eabi-gcc-ar)
set(OBJCOPY             arm-none-eabi-objcopy)
set(OBJDUMP             arm-none-eabi-objdump)
set(SIZE                arm-none-eabi-size)


# NOTE: When the value is set to ONLY, paths for the host machine will be searched
# NOTE: When the value is set to NEVER, only the build machine will be searched
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Set CMAKE to test compilation using static library compilations rather than application
# Testing an application could fail (initially) due to compiler and linker flag settings
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

####################################
# Common Flags                     #
####################################
# Note that CPU_FLAGS, LD_FLAGS, and VFP_FLAGS are set by other Toolchain files
# that include this file.
#
# See the CMake Manual for CMAKE_<LANG>_FLAGS_INIT:
#	https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_FLAGS_INIT.html

message("CPU Flags: ${CPU_FLAGS}")
message("VFP Flags: ${VFP_FLAGS}")
message("LD_Flags: ${LD_FLAGS}")

set(CMAKE_C_FLAGS_INIT
        "${CPU_FLAGS}  ${VFP_FLAGS} -Wextra -ffunction-sections -fdata-sections"
        CACHE
        INTERNAL "Default C compiler flags.")
set(CMAKE_CXX_FLAGS_INIT
        "${CPU_FLAGS}  ${VFP_FLAGS} -Wextra -ffunction-sections -fdata-sections"
        CACHE
        INTERNAL "Default C++ compiler flags.")
set(CMAKE_ASM_FLAGS_INIT
	"${CPU_FLAGS} -x assembler-with-cpp" 
	CACHE 
	INTERNAL "Default ASM compiler flags.")
set(CMAKE_EXE_LINKER_FLAGS_INIT
        "${LD_FLAGS} -Wl,--gc-sections"
        CACHE
        INTERNAL "Default linker flags.")

# Processor specific compilation flags config
set(CPU_COMPILATION FLAG
        BOOL
        OFF
        CACHE
        INTERNAL "Adds processor-specific compilation flags")

# Floating point-compilation flags config
set(FLOATING_POINT_COMPILATION FLAG
        BOOL
        OFF
        CACHE
        INTERNAL "Adds floating_point compilation flags")