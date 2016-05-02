cmake_minimum_required(VERSION 3.3)
project(2016)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        1B/1gettingthedigits/gettingthedigits.cpp
        template.h)
add_executable(2016 ${SOURCE_FILES})