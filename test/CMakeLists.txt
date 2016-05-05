PROJECT(MyHello)
cmake_minimum_required(VERSION 2.8)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
CONAN_BASIC_SETUP()


SET(CMAKE_CXX_FLAGS "-std=c++0x")
ADD_EXECUTABLE(example imageflow.capnp.c)
target_link_libraries(example ${CONAN_LIBS})
