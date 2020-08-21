
project(Logger C CXX)

add_library(Logger INTERFACE)
target_sources(Logger INTERFACE Logger.h)

target_include_directories(Logger INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

