#include <iostream>

#include "Screen.h"
#include  <math.h>
#include  <stdlib.h>

//#include <gtest/gtest.h> # Already included in gmock but not vice-versa
#include <gmock/gmock.h>

using std::cout;
using std::endl;

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

struct TestScreen : public :: testing::Test {
    virtual void SetUp() override {
    
        }

    virtual void TearDown() override {
    
        }
};

struct ISDLFunctions {
    virtual SDL_Window* SDL_CreateWindow(const char* title, \
                             int         x,             \
                             int         y, \
                             int         w,\
                             int         h,\
                             Uint32      flags) = 0;
    virtual ~ISDLFunctions(){}
};

class MockSDLFunctions : ISDLFunctions {
public:
    MockSDLFunctions(){}
    MOCK_METHOD6(SDL_CreateWindow, 
                SDL_Window*(const char* title, 
                int x, 
                int y, 
                int w, 
                int h,
                Uint32 flags));
    virtual ~MockSDLFunctions(){} 
};

MockSDLFunctions msdlf;

SDL_Window* SDL_CreateWindow(const char* title, \
                             int         x,             \
                             int         y, \
                             int         w,\
                             int         h,\
                             Uint32      flags) {
                                
    return msdlf.SDL_CreateWindow(title, x, y, w, h, flags);

}

TEST_F(TestScreen, createScreen){

   
    caveofprogramming::Screen s; 
    
    EXPECT_CALL(msdlf, SDL_CreateWindow(_,
                                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 400, 400, SDL_WINDOW_SHOWN))
                                .Times(AtLeast(1))
                                .WillOnce(Return(static_cast<SDL_Window*>(NULL)));
    s.init();

    //using testing::Mock::AllowLeak(msdlf);
    //testing::Mock::VerifyAndClearExpectations(msdlf);
    //EXPECT_FALSE(s.init(); );   
    //Mock::AllowLeak(&fooMock);  
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

