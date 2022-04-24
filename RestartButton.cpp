//
// Created by Sigve Langva on 4/14/2022.
//

#include "RestartButton.h"

RestartButton::RestartButton(const std::string& string, SDL_Renderer *renderer, int x, int y, int width, int height) {
    text = std::make_shared<Text>(renderer, string, x, y, width, height);
    rect = {text->getX()-10, text->getY()-10, text->getWidth()*2+20, text->getHeight()*2+20};
    color = {255, 255, 255, 140};
}

void RestartButton::update() {
    text->Update();
    checkState();
}

void RestartButton::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
    text->Render(renderer);
}
//Checking if mouse is over the button(calleds in handleEvents)
bool RestartButton::getHover(int x, int y) {
    if (x <= text->getX()-10+(text->width()*2)+20
    && x >= text->getX()-10
    && y >= text->getY()-10
    && y <= text->getY()-10+(text->height()*2)+20) {
        state = HOVER;
    }
    else {
        state = OFF;
    }
    return false;
}



//Called in handleevents when mousebutton is clicked. If mouse is hovering the button then state is changes to clicked
bool RestartButton::getClicked() {
    if (state == HOVER) {
        state = CLICKED;
        return true;
    }
    return false;
}

//Checking state and acts accordingly to this state
void RestartButton::checkState() {
    std::cout << state << std::endl;
    if (state == CLICKED) {
        restarted = true;
        state = OFF;
    }
    if (state == HOVER) {
        color = {220, 220, 220, 255};
    }
    else{
        color = {140, 140, 140, 0};

    }
}


