cmake_minimum_required(VERSION 3.10)
project(CustomDB)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

file(GLOB SOURCES src/*.cpp src/db/*.cpp)

add_executable(customdb ${SOURCES})


