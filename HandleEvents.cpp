//
// Created by Sigve Langva on 4/5/2022.
//

#include "HandleEvents.h"
//HandleEvents::HandleEvents() {}

void HandleEvents::input(Player *player) {
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
// Sjekk om det var en key-event
        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym) {
                case SDLK_SPACE:

                    isShooting = true;
                    break;
                case SDLK_s:
                    player->yVel = 1;
                    break;
                case SDLK_w:
                    player->yVel = -1;
                    break;
                case SDLK_d:
                    player->xVel = 1;
                    break;
                case SDLK_a:
                    player->xVel = -1;
                    break;
                case SDLK_ESCAPE:
                    isRunning = false;
                    break;
            }
        }
        if (event.type == SDL_KEYUP)
        {
// Sjekk om brukeren trykket Escape

            switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    isShooting = false;
                    break;
                case SDLK_s:
                    if (player->yVel == 1) player->yVel = 0;
                    break;
                case SDLK_w:
                    if (player->yVel == -1) player->yVel = 0;
                    break;
                case SDLK_d:
                    if (player->xVel == 1)player->xVel = 0;
                    break;
                case SDLK_a:
                    if (player->xVel == -1) player->xVel = 0;
                    break;
            }
        }

// Sjekk om brukeren trykket krysset (X) i vindu
        else if (event.type == SDL_QUIT)
        {
            isRunning = false; // avslutt
        }
    }

}

void HandleEvents::collision(std::vector<Enemy*> *e, std::vector<Laser*> *l, Player *player, Boss *boss) {
    if(killCount >=1) killCount = 0;
    for(Laser *laser: *l){
        if (laser->isActive() && !laser->isEnemy()){
            for (Enemy *enemy : *e) {
                if(enemy->isActive() && enemy->hit(laser->getX(), laser->getY())){
                    laser->setNotActive();
                    enemy->setNotActive();
                    ++killCount;
                    ++kills;
                }
            }
            if (boss->isActive()&&boss->hit(laser->getX(), laser->getY())) {
                laser->setNotActive();
            }
        }
        else if (laser->isActive() && laser->isEnemy()){
            if (player->isActive() && player->hit(laser->getX(), laser->getY())) {
                player->setNotActive();
                laser->setNotActive();
            }
        }
    }
}

void HandleEvents::finished(std::vector<GameObject*> *array) {

    for(auto it = array->begin();it !=array->end();++it) {
        if(!it.operator*()->isBackground() && it.operator*()->isActive()&&it.operator*()->getY() >= 650) {
            it.operator*()->setNotActive();
        }
        else if (!it.operator*()->isBackground() && it.operator*()->isActive() && it.operator*()->getY() <= -150) it.operator*()->setNotActive();
    }
}









