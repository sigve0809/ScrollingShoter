//
// Created by Sigve Langva on 4/6/2022.
//

#include "Boss.h"

Boss::Boss(const char *texturesheet, int x, int y, int patternX, int patternY, int maxY, SDL_Renderer *renderer, bool b)
        : Enemy(texturesheet, x, y, patternX, patternY, maxY, renderer, b) {
    init(250, -149);
    setWidthHeight(80, 80);
    shootCool = 100;

}

void Boss::Update() {
    Enemy::Update();
    if (ypos >= a->getMaxY() && !changed) {
        a->giveYval(0);
        a->giveXval(1);
        changed = true;
    }
}

void Boss::Render(SDL_Renderer *renderer) {
    SDL_RenderCopyEx(renderer, objTexture, NULL, &destRect, 0.0, NULL, SDL_FLIP_VERTICAL);


}

bool Boss::hit(int x, int y) {

    if(x > xpos && x< xpos+(getWidth()*2) && y > ypos && y< ypos+(getHeight())) {
        health--;
        return true;
    }
    return false;
}

void Boss::init(int x, int y) {
    setXpos(x);
    setYpos(y);
    a->giveXval(0);
    a->giveYval(1);
    setIsActive();
}
