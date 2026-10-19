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

add_executable(rpn_calc src/rpn_calc.cpp)

target_link_libraries(rpn_calc PRIVATE stack)