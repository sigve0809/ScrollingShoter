//
// Created by Sigve Langva on 3/30/2022.
//

#include "TextureManager.h"
SDL_Texture *TextureManager::LoadTexture(const char *fileName, SDL_Renderer *renderer) {
    SDL_Surface *tempSurface = IMG_Load(fileName);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return tex;
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest, SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, tex, &src, &dest);
}