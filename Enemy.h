//
// Created by Sigve Langva on 3/31/2022.
//

#ifndef PG4400_V22_KNR1033_ENEMY_H
#define PG4400_V22_KNR1033_ENEMY_H

#include <iostream>
#include "GameObject.h"
#include "Laser.h"
#include "Direction.h"
#include <vector>
#include <memory>
class Enemy : public GameObject{
public:
    //std::vector<std::shared_ptr<Direction>> patternVector;


    Enemy(const char *texturesheet, int x, int y, int patternX, int patternY, int maxY, SDL_Renderer *renderer);

    Laser *shoot(SDL_Renderer *renderer);

    bool isAlive(){return alive;}
    void Update() override;
    void Render(SDL_Renderer *renderer) override;
    bool hit(int x, int y){
        if(x > xpos && x< xpos+(getWidth()*2) && y > ypos && y< ypos+(getHeight()*2)) {
            std::cout << "In\n";
            alive = false;
            return true;
        }
        return false;
    }
    bool gunReady(){
        return canShoot;
    }
    void collide();
    void getDirection();
private:
    std::shared_ptr<Direction> a;
    int shootCool = 10;
    bool canShoot = true;
    bool alive = true;
    int pY;
    int pX;
    int mY;

};


#endif //PG4400_V22_KNR1033_ENEMY_H
