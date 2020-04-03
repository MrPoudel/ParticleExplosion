#include "Particle.h"
#include <math.h>
#include <stdlib.h>

namespace    caveofprogramming {

  Particle::Particle():m_x(0), m_y(0)
  {
    m_direction = (2 * M_PI * rand())/RAND_MAX;
    m_speed = (0.001 * rand())/ RAND_MAX;

    // m_x = (2.0 * rand()) / RAND_MAX - 1;
    // m_y = (2.0 * rand()) / RAND_MAX - 1;

    // m_xspeed = 0.01 * (2.0* rand()/RAND_MAX - 1);
    // m_yspeed = 0.01 * (2.0 *rand()/RAND_MAX - 1);
  }
  void Particle::update(){   
    double xspeed = m_speed * cos(m_direction);
    double yspeed = m_speed * sin(m_direction);
    m_x += xspeed;
    m_y += yspeed;


    // m_x += m_xspeed;
    // m_y += m_yspeed;

    // if(m_x < -1.0 || m_x >= 1.0)
    // {
    //   m_xspeed *= -1;
    // }

    // if(m_y < -1.0 || m_y >= 1.0)
    // {
    //   m_yspeed *= -1;
    // }
  }

  Particle::~Particle()
  {

  }

} /* namespace caveofprogramming */