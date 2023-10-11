//
// Created by luoyue on 2023/10/8.
//

#include "Ui.h"

UI::~UI()
{
    SDL_DestroyTexture(this->texture);
    buttons.clear();
}

UI::UI(const char *file_name) : Scene(file_name) {}

void UI::render_button(Render *render)
{
    for (auto& s : this->buttons) {
        s.second->render(render);
    }
}

void UI::del_button(int id) {
    this->buttons.erase(this->buttons.begin() + id);

}

void UI::del_button(Button *button)
{
    for (auto& s : this->buttons)
    {
        if (s.second == button)
        {
            this->buttons.erase(this->buttons.begin() + s.first);
            return;
        }
    }
}

void UI::del_button(const char *name) {
    for (auto& s : this->buttons)
    {
        if (s.second->get_name() == name)
        {
            this->buttons.erase(this->buttons.begin() + s.first);
            return;
        }
    }
}

void UI::change_button(int id, Button *button)
{
    this->buttons[id].second = button;
}

void UI::change_button(Button *button1, Button *button2) {
    for (auto& s : this->buttons)
    {
        if (s.second == button1)
        {
            s.second = button2;
            return;
        }
    }
}

void UI::change_button(const char *name, Button *button) {
    for (auto& s : this->buttons)
    {
        if (s.second->get_name() == name)
        {
            s.second = button;
            return;
        }
    }
}

ull UI::add_button(Button *button)
{
    this->buttons.emplace_back(this->buttons.size(), button);
    return this->buttons.size() - 1;
}

ull UI::add_button(int x, int y, int w, int h)
{
    this->buttons.emplace_back(this->buttons.size(), new Button(x, y, w, h));
    return this->buttons.size() - 1;
}

ull UI::add_button(int radius, int centreX, int centreY)
{
    this->buttons.emplace_back(this->buttons.size(), new Button(radius, centreX, centreY));
    return this->buttons.size() - 1;
}

ull UI::add_button(const char *name)
{
    this->buttons.emplace_back(this->buttons.size(), new Button(name));
    return this->buttons.size() - 1;
}

void UI::render_button(Render* render, Button *button)
{
    for(auto& s : this->buttons)
    {
        if(s.second == button)
        {
            s.second->render(render);
            return;
        }
    }
}

void UI::render_button(Render *render, int id)
{
    this->buttons[id].second->render(render);
}

[[maybe_unused]] void UI::render_button(Render *render, const char *name)
{
    for(auto& s : this->buttons)
    {
        if(s.second->get_name() == name)
        {
            s.second->render(render);
            return;
        }
    }
}

void UI::render_sprite(Render *render)
{
    for (auto& s : this->buttons)
    {
        s.second->render(render);
    }
}

void UI::load_sprite(Render *render)
{
    for (auto& s : this->buttons)
    {
        s.second->load_texture(render);
    }
}

//不允许被UI调用
void UI::render_sprite(Render *render, Sprite *sprite) {}
void UI::render_sprite(Render *render, int id) {}
void UI::render_sprite(Render *render, const char *name) {}
int UI::add_sprite(Sprite *sprite) {}
int UI::get_sprite_id(Sprite *sprite) {}
void UI::del_sprite(Sprite *sprite) {}
void UI::del_sprite(int id) {}
void UI::del_sprite(const char *name) {}
