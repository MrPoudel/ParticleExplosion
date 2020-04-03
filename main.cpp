#include <iostream>
#include <iomanip>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "Screen.h"
#include "Swarm.h"

using namespace    std;
using namespace    caveofprogramming;

int main()
{
  int    color = 0x123456;

  int              red   = (color & 0xFF0000) >> 16;
  int              green = (color & 0x00FF00) >> 8;
  unsigned char    blue  = (color & 0x0000FF);

  cout << hex << (int) blue << (int) red << endl;

  srand(time(NULL));
  Screen    screen;
  int       elapsed;

  if (screen.init() == false)
  {
    cout << "Error initializing SDL." << endl;
  }

  Swarm                    swarm;
  const Particle* const    pParticles = swarm.getParticles();

  while (true)
  {
    // Update particles
    // Draw particles

    elapsed = SDL_GetTicks();
    // screen.clear();
    swarm.update(elapsed);

    unsigned char    red   = (1 + sin(elapsed * 0.001)) * 128;
    unsigned char    green = (1 + sin(elapsed * 0.002)) * 128;
    unsigned char    blue  = (1 + sin(elapsed * 0.003)) * 128;

    for (int i = 0; i < Swarm::NPARTICLES; i++)
    {
      Particle    particle = pParticles[i];

      // int    x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
      // int    y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;

      int    x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
      int    y = (particle.m_y * Screen::SCREEN_HEIGHT / 2) + Screen::SCREEN_HEIGHT / 2;

      screen.setPixel(x, y, red, green, blue);
    }

    screen.boxBlur();

    screen.update();

    if (screen.processEvents() == false)
    {
      break;
    }
  }

  screen.close();

  return 0;
} // main
