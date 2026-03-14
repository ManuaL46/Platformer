
#include "init.hpp"

#include "SDL3/SDL_init.h"
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_messagebox.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"

ApplicationManager::ApplicationManager() {}

ApplicationManager::~ApplicationManager() {
  if (m_init && m_app_renderer && m_app_window) {
    SDL_DestroyRenderer(m_app_renderer);
    SDL_DestroyWindow(m_app_window);
  }
}

SDL_AppResult ApplicationManager::AppInit() {
  if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error",
                             "Initialization Failed!", nullptr);
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Initialization Failed!");
    return SDL_APP_FAILURE;
  }
  SDL_CreateWindowAndRenderer("Just another Platformer ", m_width, m_height,
                              SDL_WINDOW_VULKAN, &m_app_window,
                              &m_app_renderer);
  if (!m_app_renderer || !m_app_window) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "Failed to create app window/renderer!");
    return SDL_APP_FAILURE;
  }

  bool status =
      SDL_SetRenderLogicalPresentation(m_app_renderer, m_width, m_height,
                                       SDL_LOGICAL_PRESENTATION_INTEGER_SCALE);
  if (!status) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "Failed to render logical presentation!");
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  SDL_RenderPresent(m_app_renderer);
  SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING |
                               SDL_MESSAGEBOX_BUTTONS_LEFT_TO_RIGHT |
                               SDL_MESSAGEBOX_COLOR_BACKGROUND,
                           "Platformer", "Hello World!", m_app_window);

  m_init = true;
  return SDL_APP_CONTINUE;
}

SDL_AppResult ApplicationManager::AppIterate() const {
  if (!m_init) return SDL_APP_FAILURE;
  return SDL_APP_CONTINUE;
}

SDL_AppResult ApplicationManager::AppEvents(SDL_Event* event) const {
  if (!m_init) return SDL_APP_FAILURE;
  if (event->type == SDL_EVENT_QUIT) return SDL_APP_SUCCESS;
  return SDL_APP_CONTINUE;
}

SDL_AppResult ApplicationManager::AppQuit() {
  SDL_Quit();
  return SDL_APP_SUCCESS;
}
