//
// Created by Sigve Langva on 4/11/2022.
//

#ifndef PG4400_V22_KNR1033_TEXT_H
#define PG4400_V22_KNR1033_TEXT_H


#include "GameObject.h"
#include <SDL_ttf.h>

class Text : public GameObject{
public:
    Text(SDL_Renderer *renderer, std::string string);
    void Update() override{

    }
    void Render(SDL_Renderer *renderer) override{
        GameObject::Update();
        SDL_RenderCopy(renderer, objTexture, NULL, &destRect);
    }

private:
    SDL_Renderer *renderer1;
};


#endif //PG4400_V22_KNR1033_TEXT_H
