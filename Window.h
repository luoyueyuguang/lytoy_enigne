//
// Created by luoyue on 2023/10/7.
//

#ifndef LY_ENGINE_WINDOW_H
#define LY_ENGINE_WINDOW_H
#include "defines.h"
#include "Scene.h"

class Window
{
public:
    Window(const char* title, Uint32 flags,  int width, int height,
           int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED);

    Render* CreateRenderer();

    void set_x(int x);
    void set_y(int y);
    void set_width(int w);
    void set_height(int h);

    int get_x();
    int get_y();
    int get_width();
    int get_height();

    void add_scene(Scene* scene);
    int get_scene_id(Scene* scene);
    void del_scene(Scene* scene = nullptr, int id = -1);
    void set_scene(int id);

private:
    int x;
    int y;
    int width;
    int height;
    Uint32 flags = 0;

    std::vector<std::pair<int, Scene*>> scenes = {};

    Win_dow* window = nullptr;
};
#endif //LY_ENGINE_WINDOW_H
