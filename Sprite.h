//
// Created by luoyue on 2023/10/7.
//

#ifndef LY_ENGINE_SPRITE_H
#define LY_ENGINE_SPRITE_H

#include <queue>
#include "defines.h"

class Sprite
{
public:
    Sprite(const char *file_name, Render* render);
    ~Sprite();

    void render(Render* render);

    void set_dst(int x, int y, int w, int h);
    void set_src(int x, int y, int w, int h);

    int get_x();
    int get_y();
    int get_w();
    int get_h();

    double get_angle();
    SDL_Point* get_center();
    uint8_t get_flip();

    void set_x(int x);
    void set_y(int y);
    void set_w(int w);
    void set_h(int h);

    void set_angle(double angle);
    void set_center(SDL_Point* center);
    void set_flip(uint8_t flip);

private:
    const char* file_name = nullptr;

    Texture* texture = nullptr;

    Rect dst = {0, 0, 0, 0};
    Rect src = {0, 0, 0, 0};

    double angle = 0;
    SDL_Point* center = nullptr;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    template<typename T>
    std::queue<Rect> animation;
};


#endif //LY_ENGINE_SPRITE_H
