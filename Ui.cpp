//
// Created by luoyue on 2023/10/8.
//

#include "Ui.h"

UI::~UI()
{
    SDL_DestroyTexture(this->texture);
    sprites.clear();
}

UI::UI(const char *file_name) : Scene(file_name) {}



void UI::render_button(Render *render) {
    for (auto& s : this->buttons) {
        s.second->render(render);
    }
}

void UI::render_circle(Render *render)
{
    for (auto& s : this->buttons)
    {
        s.second->renderCircle(render);
    }


}

int UI::add_button(const char *name, int x, int y, int w, int h) {
    static int id = 0;
    this->sprites.emplace_back(id, new Button(x, y, w, h));
    id++;
    return id - 1;
}

int UI::add_button(Button *button) {
    static int id = 0;
    this->buttons.emplace_back(id, button);
    id++;
    return id - 1;
}

int UI::add_button(const char *name, int radius, int centreX, int centreY, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    static int id = 0;
    this->buttons.emplace_back(id, new Button(radius, centreX, centreY, r, g, b, a));
    id++;
    return id - 1;
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

void UI::change_button(int id, Button *button) {
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
