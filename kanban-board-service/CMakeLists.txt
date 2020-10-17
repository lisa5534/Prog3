cmake_minimum_required(VERSION 3.16.0)
project(Prog3 VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
include(CMakePrintHelpers)

# this will adapt cmake search path for libs and includes
# set(CMAKE_PREFIX_PATH "C:\\sqlite3")
# this adapts the library file suffixes, by default cmake does not recognize .dll on windows
# set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib" ".dll" ".a")

set(Boost_USE_STATIC_LIBS "On")

# in case we cannot find package this is helpful to debug cmake search
#set(CMAKE_FIND_DEBUG_MODE 1)

find_package(SQLite3 REQUIRED)
find_package(Boost 1.55 COMPONENTS system thread REQUIRED)

add_subdirectory(extern/crowcpp)
add_subdirectory(extern/rapidjson)

add_subdirectory(src)

target_include_directories(Service PRIVATE ${SQLite3_INCLUDE_DIRS})
target_link_libraries(Service crow rapidjson ${SQLite3_LIBRARIES})

if(WIN32)
  target_compile_options(Service PRIVATE -DBOOST_ERROR_CODE_HEADER_ONLY)
endif()