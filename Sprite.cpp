//
// Created by luoyue on 2023/10/7.
//

#include "Sprite.h"

#include <utility>

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

double Sprite::get_angle() const
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

Sprite::Sprite(const char *file_name) : GameObject(file_name)
{
    SDL_Log("Create sprite %s", file_name);
}

int Sprite::set_animation(int id, std::vector<Rect> frames) {
    this->animations[id] = std::move(frames);
    SDL_Log("Set animation %d", id);
    return id;
}

int Sprite::set_animation(std::vector<Rect> frames) {
    this->animations[animation_id] = std::move(frames);
    SDL_Log("Set animation %d", animation_id);
    return animation_id++;
}

std::vector<Rect> Sprite::get_animation(int id) {
    SDL_Log("Get animation %d", id);
    return this->animations[id];
}

ull Sprite::get_animation_size(int id) {
    SDL_Log("Get animation size %d", id);
    return this->animations[id].size();
}

void Sprite::set_r(uint8_t r) {
    this->r = r;
    SDL_Log("Set r %d", r);
}

uint8_t Sprite::get_r() const {
    SDL_Log("Get r %d", r);
    return this->r;
}

void Sprite::set_g(uint8_t g) {
    this->g = g;
    SDL_Log("Set g %d", g);
}

uint8_t Sprite::get_g() const {
    SDL_Log("Get g %d", g);
    return this->g;
}

void Sprite::set_b(uint8_t b) {
    this->b = b;
    SDL_Log("Set b %d", b);
}

uint8_t Sprite::get_b() const {
    SDL_Log("Get b %d", b);
    return this->b;
}

void Sprite::set_a(uint8_t a) {
    this->a = a;
    SDL_Log("Set a %d", a);
}

uint8_t Sprite::get_a() const {
    SDL_Log("Get a %d", a);
    return this->a;
}

void Sprite::set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
    SDL_Log("Set color %d %d %d %d", r, g, b, a);
}

void Sprite::set_color(uint32_t hex)
{
    this->r = (hex & 0xff000000) >> 24;
    this->g = (hex & 0x00ff0000) >> 16;
    this->b = (hex & 0x0000ff00) >> 8;
    this->a = (hex & 0x000000ff);
    SDL_Log("Set color %d %d %d %d", r, g, b, a);
}

uint32_t Sprite::get_color() const {
    SDL_Log("Get color %d %d %d %d", r, g, b, a);
    return (r << 24) | (g << 16) | (b << 8) | a;
}
