//
// Created by Sigve Langva on 3/30/2022.
//

#ifndef PG4400_V22_KNR1033_GAME_H
#define PG4400_V22_KNR1033_GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <memory>
#include "Manager.h"
#include <vector>
#include <SDL_ttf.h>

class Game {
public:
    Game();
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void update();
    void render();
    void clean();
    bool running() const{
        return isRunning;
    }
    static SDL_Renderer *renderer;

private:
    bool isRunning;
    SDL_Window *window;
};


#endif //PG4400_V22_KNR1033_GAME_H
