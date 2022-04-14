//
// Created by Sigve Langva on 4/11/2022.
//

#include "Text.h"


Text::Text(SDL_Renderer *renderer, std::string string, int x, int y, int width, int height) : GameObject(renderer) {
    setWidthHeight(width, height);
    xpos = x;
    ypos = y;
    renderer1 = renderer;
    TTF_Font *font = TTF_OpenFont("../Assets/8bitOperatorPlus8-Regular.ttf", 32);
    SDL_Surface * surfaceText = TTF_RenderText_Solid(font, string.c_str(), {255, 255, 255});
    objTexture = SDL_CreateTextureFromSurface(renderer1, surfaceText);
    SDL_FreeSurface(surfaceText);
}
