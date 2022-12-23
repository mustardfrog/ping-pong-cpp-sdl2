#include "Player.hpp"
#include "Game.hpp"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <cstdio>

Player::Player(){};
Player::~Player(){};
void Player::init(int x, int y , int w, int h){
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

void Player::update() {

}

void Player::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 10);
    SDL_RenderDrawRect(renderer, &player);

    SDL_RenderFillRect(renderer, &player);
}
