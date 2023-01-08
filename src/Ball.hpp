#pragma once
#include <SDL2/SDL.h>
#include "Types.hpp"

enum class Winner {
    A,
    B
};

class Ball { 

    public:
        Ball();
        ~Ball();

        SDL_Rect ball;

        Vector2 ballSpeed;

        void update();
        void render(SDL_Renderer* renderer);
    private:
};
