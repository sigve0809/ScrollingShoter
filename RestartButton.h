//
// Created by Sigve Langva on 4/14/2022.
//

#ifndef PG4400_V22_KNR1033_RESTARTBUTTON_H
#define PG4400_V22_KNR1033_RESTARTBUTTON_H


#include "Text.h"
#include <memory>
#include <vector>

class RestartButton {
public:
    RestartButton(std::string string, SDL_Renderer *renderer, int x, int y, int width, int height);

    enum State {OFF, HOVER, CLICKED};
    void update();
    void render(SDL_Renderer *renderer);
    void setOrMoveMenu(){
        if (restarted) restarted = false;
        else restarted = true;
    }
    bool getRestarted(){return restarted;}
    bool getHover(int x, int y);
    bool getClicked();
    void checkState();

private:
    std::shared_ptr<Text> text;
    bool restarted = true;
    int lastX = 0;
    int lastY = 0;
    SDL_Rect rect;
    SDL_Color color;
    State state;

};


#endif //PG4400_V22_KNR1033_RESTARTBUTTON_H
