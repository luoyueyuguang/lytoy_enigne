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
    is_running = true;
    if(window == nullptr)
    {
        SDL_Log("Create window failed: %s", SDL_GetError());
        exit(1);
    }
    SDL_Log("Create window %s", this->file_name);
}

void Window::CreateRenderer()
{
    this->render = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
    if(this->render == nullptr)
    {
        SDL_Log("Create render failed: %s", SDL_GetError());
        exit(1);
    }
    SDL_Log("Create render %s", this->file_name);
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
            s.second->render_sprite(this->render);
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
    return id ++;
}

void Window::render_scene(Scene *scene)
{
    for (auto& s : this->scenes)
    {
        if (s.second == scene)
        {
            s.second->render(this->render);
            s.second->render_sprite(this->render);
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
            s.second->render_sprite(this->render);
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
            s.second->load_sprite(this->render);
            return;
        }
    }
    scene->load_sprite(this->render);
}

void Window::load_scene(int id)
{
    for (auto& s : this->scenes)
    {
        if (s.first == id)
        {
            s.second->load_texture(this->render);
            s.second->load_sprite(this->render);
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
            s.second->load_sprite(this->render);
            return;
        }
    }
}

Render *Window::get_render()
{
    return this->render;
}

void Window::set_running(bool is_running)
{
    this->is_running = is_running;
}

bool Window::get_running() const
{
    return this->is_running;
}

Window::~Window()
{
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->render);
    SDL_Log("Delete window %s", this->file_name);
}

void Window::load_scene_true(Scene *scene) {
    for (auto& s : this->scenes)
    {
        if (s.second == scene)
        {
            s.second->load_texture(this->render);
            return;
        }
    }
}

void Window::load_scene_true(int id) {
    for (auto& s : this->scenes)
    {
        if (s.first == id)
        {
            s.second->load_texture(this->render);
            return;
        }
    }
}

void Window::load_scene_true(const char *name) {
    for (auto& s : this->scenes)
    {
        if (s.second->get_name() == name)
        {
            s.second->load_texture(this->render);
            return;
        }
    }
}
