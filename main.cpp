#include <iostream>
#include "Game.h"
#include <SDL.h>
Game *game = nullptr;
int main(int argc, char *argv[]) {
    const int FPS = 100;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    unsigned int frameTime;

    game = new Game();
    game->init("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while (game->running()){
        frameStart = SDL_GetTicks();
        game->update();
        Game::render();
        frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
    }
    game->clean();
    return 0;
}
