//
// Created by Sigve Langva on 3/30/2022.
//

#ifndef PG4400_V22_KNR1033_TEXTUREMANAGER_H
#define PG4400_V22_KNR1033_TEXTUREMANAGER_H
#include <SDL.h>
#include <SDL_image.h>
class TextureManager {
public:
    static SDL_Texture *LoadTexture(const char *texture, SDL_Renderer *renderer);
    static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest, SDL_Renderer *renderer);
};



#endif //PG4400_V22_KNR1033_TEXTUREMANAGER_H
