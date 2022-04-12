//
// Created by Sigve Langva on 4/12/2022.
//

#include "Explotion.h"

void Explotion::Update() {
    //GameObject::Update();
    srcRect.h = 744/6;
    srcRect.w = 1024/8;
    if (counter <= 0){
        if (counter1 == 8){
            counter2++;
            counter1 = 0;
        }
        if (counter2 == 9) setNotActive();
        srcRect.x = srcRect.w *counter1;
        srcRect.y = srcRect.h *counter2;
        counter = 2;
        counter1++;
    }

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = getWidth()*2;
    destRect.h = getHeight()*2;

    xpos += xVel*2;
    ypos += yVel*2;
    if(ypos < 5) setYpos(5);
    if(ypos > 542) setYpos(542);
    if (xpos < -65) setXpos(805);
    if (xpos > 810) setXpos(-60);
    counter--;
}

void Explotion::Render(SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

Explotion::Explotion(const char *texturesheet, int x, int y, SDL_Renderer *renderer, bool b) : GameObject(texturesheet, x, y, renderer, b) {}
