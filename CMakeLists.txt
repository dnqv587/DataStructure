cmake_minimum_required(VERSION 3.0)
project(DataStructure)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

include_directories(src)

add_subdirectory(src)