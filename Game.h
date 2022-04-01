//
// Created by Sigve Langva on 3/30/2022.
//

#ifndef PG4400_V22_KNR1033_GAME_H
#define PG4400_V22_KNR1033_GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <memory>
//#include "TextureManager.h"
//#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
//#include "Laser.h"
#include <vector>

class Game {
public:
    Game();
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);

    void handleEvents();
    void update();
    void render();
    void clean();
    void addEnemy(int i);
    bool running(){
        return isRunning;
    }



    static SDL_Renderer *renderer;

private:
    bool isRunning;
    SDL_Window *window;
    void shooting();
    bool isShooting = false;

    void eShooting(Enemy *e);
};


#endif //PG4400_V22_KNR1033_GAME_H
