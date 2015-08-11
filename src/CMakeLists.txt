include_directories (../include/)
include_directories (/usr/local/include/)
find_library (fftwlibs NAMES fftw3 fftw libfftw3)
set (fftw_lib "${fftwlibs}")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

#set (cmake_exe_linker_flags "-lfftw3 -lm")
cmake_minimum_required (VERSION 2.6)

file (GLOB sources "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
add_definitions (-std=c++11)

add_executable (run ${sources})
target_link_libraries (run ${fftw_lib})
