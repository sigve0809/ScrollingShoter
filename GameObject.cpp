//
// Created by Sigve Langva on 3/30/2022.
//

#include "GameObject.h"

GameObject::GameObject(const char *texturesheet, int x, int y, SDL_Renderer *renderer) {
    objTexture = TextureManager::LoadTexture(texturesheet, renderer);
    xpos = x;
    ypos = y;
}

GameObject::~GameObject() {}

void GameObject::Update() {

    srcRect.h = height;
    srcRect.w = width;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;



}

void GameObject::Render(SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, objTexture, NULL, &destRect);
}

void GameObject::destroyGameObject() {
    SDL_DestroyTexture(objTexture);
}

void GameObject::setWidthHeight(int w, int h) {
    width = w;
    height = h;
}




