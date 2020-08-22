
project(Logger C CXX)

add_library(Logger INTERFACE)

target_sources(Logger INTERFACE ${CMAKE_CURRENT_LIST_DIR}/Logger.h)

target_include_directories(Logger INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)

# Enable by default all the logging levels
target_compile_definitions(Logger INTERFACE -DLOGGING_LEVEL_ALL)  # -D removed
target_compile_features(Logger INTERFACE cxx_std_11)