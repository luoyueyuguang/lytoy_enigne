//
// Created by luoyue on 2023/10/7.
//

#ifndef LY_ENGINE_SPRITE_H
#define LY_ENGINE_SPRITE_H

#include "defines.h"
#include "GameObject.h"

class Sprite : public GameObject
{
public:
    explicit Sprite(const char* file_name);
    ~Sprite();

    virtual void render(Render* render);

    [[nodiscard]] double get_angle() const;
    SDL_Point* get_center();
    uint8_t get_flip();

    void set_angle(double angle);
    void set_center(SDL_Point* center);
    void set_flip(uint8_t flip);

    int set_animation(int id, std::vector<Rect> frames);
    int set_animation(std::vector<Rect> frames);

    ull get_animation_size(int id);
    std::vector<Rect> get_animation(int id);

protected:

    int animation_id = 0;

    double angle = 0;
    SDL_Point* center = nullptr;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    std::map<int, std::vector<Rect>> animations;
};

#endif //LY_ENGINE_SPRITE_H
