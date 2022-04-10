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
    GameObject(const char *texturesheet, int x, int y, SDL_Renderer *renderer, bool b);
    ~GameObject();

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
    int getY(){
        return ypos;
    }
    int getX(){
        return xpos;
    }
    void destroyGameObject();
    void setWidthHeight(int w, int h);
    int getWidth(){
        return width;
    }
    int getHeight(){
        return height;
    }
    bool isActive(){
        return active;
    }
    void setCanFree(){
        canFree = true;
    }
    bool getCanFree(){
        return canFree;
    }
    bool isBackground(){return background;}
    void setNotActive(){
        destroyGameObject();
        active = false;
    }
    void setID(int x){id = x;}
    int getID(){return id;}
private:
    int width = 32;
    int height = 32;
protected:
    bool background;
    bool active = true;
    SDL_Texture *objTexture;
    SDL_Rect srcRect, destRect;
    int xpos;
    int ypos;
    int id = 0;
    bool canFree = false;
};


#endif //PG4400_V22_KNR1033_GAMEOBJECT_H
