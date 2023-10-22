//
// Created by luoyue on 2023/10/23.
//

#ifndef LY_ENGINE_GAME_H
#define LY_ENGINE_GAME_H
#include "Event.h"

class Game:private Event
{
public:
    //主循环, 如果window.get_running()返回false则退出循环
    void game_loop();
};


#endif //LY_ENGINE_GAME_H
