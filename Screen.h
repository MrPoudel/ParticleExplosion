#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace caveofprogramming
{

class    Screen
{
  const static int    SCREEN_WIDTH  = 800;
  const static int    SCREEN_HEIGHT = 800;
private:
  SDL_Window*     m_window;
  SDL_Renderer*   m_renderer;
  SDL_Texture*    m_texture;
  Uint32*         m_buffer;

public:
  Screen();
  bool init();
  bool processEvents();
  void close();

  virtual ~Screen();
};

} /* namespace caveofprogramming */

#endif /* SCREEN_H_ */