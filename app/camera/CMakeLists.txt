cmake_minimum_required(VERSION 2.8.12)
# Every project needs a name.
project(cc_camera)

add_custom_target(build_parmetis ALL
        COMMAND ${CMAKE_MAKE_PROGRAM}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Call makefile to build libcamera.a")
