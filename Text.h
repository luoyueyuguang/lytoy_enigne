//
// Created by luoyue on 2023/10/11.
//

#ifndef LY_ENGINE_TEXT_H
#define LY_ENGINE_TEXT_H
#include "defines.h"
#include "Sprite.h"

class Text : virtual public Sprite
{
public:
    explicit Text(const char *text, const char *font_name, int font_size, SDL_Color color);
    ~Text();

    void render(Render* render) override;

    void load_texture(Render* render) override;

    void set_text(const char* text);
    [[nodiscard]] const char* get_text() const;

    void set_font_name(const char* font_name);
    [[nodiscard]] const char* get_font_name() const;

    void set_font_size(int font_size);
    [[nodiscard]] int get_font_size() const;

    void set_color(SDL_Color color);
    [[nodiscard]] SDL_Color get_text_color() const;

    void set_text_rect(SDL_Rect text_rect);
    [[nodiscard]] SDL_Rect get_text_rect() const;

    void set_text_texture(SDL_Texture* text_texture);
    [[nodiscard]] SDL_Texture* get_text_texture() const;

    void set_text_font(FC_Font* text_font);
    [[nodiscard]] FC_Font* get_text_font() const;


    void set_text_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    void set_text_color(uint32_t hex);
private:

    const char* text = nullptr;
    const char* font_name = nullptr;
    int font_size = 0;
    SDL_Color color = {r, g, b, a};

    FC_Font* text_font = nullptr;

    //隐藏
    [[nodiscard]] double get_angle() const override;
    SDL_Point* get_center() override;
    uint8_t get_flip() override;

    void set_angle(double angle) override;
    void set_center(SDL_Point* center) override;
    void set_flip(uint8_t flip) override;

    int set_animation(int id, std::vector<Rect> frames) override;
    int set_animation(std::vector<Rect> frames) override;

    ull get_animation_size(int id) override;
    std::vector<Rect> get_animation(int id) override;
};

#endif //LY_ENGINE_TEXT_H
