#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace    caveofprogramming {

  struct Particle {
    double    m_x;
    double    m_y;

private:
    double    m_speed;
    double    m_direction;

private:
    void init();

public:
    Particle();
    void update(int interval);
    virtual ~Particle();
  };

} /* namespace caveofprogramming */

#endif /* PARTICLE_H_ */