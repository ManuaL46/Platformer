#ifndef APPMGR_H
#define APPMGR_H

#pragma once

#include <SDL3/SDL_init.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

struct ApplicationManager {
 public:
  ApplicationManager();
  ApplicationManager(ApplicationManager&&) = delete;
  ApplicationManager& operator=(ApplicationManager&&) = delete;
  ~ApplicationManager();
  ApplicationManager(const ApplicationManager&) = delete;
  ApplicationManager& operator=(const ApplicationManager&) = delete;

  SDL_AppResult AppInit();
  [[nodiscard]] SDL_AppResult AppIterate() const;
  [[nodiscard]] SDL_AppResult AppEvents(SDL_Event* event) const;
  void CleanUp();
  static SDL_AppResult AppQuit();

 private:
  SDL_Window* m_app_window;
  SDL_Renderer* m_app_renderer;
  int m_width;
  int m_height;
};

#endif
