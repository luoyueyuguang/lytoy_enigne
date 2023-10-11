//
// Created by luoyue on 2023/10/9.
//

#include "Button.h"

Button::Button(const char *fileName) : Sprite(fileName)
{
    is_sprite = true;
}

Button::Button(int x, int y, int w, int h) : Sprite(nullptr)
{
    this->dst.x = x;
    this->dst.y = y;
    this->dst.w = w;
    this->dst.h = h;
    is_rect = true;
}

Button::Button(int radius, int centreX, int centreY) : Sprite(nullptr)
{
    this->circle_button = new CircleButton(radius, centreX, centreY);
    is_circle = true;
}


bool Button::get_clicked() const
{
    return this->is_clicked;
}

void Button::set_clicked(bool isClicked)
{
    this->is_clicked = isClicked;
}

void Button::set_r(uint8_t r)
{
    this->r = r;
}

uint8_t Button::get_r() const
{
    return this->r;
}

void Button::set_g(uint8_t g)
{
    this->g = g;
}

uint8_t Button::get_g() const
{
    return this->g;
}

void Button::set_b(uint8_t b)
{
    this->b = b;
}

uint8_t Button::get_b() const
{
    return this->b;
}

void Button::set_a(uint8_t a)
{
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

void Button::render_circle(Render *render) const
{
    if(!is_circle)
    {
        return;
    }
    SDL_SetRenderDrawColor(render, r, g, b, a);
    CircleButton::render_circle(render, this->circle_button->get_radius(),
                                this->circle_button->get_centreX(),
                                this->circle_button->get_centreY());
    SDL_SetRenderDrawColor(render, 0x00, 0xff, 0x00, 0xff);
}

void Button::render_rect(Render *render) const
{
    SDL_SetRenderDrawColor(render, r, g, b, a);
    SDL_RenderFillRect(render,new  Rect {this->dst.x, this->dst.y, this->dst.w, this->dst.h});
    SDL_SetRenderDrawColor(render, 0x00, 0xff, 0x00, 0xff);
}

void Button::render_sprite(Render *render) const
{
    SDL_RenderCopy(render, this->texture, &this->src, &this->dst);
}

void Button::render(Render *render)
{
    if(is_circle)
    {
        render_circle(render);
    }
    if(is_rect)
    {
        render_rect(render);
    }
    if(is_sprite)
    {
        render_sprite(render);
    }
}

bool Button::is_rect_button() const
{
    return is_rect;
}

bool Button::is_circle_button() const
{
    return is_circle;
}

bool Button::is_sprite_button() const
{
    return is_sprite;
}

void Button::on_click(GameEvent event, const std::function<void()> &func) {
    if(event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button) {
            int x = event.motion.x;
            int y = event.motion.y;
            SDL_Point p = {x, y};
            if (SDL_PointInRect(&p, &this->dst))
            {
                func();
                return;
            }
            else if(is_circle)[[unlikely]]
            {
                auto distance  = std::sqrt(std::pow(x - this->circle_button->get_centreX(), 2) +
                        std::pow(y - this->circle_button->get_centreY(), 2));
                if(distance <= this->circle_button->get_radius())
                {
                    func();
                    return;
                }
            }
        }
    }

}
