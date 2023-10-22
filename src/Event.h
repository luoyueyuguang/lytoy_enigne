//
// Created by luoyue on 2023/10/16.
//

#ifndef LY_ENGINE_EVENT_H
#define LY_ENGINE_EVENT_H

#include <memory>
#include "Res.h"
class Event : private Res
{

    //scene_id用于切换场景
    int scene_id = 0;
    SDL_Event event;
    void scene_add_event()
    {
        static bool is_jump = false;
        static bool is_rush = false;
        scene.add_event(SDL_KEYDOWN, [&]() {
            if(event.key.keysym.sym == SDLK_a)
            {
                player.set_x(player.get_x() - 10);
                player.set_flip(SDL_FLIP_NONE);
                player.play_animation(0);
            }
            if(event.key.keysym.sym == SDLK_d)
            {
                player.set_x(player.get_x() + 10);
                player.set_flip(SDL_FLIP_HORIZONTAL);
                player.play_animation(0);
            }
        });
    }

    void render_loop()
    {
            //清除渲染器
            window.RenderClear();
            //根据场景id来渲染场景
            window.render_scene(scene_id);

            //用于一些特定的渲染
            switch (scene_id)
            {
                case 0:
                    break;
                case 1:
                    break;
                default:
                    break;
            }

            //更新渲染器
            window.RenderPresent();
    }
    //主循环, 如果window.get_running()返回false则退出循环
    void event_loop()
    {
        static int is_rush = 0;
        static int is_jump = 0;
        static int is_attack = 0;
        static std::map<Sprite*, int> weapons;
        if(is_rush)
        {
            player.set_w(75);
            player.set_h(45);
            player.play_animation(1);
            int speed = player.get_flip() == SDL_FLIP_NONE ? -50 : 50;
            player.set_x(player.get_x() + speed);
            is_rush++;
            if(is_rush >= 4)
            {
                is_rush = 0;
                player.set_w(45);
                player.set_h(75);
                player.play_animation(0);
            }
        }
        if(is_jump)
        {
            if(is_jump <= 4)
            {
                player.set_y(player.get_y() - 45);
            }
            if(is_jump >= 7 && is_jump <= 12)
            {
                player.set_y(player.get_y() + 30);
            }
            is_jump++;
            if(is_jump >= 13)
            {
                is_jump = 0;
                player.set_y(600);
            }
        }
        if(is_attack)
        {
            player.play_animation(2);
            is_attack++;

            if(is_attack >= 8)
            {
                is_attack = 0;
                player.play_animation(0);
                player.set_w(45);
                player.set_h(75);
            }
        }
        for(auto& weapon : weapons)
        {
            weapon.first->set_x(weapon.first->get_x() + (weapon.first->get_flip() == SDL_FLIP_NONE ? 10 : -10));
            weapon.second--;
        }
        //SDL_Event用于接收事件
            //SDL_PollEvent用于获取事件
            while (SDL_PollEvent(&event))
            {
                //如果事件类型为SDL_QUIT则退出循环
                if (event.type == SDL_QUIT)
                {
                    window.set_running(false);
                    SDL_Quit();
                    return;
                }

                //根据场景id来处理事件
                switch (scene_id)
                {
                    case 0:
                        menu_start.on_click(event, [&]() { scene_id = 1;});
                        menu_intro.on_click(event, [&]() {});
                        menu_exit.on_click(event, [&]() { window.set_running(false); });
                        break;
                    case 1:
                    {
                        scene.on_key(event, SDLK_l, [&]() {
                            is_rush++;
                        });
                        scene.on_key(event, SDLK_k, [&]() {
                            is_jump++;
                        });
                        scene.on_key(event, SDLK_s, [&]() {
                                player.set_y(600);
                        });
                        scene.on_key(event, SDLK_j, [&]() {
                            is_attack++;
                            player.set_w(80);
                            player.set_h(80);
                            int offset = player.get_flip() == SDL_FLIP_NONE ? - 80: 45;
                            auto tmp = new Sprite{"../res/image23.png",
                                                  {0, 0, 160, 80},
                                                  {player.get_x() + offset,
                                                   player.get_y(), 80, 40, },
                                                  !player.get_flip()};
                            ull id = scene.add_sprite(tmp);
                            weapons.emplace(tmp, 10);
                            scene.load_sprite(window.get_render(), static_cast<int>(id));
                            SDL_Log("add weapon %d", id);
                        });
                        scene.handle_event(event);
                        break;
                    }
                }
            }
    }

    void update_loop()
    {
        //根据场景id来更新场景
        switch (scene_id)
        {
            case 0:
                break;
            case 1:
            {
                static int state = 1;
                scene.handle_update(0);
                if(enemy.get_x() < 0)
                {
                    state = 2;
                    //enemy.set_y(0);
                }
                if(enemy.get_y() > player.get_y())
                {
                    state = 1;
                }
                SDL_Log("state %d", state);
                scene.handle_update(state);
                scene.handle_update(3);
                scene.handle_update(4);
                if(player_life.empty())
                {
                    scene_id = 3;
                }
                break;
            }
            default:
                break;
        }
    }

public:
    void game_loop()
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
};


#endif //LY_ENGINE_EVENT_H
