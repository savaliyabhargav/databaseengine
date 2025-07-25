cmake_minimum_required(VERSION 3.10)
project(custom_db_engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall")

add_executable(db_server src/main.cpp)
