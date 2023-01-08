#include "Player.hpp"
#include "Ball.hpp"
#include "Game.hpp"
#include <cstdio>

Player::Player(){};
Player::~Player(){};

void Player::init(int x, int y, int w, int h) {
    player.x = x;
    player.y = y;
    player.w = w;
    player.h = h;

    playerSpeed.x = 30;
    playerSpeed.y = 30;
};

void Player::handleEvents(SDL_Event event, SDL_KeyCode a, SDL_KeyCode b) {
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == a)
            player.y -= playerSpeed.y;
        if (event.key.keysym.sym == b)
            player.y += playerSpeed.y;
    }
}

void Player::update() {}

void Player::checkCollisionWithBall(Player *player, Ball *ball) {

    SDL_bool colliding = SDL_HasIntersection(&ball->ball, &player->player);

    if (colliding) {
        SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(Game::renderer, &player->player);
        SDL_RenderPresent(Game::renderer);
        ball->ballSpeed.x *= -1;
        // ball->ballSpeed.y  *= -1;
    }
}

void Player::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 10);
    SDL_RenderDrawRect(renderer, &player);

    SDL_RenderFillRect(renderer, &player);
}
