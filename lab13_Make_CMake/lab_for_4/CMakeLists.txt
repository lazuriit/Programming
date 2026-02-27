cmake_minimum_required(VERSION 3.10)

project(PC_GAMES)

set(LIB_SELECT "STATIC" CACHE STRING "STATIC or SHARED") 

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCES ${SRC_DIR}/pcgames.c)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(PCGAMES_LIB ${LIB_SELECT} ${SOURCES}) 
add_executable(static_exe ${SRC_DIR}/main.c)
target_link_libraries(static_exe PCGAMES_LIB)
