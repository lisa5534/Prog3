cmake_minimum_required(VERSION 3.16.0)
project(Prog3 VERSION 1.0 LANGUAGES CXX)

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
include(CMakePrintHelpers)

find_package(Boost 1.70 COMPONENTS system thread REQUIRED)

add_subdirectory(extern/crowcpp)
add_subdirectory(extern/rapidjson)

add_subdirectory(src)

target_link_libraries(Application crow rapidjson)
