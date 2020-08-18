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

TEST_F(ParticleTest, constructParticle){
    caveofprogramming::Particle p;   
    

    EXPECT_EQ(p.m_x, 0);
    EXPECT_EQ(p.m_y, 0);

    p.update(1000);

    EXPECT_NEAR(p.m_x, 0.189675, 0.00001);
    EXPECT_NEAR(p.m_y, -0.161105, 0.0001);
}

TEST_F(ParticleTest, Dummytest2){
    EXPECT_EQ("hello", "hello");
    EXPECT_EQ(9, 9);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

