//
// Created by luoyue on 2023/10/8.
//

#include "GameObject.h"

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
