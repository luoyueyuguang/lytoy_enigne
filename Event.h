//
// Created by luoyue on 2023/10/8.
//

#ifndef LY_ENGINE_EVENT_H
#define LY_ENGINE_EVENT_H

#include "defines.h"
#include "GameObject.h"
#define MY_EVENT_TYPE SDL_USEREVENT + 1

class Event {
public:
    explicit Event(GameObject &object);
    ~Event();

    void add_action();
    void del_action();

    void add_event();
    void del_event();

private:
    std::map<GameEvent , std::function<void()>> events;
    //std::map<, std::function<void()>> actions;

    GameObject& object;
};

#endif //LY_ENGINE_EVENT_H
