//
// Created by luoyue on 2023/10/12.
//

#include "Music.h"

void Music::add_music(const char *name)
{
    Mix_Music* music = Mix_LoadMUS(name);
    if (music == nullptr)
    {
        SDL_Log("Load music %s failed: %s", name, Mix_GetError());
        return;
    }

    music_lists.insert(std::pair<char*, Mix_Music*>(const_cast<char*>(name), music));
    SDL_Log("Add music %s success", name);
}

void Music::add_chunk(const char *name)
{
    Mix_Chunk* chunk = Mix_LoadWAV(name);
    if (chunk == nullptr)
    {
        SDL_Log("Load chunk %s failed: %s", name, Mix_GetError());
        return;
    }

    chunk_lists.insert(std::pair<char*, Mix_Chunk*>(const_cast<char*>(name), chunk));
    SDL_Log("Add chunk %s success", name);
}

void Music::play_music(const char *name, int loops)
{
    for(auto& music : music_lists)
    {
        if (music.first == name)
        {
            Mix_PlayMusic(music.second, loops);
            SDL_Log("Play music %s success", name);
            return;
        }
    }
}

void Music::play_chunk(const char *name, int loops, int  channel)
{
    for(auto& chunk : chunk_lists)
    {
        if (chunk.first == name)
        {
            Mix_PlayChannel(channel, chunk.second, loops);
            SDL_Log("Play chunk %s success", name);
            return;
        }
    }
}

void Music::free_music(const char *name)
{
    for(auto& music : music_lists)
    {
        if (music.first == name)
        {
            Mix_FreeMusic(music.second);
            music_lists.erase(music.first);
            SDL_Log("Free music %s success", name);
            return;
        }
    }
}

void Music::free_chunk(const char *name)
{
    for(auto& chunk : chunk_lists)
    {
        if (chunk.first == name)
        {
            Mix_FreeChunk(chunk.second);
            chunk_lists.erase(chunk.first);
            SDL_Log("Free chunk %s success", name);
            return;
        }
    }
}
