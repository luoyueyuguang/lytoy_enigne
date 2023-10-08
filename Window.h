//
// Created by luoyue on 2023/10/7.
//

#ifndef LY_ENGINE_WINDOW_H
#define LY_ENGINE_WINDOW_H
#include "defines.h"
#include "Scene.h"

class Window : virtual public GameObject
{
public:
    Window(const char* title, Uint32 flags,  int width, int height,
           int x = SDL_WINDOWPOS_CENTERED, int y = SDL_WINDOWPOS_CENTERED);

    void CreateRenderer();
    void RenderPresent();
    void RenderClear();

    int add_scene(Scene* scene);
    int get_scene_id(Scene* scene);
    void del_scene(Scene* scene = nullptr, int id = -1);

    void load_scene(Scene* scene);
    void load_scene(int id);
    void load_scene(const char* name);


    void render_scene(int id);
    void render_scene(Scene* scene);
    void render_scene(const char* name);

private:
    int x;
    int y;
    int width;
    int height;
    Uint32 flags = 0;

    std::vector<std::pair<int, Scene*>> scenes = {};

    Win_dow* window = nullptr;
    Render *render = nullptr;
};
#endif //LY_ENGINE_WINDOW_H
