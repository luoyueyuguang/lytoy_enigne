//
// Created by luoyue on 2023/10/12.
//

#ifndef LY_ENGINE_MUSIC_H
#define LY_ENGINE_MUSIC_H
#include "defines.h"

class Music
{
public:
    void add_music(const char* name);
    void add_chunk(const char* name);

    void play_music(const char *name, int loops);
    void play_chunk(const char *name, int loops, int channel);

    void free_music(const char* name);
    void free_chunk(const char* name);
private:
    using music = Mix_Music*;
    using chunk = Mix_Chunk*;
    std::unordered_map<char*, music> music_lists;
    std::unordered_map<char*, chunk> chunk_lists;
};


#endif //LY_ENGINE_MUSIC_H
