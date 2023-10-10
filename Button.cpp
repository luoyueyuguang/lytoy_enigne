//
// Created by luoyue on 2023/10/9.
//

#include "Button.h"

Button::Button(const char *fileName) : Sprite(fileName){}

void Button::render(Render *render) {
    SDL_SetRenderDrawColor(render, r, g, b, a);
    SDL_RenderFillRect(render,new  Rect {this->dst.x, this->dst.y, this->dst.w, this->dst.h});
    SDL_SetRenderDrawColor(render, 0x00, 0xff, 0x00, 0xff);
}

void Button::set_clicked(bool isClicked)
{
    this->is_clicked = isClicked;
}

Button::Button(int x, int y, int w, int h) : Sprite(nullptr) {
    this->dst.x = x;
    this->dst.y = y;
    this->dst.w = w;
    this->dst.h = h;
}

bool Button::get_clicked() const {
    return this->is_clicked;
}

void Button::set_g(uint8_t g) {
    this->g = g;
}

uint8_t Button::get_g() const {
    return this->g;
}

void Button::set_b(uint8_t b) {
    this->b = b;
}

uint8_t Button::get_b() const {
    return this->b;
}

void Button::set_a(uint8_t a) {
    this->a = a;
}

uint8_t Button::get_a() const {
    return this->a;
}

void Button::set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Button::set_r(uint8_t r)
{
    this->r = r;
}

uint8_t Button::get_r() const
{
    return this->r;
}

void Button::render_circle(Render *render, int radius, int centreX, int centreY, uint8_t r, uint8_t g, uint8_t b,
                           uint8_t a)
{
    SDL_SetRenderDrawColor(render, r, g, b, a);
    new CircleButton(radius, centreX, centreY);
    CircleButton::render_circle(render, radius, centreX, centreY);
}

Button::Button(int radius, int centreX, int centreY, uint8_t r, uint8_t g, uint8_t b,
               uint8_t a) : Sprite(nullptr) {
    this->circle_button = new CircleButton(radius, centreX, centreY);
}

void Button::render_circle(Render *render) const
{
    CircleButton::render_circle(render, this->circle_button->get_radius(), this->circle_button->get_centreX(),
                                this->circle_button->get_centreY());
}
