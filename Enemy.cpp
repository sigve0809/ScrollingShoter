//
// Created by Sigve Langva on 3/31/2022.
//

#include "Enemy.h"

Enemy::Enemy(const char *texturesheet, int x, int y, int patternX, int patternY, int maxY, SDL_Renderer *renderer) : GameObject(texturesheet, x, y, renderer), pX(patternX), pY(patternY), mY(maxY){}

void Enemy::Update() {
    GameObject::Update();
    xpos += xVel;
    ypos += yVel;
    if (ypos <= 0 || ypos >= a->getMaxY()) a->setY();
    if (xpos <= 0 || xpos >= 800 - getWidth()*2) a->setX();
    yVel = a->getY();
    xVel = a->getX();
    if (shootCool == 100) canShoot = true;
    else canShoot = false;


        shootCool--;
    if (shootCool == 0) shootCool = 100;

}

Laser *Enemy::shoot(SDL_Renderer *renderer) {
    return new Laser("../Assets/Laser.png", getX()+getWidth(), getY(), true, renderer);
}
void Enemy::collide() {
    destroyGameObject();
    alive = false;
}

void Enemy::getDirection() {
    auto test = std::make_shared<Direction>(pX, pY, mY);
    a = test;
}

void Enemy::Render(SDL_Renderer *renderer) {
    SDL_RenderCopyEx(renderer, objTexture, NULL, &destRect, 0.0, NULL, SDL_FLIP_VERTICAL);

}



