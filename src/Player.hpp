#pragma once
#include <SDL2/SDL_render.h>

#include "Ball.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Types.hpp"

class Player {

    public:
        Player(int x, int y, int w, int h);
        ~Player();
        SDL_Rect player;
        int playerSpeed;

        void update();

        void render(SDL_Renderer *renderer);
        void handleEvents(SDL_Scancode a, SDL_Scancode b);

        void checkCollisionWithBall(Player *player, Ball *ball);
        void checkCollisionWithBorder();
};
