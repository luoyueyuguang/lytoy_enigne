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
    static void render_circle(Render *render, int radius, int centreX, int centreY,
                      uint8_t r = 0x00, uint8_t g = 0xff, uint8_t b = 0x00, uint8_t a = 0xff);
    void render_circle(Render *render) const;

    explicit Button(const char *fileName);
    Button(int radius, int centreX, int centreY, uint8_t r, uint8_t g, uint8_t b,
           uint8_t a);
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

protected:
    bool is_clicked = false;
    uint8_t r = 0x00, g = 0xff, b = 0x00, a = 0xff;

    CircleButton* circle_button = nullptr;
};

#endif //LY_ENGINE_BUTTON_H
