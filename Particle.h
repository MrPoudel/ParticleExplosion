#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace    caveofprogramming {

  struct Particle {
    double    m_x;
    double    m_y;

    double m_speed;
    double m_direction;

    // double m_xspeed;
    // double m_yspeed;

public:
    Particle();
    void update();
    virtual ~Particle();
  };

} /* namespace caveofprogramming */

#endif /* PARTICLE_H_ */