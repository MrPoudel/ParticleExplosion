cmake_minimum_required(VERSION 3.7)

project(SDL2Test)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

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

# add uncrustify to the build system
add_subdirectory(extern/uncrustify)
# enable testing and add googletest as a submodule
enable_testing()
add_subdirectory(googletest)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_subdirectory(Libraries)

add_executable(SDL2Test main.cpp)
target_link_libraries(SDL2Test Particle ${SDL2_LIBRARIES})
# This doesn't work, the order of dependencies matters.
#target_link_libraries(SDL2Test screen ${SDL2_LIBRARIES})

# add test subdirectory
add_subdirectory(test)

