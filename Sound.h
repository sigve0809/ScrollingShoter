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
    if(channel < 8) return channel++;
    else return channel -= 7;
}
class Sound {
public:
    Sound(std::string soundFile);
    void update();
    virtual ~Sound();

    void play();
    bool getIsDone();

private:
    Mix_Chunk *soundEffect;
    bool done = false;
    int timer = 10;
};


#endif //PG4400_V22_KNR1033_SOUND_H
