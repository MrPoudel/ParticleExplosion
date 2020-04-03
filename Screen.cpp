#include "Screen.h"

namespace    caveofprogramming
{

  Screen::Screen() :
    m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL)
  {

  }

  bool Screen::init()
  {
    /* Initialize the SDL */
    if ((SDL_INIT_VIDEO) < 0)
    {
      // cout << "SDL init failed." << endl;
      return false;
    }

    m_window = SDL_CreateWindow("Particle file explosion",
                                SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (m_window == NULL)
    {
      SDL_Quit();
      return false;
    }
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    m_texture  = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

    if (m_renderer == NULL)
    {
      // cout << "Couldn not create renderer" << endl;
      SDL_DestroyWindow(m_window);
      SDL_Quit();
      return false;
    }

    if (m_texture == NULL)
    {
      // cout << "Couldn not create texturer" << endl;
      SDL_DestroyRenderer(m_renderer);
      SDL_DestroyWindow(m_window);
      SDL_Quit();
      return false;
    }

    m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

    memset(m_buffer, 0x0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

    return true;
  }

  void Screen::update()
  {
    SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
  }

  void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
  {
    if (x < 0 || (x >= SCREEN_WIDTH) || y < 0 || (y >= SCREEN_HEIGHT))
    {
      return;
    }
    Uint32    color = 0;
    // 0xFF123456

    color  += red;
    color <<= 8;
    color  += green;
    color <<= 8;
    color  += blue;
    color <<= 8;
    color  += 0xff;

    // cout << setfill('0') << setw(8) << hex << color << endl;
    m_buffer[(y * SCREEN_WIDTH) + x] = color;

  }

  bool Screen::processEvents()
  {
    SDL_Event    event;
    bool         result = true;

    while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
      {
        result = false;
      }
    }

    return result;
  }

  void Screen::clear(){
    memset(m_buffer, 0, SCREEN_HEIGHT * SCREEN_HEIGHT * sizeof(Uint32));
  }

  void Screen::close()
  {
    delete[] m_buffer;

    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyTexture(m_texture);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
  }

  Screen::~Screen()
  {
  }

} /* namespace caveofprogramming */