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
}

ull Scene::add_sprite(Sprite* sprite)
{
    this->sprites.emplace_back(this->sprites.size(), sprite);
    SDL_Log("Add sprite %s", sprite->get_name());
    return this->sprites.size() - 1;
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
    SDL_Log("Create scene %s", file_name);
}

void Scene::handle_event(GameEvent event)
{
    for (auto& e : this->event_lists)
    {
        if (e.first == event.type)
        {
            e.second();
        }
    }
}

ull Scene::add_event(int id, const std::function<void()>& func)
{
    this->event_lists.emplace_back(id, func);
    return this->event_lists.size() - 1;
}

void Scene::del_event(int id)
{
    this->event_lists.erase(this->event_lists.begin() + id);
}

void Scene::change_event(int id, std::function<void()> func)
{
    this->event_lists[id].second = std::move(func);
}

void Scene::set_event(int id)
{
    this->event_lists[id].second();
}

void Scene::update()
{
    for (auto& func : this->update_lists)
    {
        func();
    }
}

ull Scene::add_update(const std::function<void()>& func)
{
    this->update_lists.emplace_back(func);
    return this->update_lists.size() - 1;
    SDL_Log("Add update");
}

void Scene::del_update(int id)
{
    this->update_lists.erase(this->update_lists.begin() + id);
    SDL_Log("Delete update %d", id);
}

void Scene::change_update(int id, std::function<void()> func)
{
    this->update_lists[id] = std::move(func);
    SDL_Log("Change update %d", id);
}

void Scene::set_update(int id)
{
    this->update_lists[id]();
    SDL_Log("Get update %d", id);
}

void Scene::on_key(GameEvent event, int key_id, const std::function<void()>& func)
{
    if (event.type == SDL_KEYDOWN)
    {
        if(event.key.keysym.sym == key_id)
        {
            func();
        }
    }
}

void Scene::del_sprite()
{
    sprites.pop_back();
}

Sprite *Scene::get_sprite(int id) {
    return sprites[id].second;
}

void Scene::handle_update(int id)
{
    this->update_lists[id]();
}
