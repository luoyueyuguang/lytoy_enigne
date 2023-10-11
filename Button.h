//
// Created by luoyue on 2023/10/9.
//

#ifndef LY_ENGINE_BUTTON_H
#define LY_ENGINE_BUTTON_H
#include "defines.h"
#include "Sprite.h"
#include "CircleButton.h"

class Button: virtual public Sprite
{
public:
    void render(Render *render) override;

    void render_circle(Render *render) const;
    void render_rect(Render *render) const;
    void render_sprite(Render *render) const;

    explicit Button(const char *fileName);
    Button(int radius, int centreX, int centreY);
    Button(int x, int y, int w, int h);

    void set_clicked(bool isClicked);
    [[nodiscard]] bool get_clicked() const;

    void set_r(uint8_t r);
    [[nodiscard]] uint8_t get_r() const;

    void set_g(uint8_t g);
    [[nodiscard]] uint8_t get_g() const;

    void set_b(uint8_t b);
    [[nodiscard]] uint8_t get_b() const;

    void set_a(uint8_t a);
    [[nodiscard]] uint8_t get_a() const;

    void set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

    [[nodiscard]] bool is_rect_button() const;
    [[nodiscard]] bool is_circle_button() const;
    [[nodiscard]] bool is_sprite_button() const;

    void on_click(GameEvent event, const std::function<void()> &func);

private:
    bool is_clicked = false;
    uint8_t r = 0x00, g = 0xff, b = 0x00, a = 0xff;

    bool is_rect = false;
    bool is_circle = false;
    bool is_sprite = false;

    CircleButton* circle_button = nullptr;
};

#endif //LY_ENGINE_BUTTON_H
