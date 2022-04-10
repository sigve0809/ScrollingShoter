//
// Created by Sigve Langva on 4/5/2022.
//

#ifndef PG4400_V22_KNR1033_HANDLEEVENTS_H
#define PG4400_V22_KNR1033_HANDLEEVENTS_H
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include <memory>

class HandleEvents {
public:
    //HandleEvents();

    void input(Player *player);
    void collision(std::vector<Enemy*> *e, std::vector<Laser*> *l, Player *player, Boss *boss);

    void finished(std::vector<GameObject*> *array);
    bool shooting() const{return isShooting;}
    bool running() const{return isRunning;}
    int getKillCount(){return killCount;}
    int getKills(){return kills;}

private:
    bool isRunning = true;
    bool isShooting = false;
    int killCount = 0;
    int kills = 0;
};


#endif //PG4400_V22_KNR1033_HANDLEEVENTS_H
