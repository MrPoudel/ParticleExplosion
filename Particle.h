#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace    caveofprogramming {

  struct Particle {
    double    m_x;
    double    m_y;

public:
    Particle();
    virtual ~Particle();
  };

} /* namespace caveofprogramming */

#endif /* PARTICLE_H_ */