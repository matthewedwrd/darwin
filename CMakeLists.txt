cmake_minimum_required(VERSION 3.0)
project(darwin)

include_directories(include)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.c)

add_executable(darwin ${SOURCES})

target_link_libraries(darwin)