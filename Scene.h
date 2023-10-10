//
// Created by luoyue on 2023/10/7.
//

#ifndef LYTOY_ENIGNE_SCENE_H
#define LYTOY_ENIGNE_SCENE_H

#include "defines.h"
#include "Sprite.h"

class Scene : public GameObject
{
public:
    explicit Scene(const char* file_name);

    ~Scene();

    void render(Render* render);
    void render(Render *render, double angle, SDL_Point *center, auto flip);

    void load_sprite(Render* render);
    static void load_sprite(Render* render, Sprite* sprite);
    void load_sprite(Render* render, int id);
    void load_sprite(Render* render, const char* name);

    void render_sprite(Render* render);
    static void render_sprite(Render* render, Sprite* sprite);
    void render_sprite(Render* render, int id);
    void render_sprite(Render* render, const char* name);

    int add_sprite(Sprite* sprite);
    int get_sprite_id(Sprite *sprite);

    void del_sprite(Sprite* sprite);
    void del_sprite(int id);
    void del_sprite(const char* name);

   void handle_event(GameEvent event);
   void add_event(int id, const std::function<void()>& func);
   void del_event(int id);
   void change_event(int id, std::function<void()> func);
   void get_event(int id);

   void update();
   void add_update(const std::function<void()>& func);
   void del_update(int id);
   void change_update(int id, std::function<void()> func);
   void get_update(int id);
protected:
    std::vector<std::pair<int, std::function<void()>>> event_lists;
    std::vector<std::pair<int, Sprite*>> sprites;
    std::vector<std::function<void()>> update_lists;
};

#endif //LYTOY_ENIGNE_SCENE_H
