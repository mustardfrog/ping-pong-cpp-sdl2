#include "Ball.hpp"
#include "Game.hpp"

const int initialxPos = 400;
const int initialyPos = 300;

static int aCount = 0;
static int bCount = 0;

const float delta = 0.8;

Ball::Ball() {

    ball.h = 32;
    ball.w = 32;
    ball.x = 132;
    ball.y = 132;

    ballSpeed.x = 10;
    ballSpeed.y = 10;
};

Ball::~Ball(){};

void Ball::update() {
    ball.x += ballSpeed.x * delta;
    ball.y += ballSpeed.y * delta;

    if (ball.x + 32 >= WIDTH || ball.x <= 0)
        ballSpeed.x *= -1;
    if (ball.y + 32 >= 600 || ball.y <= 0)
        ballSpeed.y *= -1;

    if (ball.x + 32 >= WIDTH) {
        ball.x = initialxPos;
        ball.y = initialyPos;
        aCount++;
    }
    if (ball.x <= 0) {
        ball.x = initialxPos;
        ball.y = initialyPos;
        bCount++;
    }
}

void Ball::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 10);
    SDL_RenderDrawRect(renderer, &ball);

    SDL_RenderFillRect(renderer, &ball);
}
