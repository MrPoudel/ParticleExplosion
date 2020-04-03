add_library(ParticleHeaders INTERFACE)

# target_include_directories(ParticleHeaders
#    INTERFACE
#    ${PROJECT_BINARY_DIR}
# )

# target_include_directories(ParticleHeaders
#     INTERFACE
#     ${CMAKE_CURRENT_LIST_DIR}
# )

add_library(Particle ${EMPTY_SOURCE})
target_link_libraries(Particle
    PUBLIC
    ParticleHeaders   
)

add_subdirectory(include)
add_subdirectory(src)