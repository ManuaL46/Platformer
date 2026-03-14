#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

struct ApplicationManager {
 public:
  ApplicationManager();
  ~ApplicationManager();

  SDL_AppResult AppInit();
  SDL_AppResult AppIterate() const;
  SDL_AppResult AppEvents(SDL_Event* event) const;
  static SDL_AppResult AppQuit();

 private:
  SDL_Window* m_app_window = nullptr;
  SDL_Renderer* m_app_renderer = nullptr;
  int m_width = 1280;
  int m_height = 720;
  bool m_init = false;
};
