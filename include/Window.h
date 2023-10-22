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

    ~Window();

    void CreateRenderer();
    void RenderPresent();
    void RenderClear();

    //场景有关操作
    int add_scene(Scene* scene);
    int get_scene_id(Scene* scene);
    void del_scene(Scene* scene = nullptr, int id = -1);

    //加载场景及场景里的精灵
    void load_scene(Scene* scene);
    void load_scene(int id);
    void load_scene(const char* name);

    //纯加载场景，不加载场景里的精灵
    void load_scene_true(Scene* scene);
    void load_scene_true(int id);
    void load_scene_true(const char* name);

    //渲染场景
    void render_scene(int id);
    void render_scene(Scene* scene);
    void render_scene(const char* name);

    Render* get_render() ;

    void set_running(bool is_running);
    [[nodiscard]] bool get_running() const;
private:
    int x = SDL_WINDOWPOS_CENTERED;
    int y = SDL_WINDOWPOS_CENTERED;
    int width;
    int height;
    Uint32 flags = -1;

    bool is_running = false;

    std::vector<std::pair<int, Scene*>> scenes;

    Win_dow* window = nullptr;
    Render *render = nullptr;
};

#endif //LY_ENGINE_WINDOW_H
