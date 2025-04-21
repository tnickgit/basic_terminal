cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED on)

project(Project2)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(Project2 src/main.cpp src/mypipe.cpp src/utility.cpp src/terminal.cpp)