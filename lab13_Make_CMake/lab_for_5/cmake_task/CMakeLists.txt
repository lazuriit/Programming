cmake_minimum_required(VERSION 3.10)

project(CMAKE_TASK)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/pipes)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/background)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_subdirectory(pipes)
add_subdirectory(background)

add_executable(cmake_exe ${SRC_DIR}/main.c)

target_link_libraries(cmake_exe BACKGROUND_LIB)