cmake_minimum_required(VERSION 3.20)
project(Calculator)

set(CMAKE_CXX_STANDARD 23)

add_library(stack INTERFACE)
target_sources(stack INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Stack.h
)

target_include_directories(stack INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_subdirectory(src)
