cmake_minimum_required(VERSION 3.7)

set(SOURCES
  ParticleTest.cpp
)

add_executable(ParticleTest ${SOURCES})
target_link_libraries(ParticleTest PUBLIC
  gtest_main
  Particle
)

add_test(
  NAME ParticleTest
  COMMAND ParticleTest
)
