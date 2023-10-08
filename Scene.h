//
// Created by luoyue on 2023/10/7.
//

#ifndef LYTOY_ENIGNE_SCENE_H
#define LYTOY_ENIGNE_SCENE_H

#include <vector>
#include "defines.h"
#include "Sprite.h"

class Scene
{
public:
    Scene(const char* file_name, Rect* src, Rect* dst);
    ~Scene();

    void load_texture(Render* render);


    void render(Render* render);
    void render(Render *render, double angle, SDL_Point *center, auto flip);
    void render_sprite(Render* render);

    void add_sprite(Sprite* sprite);
    int get_sprite_id(Sprite *sprite);
    void del_sprite(Sprite* sprite = nullptr, int id = -1);

private:
    const char* file_name = nullptr;

    Texture* texture = nullptr;

    Rect dst = {0, 0, 0, 0};
    Rect src = {0, 0, 0, 0};

    std::vector<std::pair<int, Sprite*>> sprites;
};

#endif //LYTOY_ENIGNE_SCENE_H
