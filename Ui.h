//
// Created by luoyue on 2023/10/8.
//

#ifndef LY_ENGINE_UI_H
#define LY_ENGINE_UI_H


#include "Scene.h"
#include "Button.h"




class UI : public Scene {
public:

    explicit UI(const char* file_name);
    ~UI();
    int add_button(Button* button);
    int add_button(const char* name, int x, int y, int w, int h);
    int add_button(const char* name, int radius, int centreX, int centreY,
                   uint8_t r = 0x00, uint8_t g = 0xff, uint8_t b = 0x00, uint8_t a = 0xff);

    void del_button(int id);
    void del_button(Button* button);
    void del_button(const char* name);

    void change_button(int id, Button* button);
    void change_button(Button* button1, Button* button2);
    void change_button(const char* name, Button* button);

    void render_circle(Render* render);
    void render_button(Render* render);
private:
    //std::vector<std::pair<int, Sprite*>> elements;
    std::vector<std::pair<int, Button*>> buttons;
};

#endif //LY_ENGINE_UI_H
