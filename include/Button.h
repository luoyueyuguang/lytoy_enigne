//
// Created by luoyue on 2023/10/9.
//

#ifndef LY_ENGINE_BUTTON_H
#define LY_ENGINE_BUTTON_H
#include "defines.h"
#include "CircleButton.h"
#include "Text.h"

class Button: virtual public Sprite
{
public:
    void render(Render *render) override;

    void load_texture(Render *render) override ;

    //渲染特定的不同的按钮
    void render_circle(Render *render) const;
    void render_rect(Render *render) const;
    void render_sprite(Render *render) const;
    void render_text(Render *render) const;

    explicit Button(const char *fileName);
    Button(int radius, int centreX, int centreY);
    Button(int x, int y, int w, int h);
    Button(const char *text, const char *font_name, int font_size, SDL_Color color);

    void set_clicked(bool isClicked);
    [[nodiscard]] bool get_clicked() const;

    [[nodiscard]] bool is_rect_button() const;
    [[nodiscard]] bool is_circle_button() const;
    [[nodiscard]] bool is_sprite_button() const;
    [[nodiscard]] bool is_text_button() const;

    void on_click(GameEvent event, const std::function<void()> &func);

private:
    bool is_clicked = false;

    bool is_rect = false;
    bool is_circle = false;
    bool is_sprite = false;
    bool is_text = false;

    CircleButton* circle_button = nullptr;
    Text* text = nullptr;
};

#endif //LY_ENGINE_BUTTON_H
