
include(FetchContent)
include(CTest)

#####################################################
# TODO: Acquire testing Frameworks from git
#####################################################


######################################################
# TODO: Ensure frameworks are available via fetchcontent_makeavailable() command
# see here for more details:
#   https://cmake.org/cmake/help/latest/module/FetchContent.html#command:fetchcontent_makeavailable
######################################################
FetchContent_MakeAvailable(cmocka-test-framework)
FetchContent_MakeAvailable(unity_framework)

#####################################################
# Add libraries for test frameworks
#####################################################
# NOTE: The cmocka package already has a predefined library target
# so there is no need to create a new library


###########################################################
# Create test helper library                             #
# NOTE: Functions are defined in individual test modules #
# So this library is marked as interface instead of a    #
# typical static library                                 #
###########################################################
add_library(test_helpers INTERFACE)
target_include_directories(test_helpers PUBLIC INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

###########################################################
# Example test runner                                     #
###########################################################
add_executable(example_test_runner)
target_sources(example_test_runner
        PRIVATE
        example_test_runner.c)
target_link_libraries(example_test_runner PRIVATE cmocka)

# NOTE: Example unit tests
add_test(NAME example_tests COMMAND example_test_runner)

###########################################################
# Add test subdirectories                                 #
# NOTE: CTest test cases and executables are defined in   #
# each modules CMakeLists.txt file respectively           #
###########################################################
add_subdirectory(GPIO)
add_subdirectory(LedDriver)



