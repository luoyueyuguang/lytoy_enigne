//
// Created by luoyue on 2023/10/7.
//

#include "Scene.h"

Scene::~Scene()
{
    SDL_DestroyTexture(texture);
}

void Scene::load_texture(Render *render)
{
    texture = IMG_LoadTexture(render, file_name);
}

void Scene::render(Render *render)
{
    SDL_RenderCopy(render, texture, &src, &dst);
}

void Scene::render(Render *render, double angle, SDL_Point *center, auto flip)
{
    SDL_RenderCopyEx(render, texture, &src, &dst, angle, center, flip);
}





