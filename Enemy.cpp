//
// Created by Sigve Langva on 3/31/2022.
//

#include "Enemy.h"

Enemy::Enemy(const char *texturesheet, int x, int y, int patternX, int patternY, int maxY, SDL_Renderer *renderer, bool b) :
GameObject(texturesheet, x, y, renderer, b), pX(patternX), pY(patternY), mY(maxY){getDirection();}

void Enemy::Update() {
    GameObject::Update();
    xpos += xVel;
    ypos += yVel;
    if (xpos <= 0 || xpos >= 800 - getWidth()*2) {
        a->setX();
    }

    yVel = a->getY();
    xVel = a->getX();
    if (shootCool <= 1) canShoot = true;
    else canShoot = false;
    shootCool--;
    if (shootCool <= 0) shootCool = 75;

}

void Enemy::getDirection() {
    auto test = std::make_shared<Direction>(pX, pY, mY);
    a = test;
}

void Enemy::Render(SDL_Renderer *renderer) {
    SDL_RenderCopyEx(renderer, objTexture, nullptr, &destRect, 0.0, nullptr, SDL_FLIP_VERTICAL);

}



