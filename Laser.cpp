//
// Created by Sigve Langva on 3/31/2022.
//

#include "Laser.h"

Laser::Laser(const char *texturesheet, int x, int y, bool enemy, SDL_Renderer *renderer, bool b) : GameObject(texturesheet, x, y, renderer, b), enemy(enemy) { setWidthHeight(1, 10);}

void Laser::Update() {
    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = 2;
    destRect.h = 20;
    if (enemy) ypos += 5;
    else ypos-= 5;
}

void Laser::Render(SDL_Renderer *renderer) {
    GameObject::Render(renderer);
}


