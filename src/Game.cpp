//
// Created by luoyue on 2023/10/23.
//

#include "Game.h"

void Game::game_loop()
{
    static const ll fps = 28; // 帧率
    static const ll frame = 1000 / fps; // 帧时间
    //设置窗口运行状态为true
    window.set_running(true);
    //加载数据
    load_data();
    scene_add_event();
    //主循环
    while (window.get_running())
    {
        ll begin = SDL_GetTicks();
        //事件循环
        event_loop();
        update_loop();
        //渲染循环
        render_loop();

        ll end = SDL_GetTicks();
        ll cost = end - begin;

        ll delay = frame - cost;
        if(delay > 0)
        {
            SDL_Delay(delay);
        }
    }
}