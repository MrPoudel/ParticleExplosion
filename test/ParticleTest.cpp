#include <iostream>

#include "Particle.h"
#include  <math.h>
#include  <stdlib.h>

#include <gtest/gtest.h>

struct ParticleTest : public :: testing::Test {
    virtual void SetUp() override {
    
        }

    virtual void TearDown() override {
    
        }
};

TEST_F(ParticleTest, Dummytest){
    EXPECT_EQ("hello", "hello");
    EXPECT_EQ(7, 7);
}
