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

    int get_x();
    int get_y();
    int get_w();
    int get_h();
    uint8_t get_alpha();
    const char* get_name();

    void set_x(int x);
    void set_y(int y);
    void set_w(int w);
    void set_h(int h);
    void set_alpha(uint8_t alpha);

    //void push_frames(int id, int x, int y, int w, int h);

    //void del_animation(int id);
protected:
    const char* file_name = nullptr;

    Texture* texture = nullptr;

    Rect dst = {0, 0, 0, 0};
    Rect src = {0, 0, 0, 0};
};


#endif //LY_ENGINE_GAMEOBJECT_H
