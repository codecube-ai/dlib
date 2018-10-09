cmake_minimum_required(VERSION 2.8.12)
# Every project needs a name.  We call this the "examples" project.
project(cc_detector)

add_subdirectory(../../dlib dlib_build)

aux_source_directory(src/ srcs)
include_directories(header/)
set(LIBRARY_OUTPUT_PATH ../../lib/)

add_library(ccdtora STATIC ${srcs})
target_link_libraries(ccdtora dlib::dlib)
