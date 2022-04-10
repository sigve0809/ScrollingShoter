//
// Created by Sigve Langva on 4/5/2022.
//

#ifndef PG4400_V22_KNR1033_MANAGER_H
#define PG4400_V22_KNR1033_MANAGER_H

#include <vector>
#include <iostream>
#include "Boss.h"
#include "Player.h"
#include "HandleEvents.h"
#include <memory>
#include <random>
#include <SDL.h>
class Manager {

public:
    HandleEvents *eH = new HandleEvents();
    explicit Manager(SDL_Renderer *renderer);
    void update();
    void render();
    template<typename T, typename ... TArgs>
    void addGameObject(TArgs&&... args);
    void deleteNotActive();
private:
    int count = 500;
    SDL_Renderer *renderer;
    int enemyTimer = 0;
    int shootCount = 0;
    Player *player;
    Boss *boss;
    std::vector<GameObject*> elements;
    std::vector<Enemy*> enemies;
    std::vector<Laser*> lasers;
    void deleteAll();
    int added = 0;
    void resetArray();
    std::default_random_engine generator;
};


#endif //PG4400_V22_KNR1033_MANAGER_H
