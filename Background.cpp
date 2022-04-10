//
// Created by Sigve Langva on 4/6/2022.
//

#include "Background.h"

Background::Background(const char *texturesheet, int x, int y, SDL_Renderer *renderer, bool b) :
        GameObject(texturesheet, x, y,renderer, b) {
    setWidthHeight(400, 300);
    xVel = 0;
    yVel = 2;
}
