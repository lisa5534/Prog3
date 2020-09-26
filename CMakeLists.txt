cmake_minimum_required(VERSION 3.16.0)
project(Prog3 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
include(CMakePrintHelpers)

find_package(Boost 1.52 COMPONENTS system thread REQUIRED)

add_subdirectory(extern/crowcpp)
add_subdirectory(extern/rapidjson)

add_subdirectory(src)

target_link_libraries(Application crow rapidjson)
