#include <iostream>

#include "Swarm.h"
#include  <math.h>
#include  <stdlib.h>

#include <gtest/gtest.h>

struct TestSwarm : public :: testing::Test {
    virtual void SetUp() override {
    
        }

    virtual void TearDown() override {
    
        }
};

TEST_F(TestSwarm, constructParticle){
    caveofprogramming::Swarm swm; 
    swm.update(1000);  
   // nothing to test
}

TEST_F(TestSwarm, Dummytest2){
    EXPECT_EQ("hello", "hello");
    EXPECT_EQ(9, 9);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

