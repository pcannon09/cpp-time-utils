cmake_minimum_required(VERSION 3.18)

file(READ ".private/project.json" projectInfo)

#Set priority variables
string(JSON projectVersion GET "${projectInfo}" version)
string(JSON projectVersionState GET "${projectInfo}" versionState)
string(JSON projectName GET "${projectInfo}" CMakeName)

set(VERSION "${projectVersion} ${projectVersionState}")

project(${projectName}
    VERSION ${projectVersion}
)

# Flags
set(programFlags            "-g -fsanitize=address -Wunused -Wall -Wno-range-loop-analysis")
set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} ${programFlags}")
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${programFlags}")

# Warn about the current CXX compiling using for compilation
message(STATUS "CXX Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "{${projectName}} version: ${projectVersion}")

# Setup
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)

# Dir setup
set(srcDir "${CMAKE_SOURCE_DIR}/src")
set(testDir "${CMAKE_SOURCE_DIR}/test")
set(incDir "${CMAKE_SOURCE_DIR}/inc")
set(vendorDir "${CMAKE_SOURCE_DIR}/vendor")

# Headers from the `inc/` dir
set(headers
    ${incDir}/Stopwatch.hpp
    ${incDir}/Timer.hpp
    ${incDir}/Time.hpp
    ${incDir}/macros.hpp

    ${testDir}/inc/tests.hpp
)

# Sources from the `src/` dir
set(sources
    ${testDir}/src/main.cpp
    ${testDir}/src/stopwatch.cpp
    ${testDir}/src/timer.cpp
    ${testDir}/src/time.cpp
    ${testDir}/src/sleep.cpp

    ${srcDir}/Stopwatch.cpp
    ${srcDir}/Timer.cpp
    ${srcDir}/Time.cpp
    ${srcDir}/Sleep.cpp
)

# Vendor sources from the `vendor/` dir that are used in this project
set(vendorSources
    # # IO Controller
    # ${vendorDir}/io-controller-mini/src/functions.cpp
    # ${vendorDir}/io-controller-mini/src/ioController.cpp

    # ## Conio.h
    # ${vendorDir}/io-controller-mini/vendor/conio-master/conio.c
)

# Vendor headers from the `vendor/sleepx/` dir that are used in this project
set(vendorHeaders
    # # IO Controller
    # ${vendorDir}/io-controller-mini/include/functions.hpp
    # ${vendorDir}/io-controller-mini/include/ioController.hpp
    # ${vendorDir}/io-controller-mini/include/structs.hpp

    # ## Conio.h
    # ${vendorDir}/io-controller-mini/vendor/conio-master/conio.h
)

# Link the executable
add_executable(${projectName} ${sources} ${headers} ${vendorSources} ${vendorHeaders})

