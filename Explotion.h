//
// Created by Sigve Langva on 4/12/2022.
//

#ifndef PG4400_V22_KNR1033_EXPLOTION_H
#define PG4400_V22_KNR1033_EXPLOTION_H


#include "GameObject.h"

class Explotion : public GameObject{
public:
    Explotion(const char *texturesheet, int x, int y, SDL_Renderer *renderer, bool b);

    void Update() override;
    void Render(SDL_Renderer *renderer) override;

private:
    int counter = 2;
    int counter1 = 0;
    int counter2 = 0;
};


#endif //PG4400_V22_KNR1033_EXPLOTION_H
