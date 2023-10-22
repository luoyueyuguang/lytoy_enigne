//
// Created by luoyue on 2023/10/11.
//

#include "Text.h"

Text::Text(const char *text, const char *font_name, int font_size, SDL_Color color)
        : Sprite(text) {
    this->text = text;
    this->font_name = font_name;
    this->font_size = font_size;
    this->color = color;
}

Text::~Text()
{
    FC_ClearFont(this->text_font);
}

void Text::render(Render *render)
{
    this->dst.w = FC_GetWidth(this->text_font, this->text);
    this->dst.h = FC_GetHeight(this->text_font, this->text);
    FC_Draw(this->text_font, render, static_cast<float >(this->dst.x),
            static_cast<float >(this->dst.y), this->text);
}

void Text::set_text(const char* text)
{
    this->text = text;
}

const char* Text::get_text() const
{
    return this->text;
}

void Text::set_font_name(const char* font_name)
{
    this->font_name = font_name;
}

const char* Text::get_font_name() const
{
    return this->font_name;
}

void Text::set_font_size(int font_size)
{
    this->font_size = font_size;
}

int Text::get_font_size() const
{
    return this->font_size;
}

void Text::set_color(SDL_Color color)
{
    this->color = color;
}

void Text::set_text_rect(SDL_Rect text_rect)
{
    this->dst = text_rect;
}

SDL_Rect Text::get_text_rect() const
{
    return this->dst;
}

void Text::set_text_texture(SDL_Texture* text_texture)
{
    this->texture = text_texture;
}

SDL_Texture* Text::get_text_texture() const
{
    return this->texture;
}

void Text::set_text_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    this->color = {r, g, b, a};
}

void Text::set_text_color(uint32_t hex)
{
    this->color = {static_cast<Uint8>(hex >> 24), static_cast<Uint8>(hex >> 16),
                   static_cast<Uint8>(hex >> 8), static_cast<Uint8>(hex)};
}

SDL_Color Text::get_text_color() const {
    return this->color;
}

void Text::load_texture(Render *render)
{
    this->text_font = FC_CreateFont();
    FC_LoadFont(this->text_font, render, this->font_name,
                this->font_size, this->color, TTF_STYLE_NORMAL);
}

void Text::set_text_font(FC_Font *text_font)
{
    this->text_font = text_font;
}

FC_Font* Text::get_text_font() const
{
    return this->text_font;
}

//隐藏， 不允许调用这些父类函数
double Text::get_angle() const { return 0; }
SDL_Point* Text::get_center() { return nullptr; }
uint8_t Text::get_flip() { return 0; }
void Text::set_angle(double angle) {}
void Text::set_center(SDL_Point* center) {}
void Text::set_flip(uint8_t flip) {}
int Text::set_animation(int id, std::vector<Rect> frames) {return 0;}
int Text::set_animation(std::vector<Rect> frames) {return 0;}
ull Text::get_animation_size(int id) {return 0;}
std::vector<Rect> Text::get_animation(int id) {return {};}
