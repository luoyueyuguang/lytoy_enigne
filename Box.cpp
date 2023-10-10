//
// Created by luoyue on 2023/10/10.
//

#include <algorithm>
#include "Box.h"

bool Box::check_collision(GameObject *obj1, GameObject *obj2) {
    bool x = obj1->get_x() + obj1->get_w() >= obj2->get_x() &&
             obj2->get_x() + obj2->get_w() >= obj1->get_x();
    bool y = obj1->get_y() + obj1->get_h() >= obj2->get_y() &&
             obj2->get_y() + obj2->get_h() >= obj1->get_y();
    return x && y;
}

bool Box::check_collision(GameObject *obj1, int x, int y, int w, int h) {
    bool x1 = obj1->get_x() + obj1->get_w() >= x &&
              x + w >= obj1->get_x();
    bool y1 = obj1->get_y() + obj1->get_h() >= y &&
              y + h >= obj1->get_y();
    return x1 && y1;
}

bool Box::check_collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2)
{
    bool x = x1 + w1 >= x2 &&
             x2 + w2 >= x1;
    bool y = y1 + h1 >= y2 &&
             y2 + h2 >= y1;
    return x && y;
}

bool Box::check_collision(GameObject *obj1, const std::vector<GameObject *>& objs) {
    std::ranges::any_of(objs, [obj1](GameObject* obj2){
        return check_collision(obj1, obj2);
    });
}

uint32_t Box::check_collision(GameObject *obj1, const std::vector<GameObject *> &objs, std::vector<uint32_t> &ids)
{
    uint32_t sum = 0;
    for (size_t i = 0; i < objs.size(); ++i) {
        if (check_collision(obj1, objs[i])) {
            ids.push_back(i);
            sum++;
        }
    }
    return sum;
}

uint32_t Box::check_collision(const std::vector<GameObject *> &objs, const std::vector<GameObject *> &objs2,
                              std::vector<std::pair<uint32_t, uint32_t>> &ids1)
{

    uint32_t sum = 0;
    for (size_t i = 0; i < objs.size(); ++i) {
        for (size_t j = 0; j < objs2.size(); ++j) {
            if (check_collision(objs[i], objs2[j]))
            {
                ids1.emplace_back(i, j);
                     sum++;
            }
        }
    }
    return sum;
}

bool Box::check_pixel_collision(GameObject *obj1, GameObject *obj2)
{
    int w1, h1;
    SDL_QueryTexture(obj1->get_texture(), nullptr, nullptr, &w1, &h1);
    int w2, h2;
    SDL_QueryTexture(obj2->get_texture(), nullptr, nullptr, &w2, &h2);
    auto *pixels1 = new uint32_t[w1 * h1];
    auto *pixels2 = new uint32_t[w2 * h2];
    SDL_RenderReadPixels(window->get_render(), nullptr, SDL_PIXELFORMAT_RGBA8888,
                            pixels1,w1 * sizeof(uint32_t));
    SDL_RenderReadPixels(window->get_render(), nullptr, SDL_PIXELFORMAT_RGBA8888,
                         pixels2,w2 * sizeof(uint32_t));
    for(auto y1 = 0; y1 < h1; y1++)
    {
        for(auto x1 = 0; x1 < w1; x1++)
        {
            auto pixel1 = pixels1[y1*w1 + x1];

            for(auto y2=0; y2 < h2; y2++)
            {
                for(auto x2=0; x2 < w2; x2++)
                {
                    auto pixel2 = pixels2[y2*w2 + x2];

                    int r1 = static_cast<int>((pixel1 >> 24) & 0xff);
                    int g1 = static_cast<int>((pixel1 >> 16) & 0xff);
                    int b1 = static_cast<int>((pixel1 >> 8) & 0xff);

                    int r2 = static_cast<int>((pixel2 >> 24) & 0xff);
                    int g2 = static_cast<int>((pixel2 >> 16) & 0xff);
                    int b2 = static_cast<int>((pixel2 >> 8) & 0xff);


                    if(std::abs(r1-r2)<COLOR_THRESHOLD &&
                       std::abs(g1-g2)<COLOR_THRESHOLD &&
                       std::abs(b1-b2)<COLOR_THRESHOLD)
                    {
                        int dx = x1 - x2;
                        int dy = y1 - y2;
                        if(dx*dx + dy*dy < DISTANCE_THRESHOLD*DISTANCE_THRESHOLD)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
}

Box::Box(Window *window)
{
    this->window = window;
}

void Box::set_color_threshold(int colorThreshold)
{
    this->COLOR_THRESHOLD = colorThreshold;
}

int Box::get_color_threshold() const
{
    return this->COLOR_THRESHOLD;
}

void Box::set_distance_threshold(int distanceThreshold)
{
    this->DISTANCE_THRESHOLD = distanceThreshold;
}

int Box::get_distance_threshold() const
{
    return this->DISTANCE_THRESHOLD;
}
