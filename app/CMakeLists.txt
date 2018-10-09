cmake_minimum_required(VERSION 2.8.12)
# Every project needs a name.  We call this the "examples" project.
project(cc_demo)

add_subdirectory(detector detector_build)

aux_source_directory(. srcs)
include_directories(detector/header/)
set(EXECUTABLE_OUTPUT_PATH ../bin/)

add_executable(cc_demo ${srcs})
# add_dependencies(cc_demo detector)
# link_directories(lib/)
target_link_libraries(cc_demo ccdtora)

# find_library(LIBDLIB_PATH dlib lib/)
# IF(NOT LIBDLIB_PATH)
# MESSAGE(FATAL_ERROR "libdlib not found")
# ENDIF(NOT LIBDLIB_PATH)
# MESSAGE(STATUS ${LIBDLIB_PATH} " found")

# find_library(LIBCCDETECTOR_PATH ccdtora lib/)
# IF(NOT LIBCCDETECTOR_PATH)
# MESSAGE(FATAL_ERROR "libccdtora not found")
# ENDIF(NOT LIBCCDETECTOR_PATH)
# MESSAGE(STATUS ${LIBCCDETECTOR_PATH} " found")
# target_link_libraries(cc_demo ${LIBCCDETECTOR_PATH})
