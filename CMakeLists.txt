cmake_minimum_required(VERSION 3.17)
project(Algorithm_Solution_Collection)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-DLOCAL)

include_directories(.)

add_executable(Algorithm_Solution_Collection test.cpp)
