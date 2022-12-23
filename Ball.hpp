#pragma once
#include <SDL2/SDL.h>
#include "Types.hpp"

class Ball { 
    private:
        // typedef struct Vector2
        // {
        //     int x;
        //     int y;
        // } Vector2;

    public:
        Ball();
        ~Ball();

        SDL_Rect ball;

        Vector2 ballSpeed;

        void update();
        void render(SDL_Renderer* renderer);
};
