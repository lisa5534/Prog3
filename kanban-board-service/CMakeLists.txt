cmake_minimum_required(VERSION 3.16.0)
project(Prog3 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
include(CMakePrintHelpers)

INCLUDE_DIRECTORIES(
  C:/vcpkg/installed/x86-windows/include
)
LINK_DIRECTORIES(
  C:/vcpkg/installed/x86-windows/lib
)

set(Boost_USE_STATIC_LIBS "On")
find_package( Boost 1.52 COMPONENTS system thread regex REQUIRED )

find_package(SQLite3 REQUIRED)

add_subdirectory(extern/crowcpp)
add_subdirectory(extern/rapidjson)

add_subdirectory(src)

target_include_directories(Service PRIVATE ${SQLite3_INCLUDE_DIRS})
target_link_libraries(Service crow rapidjson ${SQLite3_LIBRARIES})
