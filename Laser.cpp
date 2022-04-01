//
// Created by Sigve Langva on 3/31/2022.
//

#include "Laser.h"

Laser::Laser(const char *texturesheet, int x, int y, bool enemy, SDL_Renderer *renderer) : GameObject(texturesheet, x, y, renderer), enemy(enemy) {}

void Laser::Update() {
    GameObject::Update();
    if (enemy) ypos += 5;
    else ypos-= 5;
    if(canDel) outOfMap();
}

bool Laser::collision() {
    return canDel;
}

void Laser::outOfMap() {
    destroyGameObject();
    std::cout << "GameObject destroyed\n";
}

void Laser::Render(SDL_Renderer *renderer) {
    GameObject::Render(renderer);
}


