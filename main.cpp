#include <iostream>
#include <iomanip>
#include <SDL.h>
#include "Screen.h"

using namespace    std;
using namespace    caveofprogramming;

int main()
{
  Screen    screen;

  if (screen.init() == false)
  {
    cout << "Error initializing SDL." << endl;
  }

  while (true)
  {
    // Draw particles
    for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
    {
      for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
      {
        screen.setPixel(x, y, 255, 255, 0); // RED+BLUE = YELLOW.
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

  return 0;
} // main
