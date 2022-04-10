//
// Created by Sigve Langva on 3/30/2022.
//

#include "Player.h"
Player::Player(const char *texturesheet, int i, int i1, SDL_Renderer *renderer, bool b) : GameObject(texturesheet, i, i1, renderer, b) {
    setWidthHeight(13, 60);
    srcRect.x = 30;
    srcRect.y = 0;
}



void Player::Update() {

    srcRect.h = 76;
    srcRect.w = 150/5;
    if (counter <= 0){
        if (srcRect.x == 90) up =false;
        else if(srcRect.x == 30) up = true;
        if (up) srcRect.x += 30;
        else srcRect.x -= 30;
        counter = 10;
    }

    //std::cout << xpos << std::endl;

    destRect.x = xpos;
    destRect.y = ypos;

    destRect.w = getWidth()*2;
    destRect.h = getHeight()*2;
    //GameObject::Update();
    xpos += xVel*2;
    ypos += yVel*2;
    if(ypos < 5) setYpos(5);
    if(ypos > 542) setYpos(542);
    if (xpos < -65) setXpos(805);
    if (xpos > 810) setXpos(-60);
    counter--;



}

void Player::Render(SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}