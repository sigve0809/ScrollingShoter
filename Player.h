//
// Created by Sigve Langva on 3/30/2022.
//

#ifndef PG4400_V22_KNR1033_PLAYER_H
#define PG4400_V22_KNR1033_PLAYER_H


#include "GameObject.h"
#include "Laser.h"

class Player : public GameObject{
public:
    Player(const char *texturesheet, int i, int i1, SDL_Renderer *renderer, bool b);


    bool hit(int x, int y){
        if(x > xpos && x< xpos+(getWidth()*2) && y > ypos && y< ypos+(getHeight())) {
            std::cout << "In\n";
            alive = false;
            return true;
        }
        return false;
    }
    void Update() override;
    void Render(SDL_Renderer *renderer) override;

private:
    bool alive = true;
    bool up = true;
    int counter = 10;
};


#endif //PG4400_V22_KNR1033_PLAYER_H
