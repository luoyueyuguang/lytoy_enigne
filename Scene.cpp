//
// Created by luoyue on 2023/10/7.
//

#include "Scene.h"


Scene::Scene(const char *file_name, Rect *src, Rect *dst) : file_name(file_name), src(*src), dst(*dst) {}

Scene::~Scene() {
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

void Scene::render(Render *render) {
    SDL_RenderCopy(render, this->texture, &this->src, &this->dst);

}

void Scene::render(Render *render, double angle, SDL_Point *center, auto flip) {
    SDL_RenderCopyEx(render, this->texture, &this->src, &this->dst, angle, center, flip);
}

void Scene::render_sprite(Render *render)
{

    for (auto sprite : this->sprites)
    {
        sprite->render(render);
    }
}

void Scene::add_sprite(Sprite *sprite)
{
    this->sprites.push_back(sprite);
}

