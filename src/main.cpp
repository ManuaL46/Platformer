#include "init.hpp"

#define SDL_MAIN_USE_CALLBACKS 1
#include "SDL3/SDL_main.h"

SDL_AppResult SDL_AppInit(void** appstate, int argc, char** argv) {
  *appstate = new ApplicationManager();
  return static_cast<ApplicationManager*>(*appstate)->AppInit();
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
  return static_cast<ApplicationManager*>(appstate)->AppEvents(event);
}

SDL_AppResult SDL_AppIterate(void* appstate) {
  return static_cast<ApplicationManager*>(appstate)->AppIterate();
}

void SDL_AppQuit(void* appstate, SDL_AppResult result) {
  delete static_cast<ApplicationManager*>(appstate);
  result = ApplicationManager::AppQuit();
}
