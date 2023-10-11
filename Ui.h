//
// Created by luoyue on 2023/10/8.
//

#ifndef LY_ENGINE_UI_H
#define LY_ENGINE_UI_H


#include "Scene.h"
#include "Button.h"

class UI : virtual public Scene
{
public:
    explicit UI(const char* file_name);
    ~UI();
    ull add_button(Button* button);
    ull add_button(int x, int y, int w, int h);
    ull add_button(int radius, int centreX, int centreY);
    ull add_button(const char* name);

    void del_button(int id);
    void del_button(Button* button);
    void del_button(const char* name);

    void change_button(int id, Button* button);
    void change_button(Button* button1, Button* button2);
    void change_button(const char* name, Button* button);

    void render_sprite(Render* render) override;
    void render_button(Render* render, Button* button);
    void render_button(Render* render, int id);

    [[maybe_unused]] void render_button(Render* render, const char* name);
    void render_button(Render *render);

    void load_sprite(Render *render) override;
    //static void on_click(Button *b, GameEvent event, const std::function<void()> &func);

private:
    std::vector<std::pair<int, Button*>> buttons;

    //不允许被UI类调用
    void render_sprite(Render* render, Sprite* sprite) override;
    void render_sprite(Render* render, int id) override ;
    void render_sprite(Render* render, const char* name) override;

    int add_sprite(Sprite* sprite) override;
    int get_sprite_id(Sprite *sprite) override;

    void del_sprite(Sprite* sprite) override ;
    void del_sprite(int id) override;
    void del_sprite(const char* name) override;
};

#endif //LY_ENGINE_UI_H
