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
#include <SDL_mixer.h>

class Game {
public:


    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void update();
    static void render();
    void clean();
    [[nodiscard]] bool running() const{
        return isRunning;
    }
    static SDL_Renderer *renderer;

private:
    bool isRunning;
    SDL_Window *window;
};


#endif //PG4400_V22_KNR1033_GAME_H
