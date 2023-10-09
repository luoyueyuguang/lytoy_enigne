//
// Created by luoyue on 2023/10/8.
//

#include "GameObject.h"

#include <utility>

void GameObject::set_dst(int x, int y, int w, int h)
{
    this->dst.x = x;
    this->dst.y = y;
    this->dst.w = w;
    this->dst.h = h;
}

void GameObject::set_src(int x, int y, int w, int h)
{
    this->src.x = x;
    this->src.y = y;
    this->src.w = w;
    this->src.h = h;
}

int GameObject::get_x()
{
    return this->dst.x;
}

int GameObject::get_y()
{
    return this->dst.y;
}

int GameObject::get_w()
{
    return this->dst.w;
}

int GameObject::get_h()
{
    return this->dst.h;
}

void GameObject::set_x(int x)
{
    this->dst.x = x;
}

void GameObject::set_y(int y)
{
    this->dst.y = y;
}

void GameObject::set_w(int w)
{
    this->dst.w = w;
}

void GameObject::set_h(int h)
{
    this->dst.h = h;
}

const char *GameObject::get_name() {
    return this->file_name;
}

GameObject::~GameObject() {
    SDL_DestroyTexture(this->texture);
}

[[maybe_unused]] GameObject::GameObject(const char *file_name)
{
    this->file_name = file_name;
}

void GameObject::load_texture(Render *render)
{
    this->texture = IMG_LoadTexture(render, this->file_name);
}

void GameObject::set_alpha(uint8_t alpha)
{
    SDL_SetTextureAlphaMod(this->texture, alpha);
}

uint8_t GameObject::get_alpha() {
    uint8_t alpha;
    SDL_GetTextureAlphaMod(this->texture, &alpha);
    return alpha;
}

/*int GameObject::set_animation(int id, std::vector<Rect> frames)
{
    this->animations[id] = std::move(frames);
    return id;
}

void GameObject::push_frames(int id, int x, int y, int w, int h)
{
    this->animations[id].push_back({x, y, w, h});
}

void GameObject::del_animation(int id) {
    this->animations.erase(id);
}

int GameObject::set_animation(std::vector<Rect> frames) {
    static int id = 0;
    this->animations[id] = std::move(frames);
    id++;
    return id-1;
}

int GameObject::get_animation_size(int id)
{
    return this->animations[id].size();
}

std::vector<Rect> GameObject::get_animation(int id) {
    return this->animations[id];
}*/

void GameObject::set_dst(Rect dst)
{
    this->dst = dst;
}

void GameObject::set_src(Rect src)
{
    this->src = src;
}




