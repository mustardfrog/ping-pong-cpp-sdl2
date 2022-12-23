#include "Game.hpp"

int main(int argc, char *argv[]) {

    Game *game = nullptr;
    game = new Game();

    const int FPS = 40;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game->init();

    while (game->running()) {
        frameStart = SDL_GetTicks64();

        game->update();
        game->handleEvent();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay);
        }

    }

    game->clean();
    return 0;
}
