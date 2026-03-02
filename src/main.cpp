#include "SDL3/SDL.h"
#include "SDL3/SDL_video.h"

int main() {
  if (not SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
    SDL_Log("Initialization failed!");
    return 1;
  }
  SDL_Log("Initialization successful");
  SDL_Window* window =
      SDL_CreateWindow("Just another platformer", 1280, 720,
                       SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE);

  SDL_Delay(5000);

  SDL_Quit();
}
