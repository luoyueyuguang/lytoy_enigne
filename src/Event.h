//
// Created by luoyue on 2023/10/16.
//

#ifndef LY_ENGINE_EVENT_H
#define LY_ENGINE_EVENT_H

#include <memory>
#include "Res.h"
class Event : protected Res
{
protected:
    //scene_id用于切换场景
    int scene_id = 0;
    SDL_Event event;
    void scene_add_event();

    void render_loop();

    void event_loop();

    void update_loop();
};


#endif //LY_ENGINE_EVENT_H
