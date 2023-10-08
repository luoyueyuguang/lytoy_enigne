//
// Created by luoyue on 2023/10/7.
//

#include "Window.h"

Window::Window(const char* title, Uint32 flags, int width, int height, int x, int y):
flags(flags), width(width), height(height), x(x), y(y)
{
    window = SDL_CreateWindow(title, x, y, width, height, flags);
}

void Window::CreateRenderer()
{
    this->render = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
}

void Window::set_x(int x)
{
    this->x = x;
}

void Window::set_y(int y)
{
    this->y = y;
}

void Window::set_width(int w)
{
    this->width = w;
}

void Window::set_height(int h)
{
    this->height = h;
}

int Window::get_x()
{
    return this->x;
}

int Window::get_y()
{
    return this->y;
}

int Window::get_width()
{
    return this->width;
}

int Window::get_height()
{
    return this->height;
}

void Window::add_scene(Scene *scene)
{
    static int id = 0;
    scenes.emplace_back(id, scene);
    id++;
}

int Window::get_scene_id(Scene *scene) {
    for (auto& s : this->scenes)
    {
        if (s.second == scene)
        {
            return s.first;
        }
    }
    return -1;
}

void Window::del_scene(Scene *scene, int id)
{
    if (id != -1)
    {
        this->scenes.erase(this->scenes.begin() + id);
        return;
    }
    else if (scene != nullptr)
    {
        for (auto& s : this->scenes)
        {
            if (s.second == scene)
            {
                this->scenes.erase(this->scenes.begin() + s.first);
                return;
            }
        }
    }
}

void Window::set_scene(int id)
{
    for (auto& s : this->scenes)
    {
        if (s.first == id)
        {
            s.second->load_texture(render);
            return;
        }
    }
}

void Window::RenderClear()
{
    SDL_RenderClear(this->render);
}

void Window::RenderPresent()
{
    SDL_RenderPresent(this->render);
}

void Window::RenderScene(int id)
{
    for (auto& s : this->scenes)
    {
        if (s.first == id)
        {
            s.second->render(this->render);
            return;
        }
    }

}

