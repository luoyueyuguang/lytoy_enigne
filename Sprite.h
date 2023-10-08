//
// Created by luoyue on 2023/10/7.
//

#ifndef LY_ENGINE_SPRITE_H
#define LY_ENGINE_SPRITE_H

#include <queue>
#include "defines.h"
#include "GameObject.h"

class Sprite : public GameObject
{
public:
    Sprite(const char *file_name, Render* render);
    ~Sprite();

    void render(Render* render);

    double get_angle();
    SDL_Point* get_center();
    uint8_t get_flip();

    void set_angle(double angle);
    void set_center(SDL_Point* center);
    void set_flip(uint8_t flip);

private:

    double angle = 0;
    SDL_Point* center = nullptr;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
};
#endif //LY_ENGINE_SPRITE_H
