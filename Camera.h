//
// Created by luoyue on 2023/10/8.
//

#ifndef LY_ENGINE_CAMERA_H
#define LY_ENGINE_CAMERA_H
#include "defines.h"
#include "Sprite.h"
#include "Window.h"

class Camera
{
public:
    Camera(Window* window, Sprite* sprite);
    ~Camera();

private:
    Sprite* sprite = nullptr;
    Window* window = nullptr;
    Scene* scene = nullptr;
};


#endif //LY_ENGINE_CAMERA_H
