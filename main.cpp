#include <iostream>
#include <iomanip>
#include <SDL.h>
#include "Screen.h"

using namespace    std;
using namespace    caveofprogramming;

int main()
{

  // 0xFF123456

  unsigned char    alpha = 0xFF;
  unsigned char    red   = 0x12;
  unsigned char    green = 0x34;
  unsigned char    blue  = 0x56;

  unsigned int    color = 0;
  color  += alpha;
  color <<= 8;
  color  += red;
  color <<= 8;
  color  += green;
  color <<= 8;
  color  += blue;

  cout << setfill('0') << setw(8) << hex << color << endl;

  Screen    screen;

  if (screen.init() == false)
  {
    cout << "Error initializing SDL." << endl;
  }

  while (true)
  {
    if (screen.processEvents() == false)
    {
      break;
    }
  }

  screen.close();

  return 0;
} // main
