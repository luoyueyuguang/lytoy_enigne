//
// Created by luoyue on 2023/10/7.
//

#ifndef LYTOY_ENIGNE_SCENE_H
#define LYTOY_ENIGNE_SCENE_H
#include "defines.h"

class Scene
{
public:
    Scene(const char* file_name, Rect* dst, Rect* src):file_name(file_name), dst(*dst), src(*src){};
    ~Scene();

    void load_texture(Render* render);
    void render(Render* render);
private:
    const char* file_name = nullptr;

    Texture* texture = nullptr;

    Rect dst = {0, 0, 0, 0};
    Rect src = {0, 0, 0, 0};

    void render(Render *render, double angle, SDL_Point *center, auto flip);
};

#endif //LYTOY_ENIGNE_SCENE_H
