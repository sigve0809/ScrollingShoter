//
// Created by Sigve Langva on 3/30/2022.
//

#ifndef PG4400_V22_KNR1033_GAMEOBJECT_H
#define PG4400_V22_KNR1033_GAMEOBJECT_H

#include <SDL.h>
#include "TextureManager.h"
#include <iostream>
class GameObject {
public:
    explicit GameObject(SDL_Renderer *renderer);
    GameObject(const char *texturesheet, int x, int y, SDL_Renderer *renderer, bool b);

    virtual void Update();

    virtual void Render(SDL_Renderer *renderer);

    int yVel = 0;
    int xVel = 0;
    void setXpos(int pos){
        xpos = pos;
    }
    void setYpos(int pos){
        ypos = pos;
    }

    virtual int getY(){
        return ypos;
    }

    virtual int getX(){
        return xpos;
    }
    void destroyGameObject();
    void setWidthHeight(int w, int h);
    [[nodiscard]] int getWidth() const{
        return width;
    }
    [[nodiscard]] int getHeight() const{
        return height;
    }
    [[nodiscard]] bool isActive() const{
        return active;
    }

    [[nodiscard]] bool isBackground() const{return background;}
    void setNotActive(){
        destroyGameObject();
        active = false;
    }
    void setID(int x){id = x;}
    [[nodiscard]] int getID() const{return id;}
    void setExplotion(){
        if (explotionReady) explotionReady = false;
        else explotionReady = true;
    }
    [[nodiscard]] bool getExplotion() const{
        return explotionReady;
    }
private:
    int width = 32;
    int height = 32;
protected:
    bool explotionReady = false;
    SDL_Texture *objTexture;
    bool background;
    bool active = true;
    SDL_Rect srcRect, destRect;
    int xpos;
    int ypos;
    int id = 0;
    bool canFree = false;
};


#endif //PG4400_V22_KNR1033_GAMEOBJECT_H
