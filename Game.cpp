//
// Created by Sigve Langva on 3/30/2022.
//

#include "Game.h"
Manager *manager = nullptr;
int count = 1000;

Game::Game() {};

Game::~Game() {};

SDL_Renderer *Game::renderer = nullptr;

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) flags = SDL_WINDOW_FULLSCREEN;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "subsystem initialised" << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window){
            std::cout << "window created" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            std::cout << "renderer created" << std::endl;
        }
        SDL_Init(SDL_INIT_VIDEO);
        if (TTF_Init() < 0) std::cout << "ERROR: " << TTF_GetError() << std::endl;

        isRunning = true;
    }
    manager = new Manager(renderer);


}

void Game::handleEvents() {


}

void Game::update() {
    isRunning = manager->eH->running();
    manager->update();
}

void Game::render() {
    manager->render();
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned" << std::endl;
}





