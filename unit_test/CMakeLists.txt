include_directories (../include/)
include_directories (/usr/local/include/)
include_directories (${gtest_SOURCE_DIR}/include/)
find_library (fftwlibs NAMES fftw3 fftw libfftw3)
set (fftw_lib "${fftwlibs}")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
set (src ${PROJECT_SOURCE_DIR}/src/)

cmake_minimum_required (VERSION 2.6)

file (GLOB tests "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
message (tests)
file (GLOB srcs "${PROJECT_SOURCE_DIR}/src/*.cpp")

list (REMOVE_ITEM srcs "${PROJECT_SOURCE_DIR}/src/run_man.cpp")

add_definitions (-std=c++11)

add_executable (test ${tests} ${srcs})
target_link_libraries (test ${fftw_lib} gtest_main)
