target_sources(ParticleHeaders
    INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}/Particle.h
    ${CMAKE_CURRENT_LIST_DIR}/Screen.h
    ${CMAKE_CURRENT_LIST_DIR}/Swarm.h
)

target_include_directories(ParticleHeaders
    INTERFACE
    ${CMAKE_CURRENT_LIST_DIR}
)