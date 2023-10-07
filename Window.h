//
// Created by luoyue on 2023/10/7.
//

#ifndef LY_ENGINE_WINDOW_H
#define LY_ENGINE_WINDOW_H
#include "defines.h"

class Window
{
public:
    Window(const char* title, Uint32 flags,  int width, int height,
           int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED);
    Render* CreateRenderer();
private:
    int x;
    int y;
    int width;
    int height;
    Uint32 flags = 0;
    Win_dow* window = nullptr;
};


#endif //LY_ENGINE_WINDOW_H
