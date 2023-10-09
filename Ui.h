//
// Created by luoyue on 2023/10/8.
//

#ifndef LY_ENGINE_UI_H
#define LY_ENGINE_UI_H

#include "Sprite.h"
#include "Scene.h"
#include "Window.h"

class UI : public Scene {
public:

    explicit UI(const char* file_name);
    ~UI();

    //void handle_event(Event event);

    int add_element(Sprite* sprite);
    int get_element_id(Sprite* sprite);
    void del_element(Sprite* sprite = nullptr, int id = -1);

private:
    std::vector<std::pair<int, Sprite*>> elements;
};

#endif //LY_ENGINE_UI_H
