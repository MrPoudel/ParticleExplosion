
set(TEST_SOURCES
  Particle
  #Screen
  Swarm
)

foreach(FILE ${TEST_SOURCES})
    add_executable(Test${FILE}
        Test${FILE}.cpp
    )

    target_link_libraries(Test${FILE}
        PRIVATE
        Particle
        gtest_main
    )

    add_test(NAME Test${FILE} COMMAND Test${FILE})

endforeach()

if(CMAKE_COMPILER_IS_GNUCXX) # Because We run the tests in host machine not in the target
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
        # setup_target_for_coverage_gcovr_xml(NAME coverage
        #                                     EXECUTABLE ParticleTest
        #                                     EXCLUDE "extern/*" "test/*"
        #                                     )

        setup_target_for_coverage_gcovr_html(NAME coverage
                                            EXECUTABLE ctest -j ${n_cores}
                                            DEPENDENCIES
                                                TestParticle
                                                TestSwarm
                                            EXCLUDE "extern/*" "test/*" "Libraries/include/*"
                                            ) 
    endif()