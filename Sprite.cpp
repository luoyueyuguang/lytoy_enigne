//
// Created by luoyue on 2023/10/7.
//

#include "Sprite.h"

Sprite::~Sprite()
{
    SDL_DestroyTexture(this->texture);
}

void Sprite::render(Render *render)
{
    SDL_RenderCopyEx(render, this->texture, &this->src, &this->dst,
                     this->angle, this->center, this->flip);
}

void Sprite::set_angle(double angle)
{
    this->angle = angle;
    SDL_Log("Set angle %f", angle);
}

void Sprite::set_center(SDL_Point *center)
{
    this->center = center;
    SDL_Log("Set center %d %d", center->x, center->y);
}

void Sprite::set_flip(uint8_t flip)
{
    this->flip = static_cast<SDL_RendererFlip>(flip);
    SDL_Log("Set flip %d", flip);
}

double Sprite::get_angle()
{
    SDL_Log("Get angle %f", angle);
    return this->angle;
}

SDL_Point* Sprite::get_center()
{
    return this->center;
}

uint8_t Sprite::get_flip()
{
    return this->flip;
}

Sprite::Sprite(const char *file_name) : GameObject(file_name) {}

int Sprite::set_animation(int id, std::vector<Rect> frames) {
    this->animations[id] = frames;
    SDL_Log("Set animation %d", id);
    return id;
}

int Sprite::set_animation(std::vector<Rect> frames) {
    this->animations[animation_id] = frames;
    SDL_Log("Set animation %d", animation_id);
    return animation_id++;
}

std::vector<Rect> Sprite::get_animation(int id) {
    SDL_Log("Get animation %d", id);
    return this->animations[id];
}

int Sprite::get_animation_size(int id) {
    SDL_Log("Get animation size %d", id);
    return this->animations[id].size();
}
