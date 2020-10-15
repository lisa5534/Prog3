

file (GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
#file (GLOB_RECURSE INCLUDE_FILES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

set (EXCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Repository/MongoDB")
foreach (DIRECTORY ${SOURCE_FILES})
    string (FIND ${DIRECTORY} ${EXCLUDE_DIR} EXCLUDE_DIR_FOUND)
    if (NOT ${EXCLUDE_DIR_FOUND} EQUAL -1)
        list (REMOVE_ITEM SOURCE_FILES ${DIRECTORY})
        #message("excluded source file: ${DIRECTORY}")
    endif ()
endforeach(DIRECTORY)

cmake_print_variables(SOURCE_FILES)
#cmake_print_variables(INCLUDE_FILES)

add_executable(Service ${SOURCE_FILES})
target_include_directories(Service PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_options(Service PRIVATE -Wall -Wextra -Wconversion -Wsign-conversion -Wno-missing-field-initializers -Wno-unused-parameter)