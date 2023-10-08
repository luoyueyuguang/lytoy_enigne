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
    SDL_RenderCopyEx(render, this->texture, &this->src, &this->dst, this->angle, this->center, this->flip);
}

void Sprite::set_angle(double angle)
{
    this->angle = angle;
}

void Sprite::set_center(SDL_Point *center)
{
    this->center = center;
}

void Sprite::set_flip(uint8_t flip)
{
    this->flip = static_cast<SDL_RendererFlip>(flip);
}

double Sprite::get_angle()
{
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