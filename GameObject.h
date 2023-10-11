//
// Created by luoyue on 2023/10/8.
//

#ifndef LY_ENGINE_GAMEOBJECT_H
#define LY_ENGINE_GAMEOBJECT_H

#include "defines.h"

class GameObject
{
public:
    explicit GameObject(const char* file_name);
    void load_texture(Render* render);
    ~GameObject();
    void set_dst(int x, int y, int w, int h);
    void set_src(int x, int y, int w, int h);

    void set_dst(Rect dst);
    void set_src(Rect src);

    Rect & get_dst();
    Rect & get_src();

    [[nodiscard]] int get_x() const;
    [[nodiscard]] int get_y() const;
    [[nodiscard]] int get_w() const;
    [[nodiscard]] int get_h() const;
    uint8_t get_alpha();
    const char* get_name();

    void set_x(int x);
    void set_y(int y);
    void set_w(int w);
    void set_h(int h);
    void set_alpha(uint8_t alpha);

    void set_src_x(int x);
    void set_src_y(int y);
    void set_src_w(int w);
    void set_src_h(int h);

    [[nodiscard]] int get_src_x() const;
    [[nodiscard]] int get_src_y() const;
    [[nodiscard]] int get_src_w() const;
    [[nodiscard]] int get_src_h() const;

    void set_name(const char* name);

    SDL_Texture *get_texture();

protected:
    const char* file_name = nullptr;

    Texture* texture = nullptr;

    Rect dst = {0, 0, 0, 0};
    Rect src = {0, 0, 0, 0};
};


#endif //LY_ENGINE_GAMEOBJECT_H
