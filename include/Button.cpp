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
    if(!this->circle_button)
    {
        SDL_Log("Button: new CircleButton failed");
    }
    is_circle = true;
}

Button::Button(const char *text, const char *font_name, int font_size, SDL_Color color)
        : Sprite(nullptr) {
    this->text = new Text(text, font_name, font_size, color);
    if(!this->text)
    {
        SDL_Log("Button: new Text failed");
    }
    is_text = true;
}

bool Button::get_clicked() const
{
    return this->is_clicked;
}

void Button::set_clicked(bool isClicked)
{
    this->is_clicked = isClicked;
}


void Button::render_circle(Render *render) const
{
    if(!is_circle||!this->circle_button)
    {
        SDL_Log("Button: render_circle failed");
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
    if(!is_sprite)
    {
        SDL_Log("Button: render_sprite failed");
        return;
    }
    SDL_RenderCopy(render, this->texture, &this->src, &this->dst);
}

void Button::render_text(Render *render) const
{
    if(!is_text||!this->text)
    {
        SDL_Log("Button: render_text failed");
        return;
    }
    this->text->set_dst(this->dst);
    this->text->set_x(this->dst.x);
    this->text->set_y(this->dst.y);
    this->text->set_w(this->dst.w);
    this->text->set_h(this->dst.h);

    this->text->render(render);
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
    if(is_text)
    {
        render_text(render);
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

bool Button::is_text_button() const
{
    return is_text;
}

void Button::on_click(GameEvent event, const std::function<void()> &func)
{
    if(event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button) {
            int x = event.motion.x;
            int y = event.motion.y;
            SDL_Log("Button: on_click %d %d", x, y);
            SDL_Point p = {x, y};
            auto rect = this->dst;
            if(is_text)
            {
                rect = this->text->get_text_rect();
                SDL_Log("Button: on_click text %d %d %d %d", rect.x, rect.y, rect.w, rect.h);
            }
            if (SDL_PointInRect(&p, &rect))
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

void Button::load_texture(Render *render)
{
    if(is_sprite)
    {
        Sprite::load_texture(render);
    }
    if(is_text)
    {
        this->text->load_texture(render);
    }
}
