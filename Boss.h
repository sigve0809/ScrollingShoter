//
// Created by Sigve Langva on 4/6/2022.
//

#ifndef PG4400_V22_KNR1033_BOSS_H
#define PG4400_V22_KNR1033_BOSS_H


#include "Enemy.h"


class Boss : public Enemy{

public:
    void init(int x, int y);
    Boss(const char *texturesheet, int x, int y, int patternX, int patternY, int maxY, SDL_Renderer *renderer, bool b);
    bool hit(int x, int y)override;
    void Update()override;
    void Render(SDL_Renderer *renderer)override;
    void setIsActive(){
        active = true;
    }
    [[nodiscard]] int getHealth() const{
        return health;
    }

private:
    int health = 10;
    bool changed = false;
};


#endif //PG4400_V22_KNR1033_BOSS_H
