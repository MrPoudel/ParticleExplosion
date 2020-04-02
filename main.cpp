#include <iostream>
#include <iomanip>
#include <SDL.h>
#include <math.h>
#include "Screen.h"

using namespace    std;
using namespace    caveofprogramming;

int main()
{
  Screen    screen;
  int       elapsed;

  if (screen.init() == false)
  {
    cout << "Error initializing SDL." << endl;
  }

  // int max = 0;

  while (true)
  {
    // Update particles
    // Draw particles

    elapsed = SDL_GetTicks();
    unsigned char    red   = (1 + sin(elapsed * 0.001)) * 128;
    unsigned char    green = (1 + sin(elapsed * 0.002)) * 128;
    unsigned char    blue  = (1 + sin(elapsed * 0.003)) * 128;

    // if(green > max)
    // max = green;

    for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
    {
      for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
      {
        screen.setPixel(x, y, red, green, blue); // RED+BLUE = YELLOW.
      }
    }

    // Draw the screen
    screen.update();

    if (screen.processEvents() == false)
    {
      break;
    }
  }

  screen.close();
// cout << max << endl;

  return 0;
} // main
