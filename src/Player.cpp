#include "Player.hpp"
#include "Ball.hpp"
#include "Game.hpp"
#include <cstdio>

const float delta = 0.2;

Player::Player(int x, int y, int w, int h) {
    player.x = x;
    player.y = y;
    player.w = w;
    player.h = h;

    playerSpeed = 200;
};

Player::~Player(){};

void Player::checkCollisionWithBorder() {
    if (player.x <= 0)
        player.y = 0;
    if (player.h >= 600)
        player.y = 400;
}

void Player::handleEvents(SDL_Event event, SDL_KeyCode a, SDL_KeyCode b) {
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == a)
            player.y -= playerSpeed * delta;
        if (event.key.keysym.sym == b)
            player.y += playerSpeed * delta;
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
    }
}

void Player::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 10);
    SDL_RenderDrawRect(renderer, &player);

    SDL_RenderFillRect(renderer, &player);
}
