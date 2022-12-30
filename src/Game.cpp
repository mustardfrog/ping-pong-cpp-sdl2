#include "Game.hpp"
#include "Ball.hpp"
#include "Player.hpp"
#include <SDL2/SDL_keycode.h>
#include <cstdio>

Game::Game(){};

Ball *ball = new Ball();
Player *playerA = new Player();
Player *playerB = new Player();

Game::~Game(){};

SDL_Renderer *Game::renderer = nullptr;

void Game::init() {

    // if (IMG_Init(IMG_INIT_PNG) == 0) {
    //     printf("failed to initialize png");
    // };

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("cannot start sdl");
    }

    window = SDL_CreateWindow(
        "title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
        SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    if (window == NULL) {
        printf("window is null");
        isRunning = false;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (renderer) {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }

    if (renderer == NULL) {
        printf("renderer is null");
        isRunning = false;
    }
    playerA->init(32, 32, 30, 200);
    playerB->init(700, 32, 30, 200);

    isRunning = true;
}

void Game::handleEvent() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
    playerA->handleEvents(event, SDL_KeyCode::SDLK_k,SDL_KeyCode::SDLK_j ); 
    playerB->handleEvents(event, SDL_KeyCode::SDLK_UP, SDL_KeyCode::SDLK_DOWN); 

}

void Game::update() {
    ball->update();
    playerA->checkCollisionWithBall(ball);
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0,0,0, 10);
    SDL_RenderClear(renderer);
    // render shits here

    ball->render(renderer);
    playerA->render(renderer);
    playerB->render(renderer);

    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
