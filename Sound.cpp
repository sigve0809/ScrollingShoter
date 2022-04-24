//
// Created by Sigve Langva on 4/13/2022.
//

#include "Sound.h"
Sound::Sound(const std::string& soundFile) : soundEffect(Mix_LoadWAV(soundFile.c_str())) {}

Sound::Sound() {}//Playeing sound on channelnumber(h) given on init
void Sound::play() {
    h = getChannel();
    std::cout << "Channel: " << h << std::endl;
    Mix_PlayChannel(h, soundEffect, 0);
}


void Sound::update() {
    //free channel if playing is done
    if (timer <= 0) {
        done = true;
        std::cout << "free\n";
        Mix_HaltChannel(h);
        Mix_FreeChunk(soundEffect);
        soundEffect = nullptr;
    }
    timer--;
}
//Playing song infinite amount of times
void Sound::playSong() {
    Mix_PlayMusic(song, -1);
}

//Stop and free channel
void Sound::stopSong() {
    Mix_HaltMusic();
    Mix_FreeMusic(song);
    song = nullptr;
}

