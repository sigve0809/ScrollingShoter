//
// Created by Sigve Langva on 4/5/2022.
//

#include <functional>
#include "Manager.h"
#include "Background.h"


Manager::Manager(SDL_Renderer *renderer) : renderer(renderer) {

    shootCount = 0;
    addGameObject<Background>("../Assets/Background.png", 0, -600, renderer, true);
    addGameObject<Background>("../Assets/Background.png", 0, 0, renderer, true);
    addGameObject<Player>("../Assets/player2.png", 350,  500, renderer, false);
    addGameObject<Boss>("../Assets/boss.png", 250, -30, 0, 1, 10, renderer, false);
    boss->setNotActive();
    boss->setWidthHeight(80, 80);
}

void Manager::update() {
    if (enemyTimer <= 0){
        std::cout << "4\n";

        std::uniform_int_distribution<int> distribution(0,800-64);
        std::uniform_int_distribution<int> distribution2(-1,1);
        int rand1 = distribution(generator);
        int rand2 = distribution2(generator);
        if (!boss->isActive())addGameObject<Enemy>("../Assets/spaceship1.png", rand1, -32, rand2, 1, 400, renderer, false);
        enemyTimer = 500;
    }
    enemyTimer--;
    for (auto it = elements.begin();it !=elements.end();++it){
        if (it.operator*()->isActive()){
            std::cout << "1\n";
            it.operator*()->Update();
        }
    }
    std::cout << "done" << std::endl;

    for(Enemy *e: enemies){
        std::cout << "2\n";
        if (e->isActive() && e->gunReady()) addGameObject<Laser>("../Assets/Laser.png", e->getX() + e->getWidth()*2-2, e->getY()+3, true, renderer, false);
    }
    if (boss->isActive() && boss->gunReady()) {
        std::cout << "3\n";
        addGameObject<Laser>("../Assets/Laser.png", boss->getX() + boss->getWidth(), boss->getY()+boss->getHeight()*2-70, true, renderer, false);
        addGameObject<Laser>("../Assets/Laser.png", boss->getX() + boss->getWidth()-50, boss->getY()+boss->getHeight()*2-100, true, renderer, false);
        addGameObject<Laser>("../Assets/Laser.png", boss->getX() + boss->getWidth()+50, boss->getY()+boss->getHeight()*2-100, true, renderer, false);
    }

    deleteNotActive();
    std::cout << "5\n";

    eH->input(player);
    std::cout << "6\n";

    eH->collision(&enemies, &lasers, player, boss);
    std::cout << "7\n";

    eH->finished(&elements);
    if (eH->shooting() && shootCount <= 0 &&player->isActive()){
        std::cout << "8\n";
        if (count == 1){
            addGameObject<Laser>("../Assets/Laser.png", player->getX() + player->getWidth()*2-2, player->getY()+3, false, renderer, false);
            count = 2;
        }
        else{
            addGameObject<Laser>("../Assets/Laser.png", player->getX() + 2, player->getY()+3, false, renderer, false);
            count = 1;
        }
        shootCount = 30;
    }
    if (eH->getKillCount() >= 1) {
        std::cout << "10\n";
        addGameObject<Boss>("../Assets/boss.png", 250, -30, 0, 1, 10, renderer, false);
    }
    shootCount--;
    if (!eH->running()) deleteAll();
}
void Manager::render() {
    SDL_RenderClear(renderer);

    for (auto it = elements.begin();it !=elements.end();++it){
        if (it.operator*()->isActive()) it.operator*()->Render(renderer);
    }
    SDL_RenderPresent(renderer);
}

template<class T, class... TArgs>
void Manager::addGameObject(TArgs &&... args) {
    auto *l = new T(std::forward<TArgs>(args)...);

    if (std::is_same<T, Boss>::value){
        std::cout <<"ADDED BOSS\n";
        boss = reinterpret_cast<Boss*>(l);
        boss->init(250, -149);
        boss->setWidthHeight(80, 80);
    }
    else if (std::is_same<T, Enemy>::value) {

        Enemy *enemy = reinterpret_cast<Enemy*>(l);
        std::cout <<"ADDED Enemy\n";

        //enemy->getDirection();
        elements.emplace_back(enemy);
        enemies.template emplace_back(enemy);
        return;
    }
    else if (std::is_same<T, Laser>::value) {
        Laser *laser = reinterpret_cast<Laser*>(l);
        laser->setWidthHeight(1, 10);
        elements.emplace_back(laser);
        lasers.template emplace_back(laser);
        return;
    }
    else if (std::is_same<T, Player>::value) player = reinterpret_cast<Player*>(l);


    elements.emplace_back(reinterpret_cast<T*>(l));

}

void Manager::deleteNotActive() {

    enemies.erase(
            std::remove_if(enemies.begin(), enemies.end(), [](auto & o){
                return !o->isActive();}),
            enemies.end());
    lasers.erase(
            std::remove_if(lasers.begin(), lasers.end(), [](auto & o){
                return !o->isActive();}),
            lasers.end());
    for(auto it = elements.begin();it !=elements.end();++it){
        if (!it.operator*()->isActive()){
            it.operator*()->setCanFree();

        }
    }
    elements.erase(
            std::remove_if(elements.begin(), elements.end(), [](auto & o){
                return !o->isActive();}),
            elements.end());

}
void Manager::deleteAll(){
    elements.clear();
    for(Enemy *e: enemies){
        if (e->isActive()) e->setNotActive();
    }
    for(Laser *l: lasers) {
        if(l->isActive())l->setNotActive();
    }
    if (!player->isActive()) player->setNotActive();
    if (!boss->isActive()) boss->setNotActive();

    std::cout <<"all deleted\n";
    enemies.clear();
    lasers.clear();
}



