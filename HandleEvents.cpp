//
// Created by Sigve Langva on 4/5/2022.
//

#include "HandleEvents.h"
//HandleEvents::HandleEvents() {}

void HandleEvents::input(std::shared_ptr<Player> *player) {
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
                    player->operator*().yVel = 1;
                    break;
                case SDLK_w:
                    player->operator*().yVel = -1;
                    break;
                case SDLK_d:
                    player->operator*().xVel = 1;
                    break;
                case SDLK_a:
                    player->operator*().xVel = -1;
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
                    if (player->operator*().yVel == 1) player->operator*().yVel = 0;
                    break;
                case SDLK_w:
                    if (player->operator*().yVel == -1) player->operator*().yVel = 0;
                    break;
                case SDLK_d:
                    if (player->operator*().xVel == 1)player->operator*().xVel = 0;
                    break;
                case SDLK_a:
                    if (player->operator*().xVel == -1) player->operator*().xVel = 0;
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

void HandleEvents::collision(std::vector<std::shared_ptr<Enemy>> *e, std::vector<std::shared_ptr<Laser>> *l, std::shared_ptr<Player> *player, std::shared_ptr<Boss> *boss) {
    if(killCount >=1) killCount = 0;
    for(auto laser: *l){
        if (laser->isActive() && !laser->isEnemy()){
            for (auto enemy : *e) {
                if(enemy->isActive() && enemy->hit(laser->getX(), laser->getY())){
                    laser->setNotActive();
                    enemy->setNotActive();
                    ++killCount;
                    ++kills;
                }
            }
            if (boss->operator*().isActive()&&boss->operator*().hit(laser->getX(), laser->getY())) {
                laser->setNotActive();
                if (boss->operator*().getHealth() <= 0){
                    boss->operator*().setNotActive();
                    boss->operator*().setExplotion();
                    ++kills;
                }
            }
        }
        else if (laser->isActive() && laser->isEnemy()){
            if (player->operator*().isActive() && player->operator*().hit(laser->getX(), laser->getY())) {
                player->operator*().setNotActive();
                player->operator*().setExplotion();
                laser->setNotActive();
            }
        }
    }
}

void HandleEvents::finished(std::vector<std::shared_ptr<GameObject>> *array) {

    for(auto it = array->begin();it !=array->end();++it) {
        if(!it.operator*()->isBackground() && it.operator*()->isActive()&&it.operator*()->getY() >= 650) {
            it.operator*()->setNotActive();
        }
        else if (!it.operator*()->isBackground() && it.operator*()->isActive() && it.operator*()->getY() <= -150) it.operator*()->setNotActive();
    }
}









