cmake_minimum_required(VERSION 3.10)
project(CustomDB)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/db)

file(GLOB SOURCES 
    ${PROJECT_SOURCE_DIR}/*.cpp 
    ${PROJECT_SOURCE_DIR}/db/*.cpp
)

add_executable(customdb ${SOURCES})
