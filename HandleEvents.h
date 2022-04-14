//
// Created by Sigve Langva on 4/5/2022.
//

#ifndef PG4400_V22_KNR1033_HANDLEEVENTS_H
#define PG4400_V22_KNR1033_HANDLEEVENTS_H
#include "Player.h"
#include "Enemy.h"
#include "Boss.h"
#include "RestartButton.h"

#include <memory>

class HandleEvents {
public:
    //HandleEvents();

    void input(std::shared_ptr<Player> *player, std::shared_ptr<RestartButton> restartButton);
    void collision(std::vector<std::shared_ptr<Enemy>> *e, std::vector<std::shared_ptr<Laser>> *l, std::shared_ptr<Player> *player, std::shared_ptr<Boss> *boss, std::shared_ptr<RestartButton> restartButton);

    void finished(std::vector<std::shared_ptr<GameObject>> *array);
    bool shooting() const{return isShooting;}
    bool running() const{return isRunning;}
    int getKillCount() const{return killCount;}
    int getKills() const{return kills;}

private:
    bool isRunning = true;
    bool isShooting = false;
    int killCount = 0;
    int kills = 0;
};


#endif //PG4400_V22_KNR1033_HANDLEEVENTS_H
