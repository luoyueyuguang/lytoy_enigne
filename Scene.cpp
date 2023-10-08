//
// Created by luoyue on 2023/10/7.
//

#include "Scene.h"


Scene::Scene(const char *file_name, Rect *src, Rect *dst) : file_name(file_name), src(*src), dst(*dst) {}

Scene::~Scene()
{
    SDL_DestroyTexture(this->texture);
}

void Scene::load_texture(Render *render)
{
    this->texture = IMG_LoadTexture(render, this->file_name);
    if (this->texture == nullptr)
    {
        SDL_Log("load texture failed: %s\n", SDL_GetError());
        exit(1);
    }
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
}

void Scene::add_sprite(Sprite* sprite)
{
    static int id = 0;
    this->sprites.emplace_back(id, sprite);
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

void Scene::del_sprite(Sprite *sprite, int id)
{
    if (id != -1)
    {
        this->sprites.erase(this->sprites.begin() + id);
        return;
    }
    else if (sprite != nullptr)
    {
        for (auto& s : this->sprites)
        {
            if (s.second == sprite)
            {
                this->sprites.erase(this->sprites.begin() + s.first);
                return;
            }
        }
    }
}


