cmake_minimum_required(VERSION 3.10.2)
project(LibTest)
#stb_library
include_directories(${CMAKE_SOURCE_DIR}/library/stbLib)
#opengl
include_directories(${CMAKE_SOURCE_DIR}/library/glfw-3.2.1.bin.WIN32/include)
link_directories(${CMAKE_SOURCE_DIR}/library/glfw-3.2.1.bin.WIN32/lib-vc2012)

add_subdirectory(test1)