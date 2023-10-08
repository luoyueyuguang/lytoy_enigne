//
// Created by luoyue on 2023/10/7.
//

#include "Window.h"

Window::Window(const char* title, Uint32 flags, int width, int height, int x, int y) : GameObject(title)
{
    this->file_name = title;
    this->flags = flags;
    this->width = width;
    this->height = height;
    this->x = x;
    this->y = y;
    window = SDL_CreateWindow(this->file_name, this->x, this->y, this->width, this->height, this->flags);
}

void Window::CreateRenderer()
{
    this->render = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
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

void Window::render_scene(int id)
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

void Window::RenderClear()
{
    SDL_RenderClear(this->render);
}

void Window::RenderPresent()
{
    SDL_RenderPresent(this->render);
}

int Window::add_scene(Scene *scene)
{
    static int id = 0;
    scenes.emplace_back(id, scene);
    id++;
    return id - 1;
}

void Window::render_scene(Scene *scene)
{
    for (auto& s : this->scenes)
    {
        if (s.second == scene)
        {
            s.second->render(this->render);
            return;
        }
    }
}

void Window::render_scene(const char *name)
{
    for (auto& s : this->scenes)
    {
        if (s.second->get_name() == name)
        {
            s.second->render(this->render);
            return;
        }
    }
}

void Window::load_scene(Scene *scene)
{
    for (auto& s : this->scenes)
    {
        if (s.second == scene)
        {
            s.second->load_texture(this->render);
            return;
        }
    }
}

void Window::load_scene(int id)
{
    for (auto& s : this->scenes)
    {
        if (s.first == id)
        {
            s.second->load_texture(this->render);
            return;
        }
    }
}

void Window::load_scene(const char *name)
{
    for (auto& s : this->scenes)
    {
        if (s.second->get_name() == name)
        {
            s.second->load_texture(this->render);
            return;
        }
    }
}
