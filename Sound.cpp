//
// Created by Sigve Langva on 4/13/2022.
//

#include "Sound.h"

void Sound::play() {
    int h = getChannel();
    std::cout << "Channel: " << h << std::endl;
    Mix_PlayChannel(h, soundEffect, 0);
}

Sound::Sound(std::string soundFile) : soundEffect(Mix_LoadWAV(soundFile.c_str())) {}

Sound::~Sound() {
}

void Sound::update() {
    if (timer == 0) {
        done = true;
    }
}

bool Sound::getIsDone() {
    if (timer <= 0){
        Mix_FreeChunk(soundEffect);
        return true;
    }
    timer--;
    return false;
}
