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
private:

    std::vector<std::pair<int, Sprite*>> sprites;
    //Event
};

#endif //LYTOY_ENIGNE_SCENE_H
