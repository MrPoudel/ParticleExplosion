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

if(CMAKE_COMPILER_IS_GNUCXX)    
    include(CodeCoverage)  
    append_coverage_compiler_flags()  
    message("Coverage is going to be generated")
    #set(COVERAGE_EXCLUDES
    #          'test/*'              
    #          'extern/*'              
    #          )
    #set(COVERAGE_LCOV_EXCLUDES 
    #"/usr/include/*" 
    #"/usr/include/c++/*"
    #"/usr/include/x86_64-linux-gnu/c++/7/bits/*"    
    #)
    # SETUP_TARGET_FOR_COVERAGE_LCOV(NAME coverage
    #                          EXECUTABLE ${TEST_EXE_NAME}
    #                          )
    setup_target_for_coverage_gcovr_xml(NAME coverage
                                        EXECUTABLE ParticleTest
                                        EXCLUDE "extern/*" "test/*"
                                        )    

    setup_target_for_coverage_gcovr_html(NAME coverage2
                                        EXECUTABLE ParticleTest
                                        EXCLUDE "extern/*" "test/*"
                                        ) 

endif()
