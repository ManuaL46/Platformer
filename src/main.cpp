#include "SDL3/SDL_init.h"
#include "SDL3/SDL_log.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_timer.h"
#include "SDL3/SDL_video.h"
#define SDL_MAIN_USE_CALLBACKS 1

#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"

static SDL_Window* app_window = nullptr;
static SDL_Renderer* app_renderer = nullptr;
static int width = 1280;
static int height = 720;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char** argv) {
  if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Initialization Failed!");
    return SDL_APP_FAILURE;
  }
  SDL_CreateWindowAndRenderer("Just another Platformer ", width, height,
                              SDL_WINDOW_VULKAN, &app_window, &app_renderer);
  if (!app_renderer || !app_window) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "Failed to create app window/renderer!");
    return SDL_APP_FAILURE;
  }

  bool status = SDL_SetRenderLogicalPresentation(
      app_renderer, width, height, SDL_LOGICAL_PRESENTATION_INTEGER_SCALE);
  if (!status) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "Failed to render logical presentation!");
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
    return SDL_APP_FAILURE;
  }

  SDL_RenderPresent(app_renderer);

  SDL_Delay(5000);

  return SDL_APP_SUCCESS;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
  return SDL_APP_CONTINUE;
}
SDL_AppResult SDL_AppIterate(void* appstate) { return SDL_APP_CONTINUE; }

void SDL_AppQuit(void* appstate, SDL_AppResult result) { SDL_Quit(); }
