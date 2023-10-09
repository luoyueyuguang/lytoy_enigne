//
// Created by luoyue on 2023/10/7.
//

#include "Scene.h"

Scene::~Scene()
{
    if(this->texture != nullptr)
    {
        SDL_DestroyTexture(this->texture);
    }
    sprites.clear();
}

void Scene::render(Render *render)
{
    SDL_RenderCopy(render, this->texture, &this->src, &this->dst);
    render_sprite(render);
}

void Scene::render(Render *render, double angle, SDL_Point *center, auto flip)
{
    SDL_RenderCopyEx(render, this->texture, &this->src, &this->dst, angle, center, flip);
    render_sprite(render);
}

void Scene::render_sprite(Render *render)
{
    for (auto& sprite : this->sprites)
    {
        sprite.second->render(render);
    }
    SDL_Log("Render sprite");
}

int Scene::add_sprite(Sprite* sprite)
{
    static int id = 0;
    this->sprites.emplace_back(id, sprite);
    SDL_Log("Add sprite %d", id);
    return id++;
}

int Scene::get_sprite_id(Sprite* sprite)
{
    for (auto& s : this->sprites)
    {
        if (s.second == sprite)
        {
            return s.first;
        }
    }
    return -1;
}

void Scene::del_sprite(Sprite *sprite)
{
    for (auto& s : this->sprites)
    {
        if (s.second == sprite)
        {
            this->sprites.erase(this->sprites.begin() + s.first);
            SDL_Log("Delete sprite %s", sprite->get_name());
            return;
        }
    }
}

void Scene::del_sprite(int id)
{
        this->sprites.erase(this->sprites.begin() + id);
        SDL_Log("Delete sprite %d", id);
}

void Scene::del_sprite(const char* name)
{
    for (auto& s : this->sprites)
    {
        if (s.second->get_name() == name)
        {
            this->sprites.erase(this->sprites.begin() + s.first);
            SDL_Log("Delete sprite %s", name);
            return;
        }
    }
}

void Scene::render_sprite(Render *render, Sprite *sprite)
{
    sprite->render(render);
    SDL_Log("Render sprite %s", sprite->get_name());
}

void Scene::render_sprite(Render *render, int id)
{
    this->sprites[id].second->render(render);
    SDL_Log("Render sprite %d", id);
}

void Scene::render_sprite(Render *render, const char* name)
{
    for (auto& s : this->sprites)
    {
        if (s.second->get_name() == name)
        {
            s.second->render(render);
            return;
        }
    }
}

void Scene::load_sprite(Render *render)
{
    for (auto& sprite : this->sprites)
    {
        sprite.second->load_texture(render);
    }
}

void Scene::load_sprite(Render *render, Sprite *sprite)
{
    sprite->load_texture(render);
}

void Scene::load_sprite(Render *render, int id)
{
    this->sprites[id].second->load_texture(render);
}

void Scene::load_sprite(Render *render, const char* name)
{
    for (auto& s : this->sprites)
    {
        if (s.second->get_name() == name)
        {
            s.second->load_texture(render);
            return;
        }
    }
}

Scene::Scene(const char *file_name) : GameObject(file_name)
{
}
