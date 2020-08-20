
cmake_minimum_required (VERSION 2.6)
set(CMAKE_CXX_STANDARD 11)

include(CheckCCompilerFlag)

project(market)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

include_directories("includes")
file(GLOB SOURCES "src/*.cpp")

add_executable(market ${SOURCES})