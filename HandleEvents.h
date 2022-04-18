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
    void input(std::shared_ptr<Player> *player, const std::shared_ptr<RestartButton>& restartButton);
    void collision(std::vector<std::shared_ptr<Enemy>> *e, std::vector<std::shared_ptr<Laser>> *l, std::shared_ptr<Player> *player, std::shared_ptr<Boss> *boss, std::shared_ptr<RestartButton> restartButton);

    static void finished(std::vector<std::shared_ptr<GameObject>> *array);
    [[nodiscard]] bool shooting() const{return isShooting;}
    [[nodiscard]] bool running() const{return isRunning;}
    [[nodiscard]] int getKillCount() const{return killCount;}
    [[nodiscard]] int getKills() const{return kills;}
    void restart();


private:
    bool isRunning = true;
    bool isShooting = false;
    int killCount = 0;
    int kills = 0;

};


#endif //PG4400_V22_KNR1033_HANDLEEVENTS_H
