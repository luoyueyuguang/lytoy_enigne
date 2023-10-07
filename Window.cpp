//
// Created by luoyue on 2023/10/7.
//

#include "Window.h"


Render *Window::CreateRenderer()
{
    return SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
}

Window::Window(const char *title, Uint32 flags, int width, int height, int x, int y):
    x(x), y(y), width(width), height(height), flags(flags)
{
    this->window = SDL_CreateWindow(title, x, y, width, height, flags);
    if (this->window == nullptr) {
        SDL_Log("Create window failed: %s\n", SDL_GetError());
        exit(1);
    }
}
