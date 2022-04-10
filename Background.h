//
// Created by Sigve Langva on 4/6/2022.
//

#ifndef PG4400_V22_KNR1033_BACKGROUND_H
#define PG4400_V22_KNR1033_BACKGROUND_H


#include "GameObject.h"

class Background : public GameObject {
public:
    Background(const char *texturesheet, int x, int y, SDL_Renderer *renderer, bool b);
    void Update()override{
        GameObject::Update();
        ypos+=yVel;
        if (getY() >= 600) setYpos(-600);
    }

};


#endif //PG4400_V22_KNR1033_BACKGROUND_H
