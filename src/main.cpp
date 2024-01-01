#include <iostream>
#include <string>
#include "SDL_Headers.h"

using namespace std;

void rect(SDL_Renderer *Renderer, int x, int y, int w, int h, int R, int G, int B, int fill_boolian);
void help(SDL_Renderer *Renderer, double x_ball, double y_ball, int dx, bool clicked);
int main(int argc, char *argv[])
{

  // Initialization of SDL windows
  Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER;
  Uint32 WND_flags = SDL_WINDOW_SHOWN; //| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;

  SDL_Window *m_window;
  SDL_Renderer *m_renderer;
  // Texture for loading image

  SDL_Init(SDL_flags);

  SDL_CreateWindowAndRenderer(1200, 700, WND_flags, &m_window, &m_renderer);
  // Pass the focus to the drawing window
  SDL_RaiseWindow(m_window);
  // Get screen resolution
  SDL_DisplayMode DM;
  SDL_GetCurrentDisplayMode(0, &DM);
  // Clear the window with a black background
  // SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
  SDL_RenderClear(m_renderer);

  // Show the window
  SDL_RenderPresent(m_renderer);
  SDL_Event *e = new SDL_Event();

  bool clicked = false;
  int x = 200, dx = 10;
  double zarib = 1, acceleration = 3, velocity = -200, y, y0 = 500, t, rx = 55;

  while (true)
  {
    while (!clicked)
    {
      rect(m_renderer, 0, 0, 1200, 540, 53, 81, 92, 1);
      help(m_renderer, x, y0, dx, clicked);
      filledEllipseRGBA(m_renderer, x, y0, 40, 40, 100, 200, 0, 127);
      rect(m_renderer, 0, 540, 1200, 160, 255, 255, 0, 1);
      SDL_RenderPresent(m_renderer);
      SDL_Delay(25);
      SDL_RenderClear(m_renderer);
      SDL_PollEvent(e);
      if (e->type == SDL_KEYDOWN)
      {
        switch (e->key.keysym.sym)
        {
        case SDLK_w:
          if (y0 > 40)
          {
            y0 -= 5;
            rect(m_renderer, 0, 0, 1200, 540, 53, 81, 92, 1);
            help(m_renderer, x, y0, dx, clicked);
            filledEllipseRGBA(m_renderer, x, y0, 40, 40, 100, 200, 0, 127);
            rect(m_renderer, 0, 540, 1200, 160, 255, 255, 0, 1);
            SDL_RenderPresent(m_renderer);
            SDL_Delay(25);
            SDL_RenderClear(m_renderer);
          }
          break;

        case SDLK_s:
          if (y0 < 500)
          {
            y0 += 5;
            rect(m_renderer, 0, 0, 1200, 540, 53, 81, 92, 1);
            help(m_renderer, x, y0, dx, clicked);
            filledEllipseRGBA(m_renderer, x, y0, 40, 40, 100, 200, 0, 127);
            rect(m_renderer, 0, 540, 1200, 160, 255, 255, 0, 1);
            SDL_RenderPresent(m_renderer);
            SDL_Delay(25);
            SDL_RenderClear(m_renderer);
          }
          break;

        case SDLK_d:
          if (x < 1160)
          {
            x += 5;
            rect(m_renderer, 0, 0, 1200, 540, 53, 81, 92, 1);
            help(m_renderer, x, y0, dx, clicked);
            filledEllipseRGBA(m_renderer, x, y0, 40, 40, 100, 200, 0, 127);
            rect(m_renderer, 0, 540, 1200, 160, 255, 255, 0, 1);
            SDL_RenderPresent(m_renderer);
            SDL_Delay(25);
            SDL_RenderClear(m_renderer);
          }
          break;

        case SDLK_a:
          if (x > 40)
          {
            x -= 5;
            rect(m_renderer, 0, 0, 1200, 540, 53, 81, 92, 1);
            help(m_renderer, x, y0, dx, clicked);
            filledEllipseRGBA(m_renderer, x, y0, 40, 40, 100, 200, 0, 127);
            rect(m_renderer, 0, 540, 1200, 160, 255, 255, 0, 1);
            SDL_RenderPresent(m_renderer);
            SDL_Delay(25);
            SDL_RenderClear(m_renderer);
          }
          break;

        case SDLK_p:
          clicked = true;
          break;

        case SDLK_e:
          if (dx < 35)
          {
            dx += 1;
          }
          break;

        case SDLK_q:
          if (dx > 0.5)
          {
            dx -= 1;
          }
          break;
        }
      }
    }

    if (clicked)
    {
      for (t = 0; t < 25 && zarib >= 0.05; t += 0.1)
      {
        y = (0.5 * acceleration * t * t + velocity * t) * zarib + y0;
        velocity += acceleration * t;

        rect(m_renderer, 0, 0, 1200, 540, 53, 81, 92, 1);
        filledEllipseRGBA(m_renderer, x, y, 40, 40, 100, 200, 0, 127);
        rect(m_renderer, 0, 540, 1200, 160, 255, 255, 0, 1);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(25);
        SDL_RenderClear(m_renderer);

        if (x < 40 || x > 1160)
          dx = -dx;
        x += dx;
        if (y > 500)
        {
          rect(m_renderer, 0, 0, 1200, 540, 53, 81, 92, 1);
          filledEllipseRGBA(m_renderer, x, y, rx, 40, 100, 200, 0, 127);
          rect(m_renderer, 0, 540, 1200, 160, 255, 255, 0, 1);
          SDL_RenderPresent(m_renderer);
          SDL_Delay(25);
          zarib *= 0.8;
          t = 0;
          velocity = -200;
          y0 = 500;
          acceleration = 3;
          rx -= 1;
        }
      }
      // new
      clicked = false;
      rx = 55;
      zarib = 1;
      t = 0;
      acceleration = 3;
      velocity = -200;
      if (dx < 0)
      {
        dx = -dx;
      }
    }
  }

  SDL_DestroyWindow(m_window);
  SDL_DestroyRenderer(m_renderer);
  IMG_Quit();
  SDL_Quit();
  return 0;
}
void rect(SDL_Renderer *Renderer, int x, int y, int w, int h, int R, int G, int B, int fill_boolian)
{

  SDL_Rect rectangle;
  rectangle.x = x;
  rectangle.y = y;
  rectangle.w = w;
  rectangle.h = h;

  SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
  SDL_RenderFillRect(Renderer, &rectangle);
  SDL_RenderDrawRect(Renderer, &rectangle);
  // SDL_RenderPresent(Renderer);
}
void help(SDL_Renderer *Renderer, double x_ball, double y_ball, int dx, bool clicked)
{
  int y_help = 0, y0 = y_ball, x_help = x_ball;
  double velocity = -200;
  if (!clicked)
  {
    for (double time = 0; time < 3.8; time += 0.1)
    {
      y_help = (0.5 * 3 * time * time + velocity * time) + y0;
      velocity += 3 * time;
      filledEllipseRGBA(Renderer, x_help, y_help, 1, 1, 255, 255, 0, 255);
      x_help += dx;
    }
  }
}
