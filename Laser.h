//
// Created by Sigve Langva on 3/31/2022.
//

#ifndef PG4400_V22_KNR1033_LASER_H
#define PG4400_V22_KNR1033_LASER_H

#include <SDL.h>
#include "GameObject.h"
#include <iostream>
class Laser : public GameObject{


public:
    Laser(const char *texturesheet, int x, int y, bool enemy, SDL_Renderer *renderer, bool b);
    bool isEnemy(){return enemy;}
    bool collision();
    void outOfMap();
    void Update() override;
    void Render(SDL_Renderer *renderer) override;
    void canDelete(){
        canDel = true;
    }
private:
    bool enemy;
    bool canDel = false;

};


#endif //PG4400_V22_KNR1033_LASER_H
