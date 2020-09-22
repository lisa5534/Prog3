cmake_minimum_required(VERSION 3.16.0)
project(Prog3 VERSION 1.0 LANGUAGES CXX)

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
include(CMakePrintHelpers)

# find boost
# add subdir external

# also link boost here
# also link external libs here
add_subdirectory(src)


# include(CTest)
# enable_testing()

#set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#include(CPack)
