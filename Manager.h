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
#include "Text.h"
#include "Sound.h"

class Manager {

public:
    std::shared_ptr<HandleEvents> eH = std::make_shared<HandleEvents>();
    explicit Manager(SDL_Renderer *renderer);
    void update();
    void render();
    template<typename T, typename ... TArgs>
    std::shared_ptr<T> addGameObject(TArgs&&... args);
    void deleteNotActive();
private:
    int count = 500;
    SDL_Renderer *renderer;
    int enemyTimer = 0;
    int shootCount = 0;
    std::shared_ptr<Player> player;
    std::shared_ptr<Boss> boss;
    std::vector<std::shared_ptr<GameObject>> elements;
    std::vector<std::shared_ptr<Enemy>> enemies;
    std::vector<std::shared_ptr<Laser>> lasers;
    std::vector<std::shared_ptr<Sound>> sounds;
    void deleteAll();
    std::default_random_engine generator;
    std::shared_ptr<Text> text;
    int kills = 0;
    int maxTimer = 50;

    void checkForDeath();
};


#endif //PG4400_V22_KNR1033_MANAGER_H
