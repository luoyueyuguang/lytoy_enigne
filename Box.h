//
// Created by luoyue on 2023/10/10.
//

#ifndef LY_ENGINE_BOX_H
#define LY_ENGINE_BOX_H

#include "defines.h"
#include "GameObject.h"
#include "Button.h"
#include "Window.h"

class Box
{
public:
    Box() = delete;
    explicit Box(Window* window);

    static bool check_collision(GameObject* obj1, GameObject* obj2);
    static bool check_collision(GameObject* obj1, int x, int y, int w, int h);
    static bool check_collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
    static bool check_collision(GameObject* obj1, const std::vector<GameObject*>& objs);

    static uint32_t check_collision(GameObject* obj1, const std::vector<GameObject*>& objs, std::vector<uint32_t>& ids);
    static uint32_t check_collision(const std::vector<GameObject*>& objs, const std::vector <GameObject*>& objs2,
                             std::vector<std::pair<uint32_t, uint32_t>>& ids1);

    bool check_pixel_collision(GameObject* obj1, GameObject* obj2);

    void set_color_threshold(int colorThreshold);
    [[nodiscard]] int get_color_threshold() const;

    void set_distance_threshold(int distanceThreshold);
    [[nodiscard]] int get_distance_threshold() const;
private:
    Window* window;
    int COLOR_THRESHOLD = 30;
    int  DISTANCE_THRESHOLD= 10;
};


#endif //LY_ENGINE_BOX_H
