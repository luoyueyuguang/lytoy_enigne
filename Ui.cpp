//
// Created by luoyue on 2023/10/8.
//

#include "Ui.h"
//UI::UI(const char *file_name, Rect *src, Rect *dst) : Scene(file_name, src, dst) {}

/*void UI::handle_event(Event event) {
    for (auto& element : this->elements) {
        switch (event.type) {
            case SDL_MOUSEMOTION:
                element.second->handle_mouse_click(event);
                break;
            case SDL_KEYDOWN:
                element.second->handle_key_press(event);
                break;
            case SDL_QUIT:
                element.second->handle_window_close(event);
                break;
            default:
                // Handle unknown event
                break;
        }
    }
}*/

int UI::add_element(Sprite* sprite) {
    static int id = 0;
    this->elements.emplace_back(id, sprite);
    id++;
    return id - 1;
}

int UI::get_element_id(Sprite* sprite) {
    for (auto& e : this->elements) {
        if (e.second == sprite) {
            return e.first;
        }
    }
    return -1;
}

void UI::del_element(Sprite* sprite, int id) {
    if (id != -1) {
        this->elements.erase(this->elements.begin() + id);
        return;
    }
    else if (sprite != nullptr) {
        for (auto& e : this->elements) {
            if (e.second == sprite) {
                this->elements.erase(this->elements.begin() + e.first);
                return;
            }
        }
    }
}

UI::~UI()
{
    SDL_DestroyTexture(this->texture);
    elements.clear();
}

UI::UI(const char *file_name) : Scene(file_name){
}
