//
// Created by Sigve Langva on 4/5/2022.
//

#include <functional>
#include "Manager.h"
#include "Background.h"
#include "Explotion.h"
#include "Sound.h"


Manager::Manager(SDL_Renderer *renderer) : renderer(renderer) {

    shootCount = 0;
    addGameObject<Background>("../Assets/Background.png", 0, -600, renderer, true);
    addGameObject<Background>("../Assets/Background.png", 0, 0, renderer, true);
    addGameObject<Player>("../Assets/player2.png", 350,  500, renderer, false);
    addGameObject<Boss>("../Assets/boss.png", 250, -30, 0, 1, 10, renderer, false);
    addGameObject<Text>(renderer, std::to_string(kills));
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
        enemyTimer = maxTimer;
        if (maxTimer >= 200)maxTimer -= 10;
        else maxTimer = 200;
    }
    std::string sFile = "../Assets/LaserSound.mp3";

    enemyTimer--;

    std::cout << "done" << std::endl;

    for(auto e: enemies){
        std::cout << "2\n";
        if (e->isActive() && e->gunReady()) {
            std::shared_ptr<Sound> sound = std::make_shared<Sound>(sFile);
            sound->play();
            addGameObject<Laser>("../Assets/Laser.png", e->getX() + e->getWidth()*2-2, e->getY()+3, true, renderer, false);
        }
    }
    if (boss->isActive() && boss->gunReady()) {
        std::cout << "3\n";
        std::shared_ptr<Sound> sound = std::make_shared<Sound>(sFile);
        sound->play();
        addGameObject<Laser>("../Assets/Laser.png", boss->getX() + boss->getWidth(), boss->getY()+boss->getHeight()*2-70, true, renderer, false);
        addGameObject<Laser>("../Assets/Laser.png", boss->getX() + boss->getWidth()-50, boss->getY()+boss->getHeight()*2-100, true, renderer, false);
        addGameObject<Laser>("../Assets/Laser.png", boss->getX() + boss->getWidth()+50, boss->getY()+boss->getHeight()*2-100, true, renderer, false);
    }

    deleteNotActive();
    std::cout << "5\n";

    eH->input(&player);
    std::cout << "6\n";

    eH->collision(&enemies, &lasers, &player, &boss);
    std::cout << "7\n";
    checkForDeath();
    eH->finished(&elements);
    if (eH->shooting() && shootCount <= 0 &&player->isActive()){
        std::cout << "8\n";
        std::shared_ptr<Sound> sound = std::make_shared<Sound>(sFile);
        sound->play();
        sounds.emplace_back(sound);
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
    if (eH->getKillCount() >= 5) {
        std::cout << "10\n";
        addGameObject<Boss>("../Assets/boss.png", 250, -30, 0, 1, 10, renderer, false);
    }
    if (eH->getKills() > kills){
        kills++;
        text->setNotActive();
        addGameObject<Text>(renderer, std::to_string(kills));
    }
    shootCount--;
    for (auto it = elements.begin();it !=elements.end();++it){
        if (it.operator*()->isActive()){
            std::cout << "1\n";
            it.operator*()->Update();
        }
    }
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
std::shared_ptr<T> Manager::addGameObject(TArgs &&... args) {
    std::shared_ptr<T> l = std::make_shared<T>(std::forward<TArgs>(args)...);
    if (std::is_same<T, Boss>::value) boss = std::dynamic_pointer_cast<Boss>(l);
    else if (std::is_same<T, Enemy>::value) enemies.emplace_back(std::dynamic_pointer_cast<Enemy>(l));
    else if (std::is_same<T, Laser>::value) lasers.emplace_back(std::dynamic_pointer_cast<Laser>(l));
    else if (std::is_same<T, Player>::value) player = std::dynamic_pointer_cast<Player>(l);
    else if (std::is_same<T, Text>::value) text = std::dynamic_pointer_cast<Text>(l);
    elements.emplace_back(l);
    return std::dynamic_pointer_cast<T>(l);
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
    elements.erase(
            std::remove_if(elements.begin(), elements.end(), [](auto & o){
                return !o->isActive();}),
            elements.end());

}

void Manager::deleteAll(){
    std::for_each(elements.begin(), elements.end(), [](std::shared_ptr<GameObject> &ob) { if (ob->isActive()) ob->setNotActive(); });
    elements.clear();
    enemies.clear();
    lasers.clear();
    std::cout <<"all deleted\n";
}
void Manager::checkForDeath(){
    std::for_each(enemies.begin(), enemies.end(), [this](std::shared_ptr<Enemy> &ob) {
        if (!ob->isActive()){
            addGameObject<Explotion>("../Assets/exploSprite.png", ob->getX(), ob->getY(), renderer, false);
        }
    });
    if (player->getExplotion()) {
        addGameObject<Explotion>("../Assets/exploSprite.png", player->getX(), player->getY(), renderer, false);
        player->setExplotion();
    }
    if (boss->getExplotion()) {
        std::shared_ptr<Explotion> g = addGameObject<Explotion>("../Assets/exploSprite.png", boss->getX(), boss->getY(), renderer, false);
        g->setWidthHeight(boss->getWidth(), boss->getHeight());
        boss->setExplotion();
    }


}
