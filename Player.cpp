//
// Created by Sigve Langva on 3/30/2022.
//

#include "Player.h"
Player::Player(const char *string, int i, int i1, SDL_Renderer *renderer) : GameObject(string, i, i1, renderer) {}


Laser* Player::shoot(SDL_Renderer *renderer) {
    if (cannon == 1) {
        cannon = 2;
        return new Laser("../Assets/Laser.png", xpos+2, ypos+3, false, renderer);
    }
    cannon = 1;
    return new Laser("../Assets/Laser.png", xpos + getWidth()*2-2, ypos+3, false, renderer);
}

void Player::Update() {
    GameObject::Update();
    xpos += xVel*2;
    ypos += yVel*2;
    if(ypos < 5) setYpos(5);
    if(ypos > 542) setYpos(542);
    if (xpos < -65) setXpos(805);
    if (xpos > 810) setXpos(-60);
}

void Player::Render(SDL_Renderer *renderer) {
    GameObject::Render(renderer);
}

