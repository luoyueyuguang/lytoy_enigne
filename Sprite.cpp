//
// Created by luoyue on 2023/10/7.
//

#include "Sprite.h"

Sprite::Sprite(const char *file_name, Render *render) : file_name(file_name)
{
    texture = IMG_LoadTexture(render, file_name);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(this->texture);
}

void Sprite::render(Render *render)
{
    SDL_RenderCopyEx(render, this->texture, &this->src, &this->dst, angle, center, flip);
}

void Sprite::set_dst(int x, int y, int w, int h)
{
    this->dst.x = x;
    this->dst.y = y;
    this->dst.w = w;
    this->dst.h = h;
}

void Sprite::set_src(int x, int y, int w, int h)
{
    this->src.x = x;
    this->src.y = y;
    this->src.w = w;
    this->src.h = h;
}

void Sprite::set_x(int x)
{
    this->dst.x = x;
}

void Sprite::set_y(int y)
{
    this->dst.y = y;
}

void Sprite::set_w(int w)
{
    this->dst.w = w;
}

void Sprite::set_h(int h)
{
    this->dst.h = h;
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

int Sprite::get_x()
{
    return this->dst.x;
}

int Sprite::get_y()
{
    return this->dst.y;
}

int Sprite::get_w()
{
    return this->dst.w;
}

int Sprite::get_h()
{
    return this->dst.h;
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