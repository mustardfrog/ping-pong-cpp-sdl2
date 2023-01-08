#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_keycode.h>
#include <cstdio>

class Game {
  public:
    static SDL_Renderer *renderer;

    Game();
    ~Game();

    void init();
    void handleEvent();
    void update();
    void render();
    void clean();
    bool running() { return isRunning; };

  private:
    bool isRunning = false;
    SDL_Window *window;
};
