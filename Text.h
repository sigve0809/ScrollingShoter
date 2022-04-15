//
// Created by Sigve Langva on 4/11/2022.
//

#ifndef PG4400_V22_KNR1033_TEXT_H
#define PG4400_V22_KNR1033_TEXT_H


#include "GameObject.h"
#include <SDL_ttf.h>

class Text : public GameObject{
public:
    Text(SDL_Renderer *renderer, std::string string, int x, int y, int width, int height);
    void Update() override{
        GameObject::Update();

    }
    void Render(SDL_Renderer *renderer) override{
        SDL_RenderCopy(renderer, objTexture, NULL, &destRect);
    }
    int getX(){
        return xpos;
    }
    int getY(){
        return ypos;
    }
    int width(){return getWidth();}
    int height(){return getHeight();}


private:
    SDL_Renderer *renderer1;
};


#endif //PG4400_V22_KNR1033_TEXT_H
