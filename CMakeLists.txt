cmake_minimum_required(VERSION 3.16)

project(SDL2Test)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/uncrustify/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

set(GCC_COVERAGE_COMPILE_FLAGS "-g -O0 -coverage -fprofile-arcs -ftest-coverage")
set(GCC_COVERAGE_LINK_FLAGS    "-coverage -lgcov")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

# Release MinSizeRel
set(CMAKE_BUILD_TYPE Debug)

# Disable in-source builds to prevent source tree corruption.
#if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
#  message(FATAL_ERROR "
#FATAL: In-source builds are not allowed.
#       You should create a separate directory for build files.
#")
#endif()

# add uncrustify to the build system
###add_subdirectory(extern/uncrustify)
# enable testing and add googletest as a submodule
enable_testing()
add_subdirectory(extern/googletest)

#find_package(Threads REQUIRED) #${CMAKE_THREAD_LIBS_INIT}
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_subdirectory(Libraries)

add_executable(SDL2Test main.cpp)
target_link_libraries(SDL2Test Particle ${SDL2_LIBRARIES} Logger)
# The order of dependencies matters.

# add test subdirectory
add_subdirectory(test)
