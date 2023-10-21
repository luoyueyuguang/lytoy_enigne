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
    Sprite(const char *fileName, Rect src, Rect dst, uint8_t flip = SDL_FLIP_NONE);
    ~Sprite();

    virtual void render(Render* render);

    [[nodiscard]] virtual double get_angle() const;

    virtual SDL_Point* get_center();

    virtual uint8_t get_flip();

    virtual void set_angle(double angle);

    virtual void set_center(SDL_Point* center);

    virtual void set_flip(uint8_t flip);

    virtual int set_animation(int id, std::vector<Rect> frames);

    virtual int set_animation(std::vector<Rect> frames);

    virtual ull get_animation_size(int id);

    virtual std::vector<Rect> get_animation(int id);

    void play_animation(int id);

    void set_r(uint8_t r);
    [[nodiscard]] uint8_t get_r() const;

    void set_g(uint8_t g);
    [[nodiscard]] uint8_t get_g() const;

    void set_b(uint8_t b);
    [[nodiscard]] uint8_t get_b() const;

    void set_a(uint8_t a);
    [[nodiscard]] uint8_t get_a() const;

    void set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    void set_color(uint32_t hex);

    [[nodiscard]] virtual uint32_t get_color() const;
protected:

    int animation_id = 0;

    double angle = 0;
    SDL_Point* center = nullptr;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    std::map<int, std::vector<Rect>> animations;

    uint8_t r = 0x00, g = 0xff, b = 0x00, a = 0xff;
};

#endif //LY_ENGINE_SPRITE_H
