add_library(ParticleHeaders INTERFACE)

add_library(Particle ${EMPTY_SOURCE})
target_link_libraries(Particle
    PUBLIC
    ParticleHeaders
)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(Logger)
