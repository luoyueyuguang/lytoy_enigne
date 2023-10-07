//
// Created by luoyue on 2023/10/7.
//

#include "Window.h"

Window::Window(const char* title, Uint32 flags, int width, int height, int x, int y):
flags(flags), width(width), height(height), x(x), y(y)
{
    window = SDL_CreateWindow(title, x, y, width, height, flags);
}

Render *Window::CreateRenderer()
{
    return SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
}
