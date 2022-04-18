//
// Created by Sigve Langva on 4/13/2022.
//

#ifndef PG4400_V22_KNR1033_SOUND_H
#define PG4400_V22_KNR1033_SOUND_H

#include <string>
#include <iostream>
#include <SDL_mixer.h>
inline int getChannel(){
    static int channel = 0;
    std::cout << channel << std::endl;
    if(channel < 8) return channel++;
    else{
        channel = 0;
        return channel++;
    }
}
class Sound {
public:
    explicit Sound(const std::string& soundFile);
    Sound();

    void update();
    void playSong();
    void stopSong();
    void play();
    [[nodiscard]] bool isDone() const{return done;}

private:
    Mix_Chunk *soundEffect;
    Mix_Music *song = Mix_LoadMUS("../Assets/Androids.wav");
    bool done = false;
    int timer = 60;
    int h;
};


#endif //PG4400_V22_KNR1033_SOUND_H
