PROJECT(c-capnproto)
cmake_minimum_required(VERSION 2.8)
include(${CMAKE_CURRENT_SOURCE_DIR}/conanbuildinfo.cmake)
CONAN_BASIC_SETUP()



add_library(c_capnproto ../lib/capn-malloc.c ../lib/capn-stream.c ../lib/capn.c)
IF(UNIX AND FPIC)
  SET_TARGET_PROPERTIES(c_capnproto PROPERTIES COMPILE_FLAGS "-fPIC")
ENDIF()

target_link_libraries(c_capnproto ${CONAN_LIBS})