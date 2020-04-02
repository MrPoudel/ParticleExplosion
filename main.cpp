#include <iostream>
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
    if (screen.processEvents() == false)
    {
      break;
    }
  }

  screen.close();

  return 0;
} // main
