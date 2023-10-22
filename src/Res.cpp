//
// Created by luoyue on 2023/10/16.
//

#include "Res.h"
void Res::create_renderer()
{
    window.CreateRenderer();
}

//创建场景
void Res::create_scene()
{
    //设置场景的位置和大小
    scene.set_dst(0, 0, 1470, 810);
    //设置场景的来源图片的位置和大小
    scene.set_src(0, 0, 1960, 1080);
}

void Res::create_sprite()
{
    player.set_dst(735, 600, 45, 75);
    player.set_src(walk_rect[0]);
    enemy.set_dst(0, 555, 240, 120);
    enemy.set_src(hor_att[0]);
}

void Res::add_player_animation()
{
    player.set_animation(walk_rect);
    player.set_animation(rush_rect);
    player.set_animation(attack_rect);
    enemy.set_animation(ver_att);
    enemy.set_animation(hor_att);
}

void Res::create_menu()
{
    //创建菜单
    menu.set_dst(0, 0, 1470, 810);
    menu.set_src(0, 0, 1960, 1080);
}

//创建开始按钮
void Res::create_menu_start()
{
    //由于实现者自身水平的原因， 推荐使用set_x和set_y来设置按钮的位置， 而不是set_dst。
    menu_start.set_x(820);
    menu_start.set_y(520);
}

//创建介绍按钮
void Res::create_menu_intro()
{
    menu_intro.set_x(820);
    menu_intro.set_y(600);
}
//创建退出按钮
void Res::create_menu_exit()
{
    menu_exit.set_x(820);
    menu_exit.set_y(680);
}

//输赢界面的按钮
void Res::set_win_lose_button()
{
    lose_scene_exit.set_x(820);
    lose_scene_exit.set_y(680);

    lose_scene_you_lose.set_x(735 - 200);
    lose_scene_you_lose.set_y(415 - 100);

    lose_scene_restart.set_x(820);
    lose_scene_restart.set_y(600);

    win_scene_exit.set_x(820);
    win_scene_exit.set_y(680);

    win_scene_you_win.set_x(735 -200);
    win_scene_you_win.set_y(415 - 100);

    win_scene_restart.set_x(820);
    win_scene_restart.set_y(600);
}

//创建输赢场景
void Res::create_win_and_lose_scene()
{
    win_scene.set_dst(0, 0, 1470, 810);
    win_scene.set_src(0, 0, 1960, 1080);

    lose_scene.set_dst(0, 0, 1470, 810);
    lose_scene.set_src(0, 0, 1960, 1080);
}

//将按钮添加到菜单中
void Res::menu_add_button()
{
    menu.add_button(&menu_start);
    menu.add_button(&menu_intro);
    menu.add_button(&menu_exit);

    lose_scene.add_button(&lose_scene_exit);
    lose_scene.add_button(&lose_scene_restart);
    lose_scene.add_button(&lose_scene_you_lose);

    win_scene.add_button(&win_scene_exit);
    win_scene.add_button(&win_scene_restart);
    win_scene.add_button(&win_scene_you_win);
}

//构造生命值
void Res::player_life_emplace()
{
    for(int i = 0; i < 10; i++)
    {
        player_life.emplace_back(scene.add_sprite(new Sprite{"../res/life.png",
                                                             {0, 0, 80, 80},
                                                             {i * 50, 0, 40, 40},
                                                             SDL_FLIP_NONE}));
    }
}

//窗口添加场景
void Res::window_add_scene()
{
    window.add_scene(&menu);
    window.add_scene(&scene);
    window.add_scene(&win_scene);
    window.add_scene(&lose_scene);
    scene.add_sprite(&player);
    scene.add_sprite(&enemy);
    player_life_emplace();
}

//场景添加更新
void Res::scene_add_update()
{
    scene.add_update([&]() {
        if(player.get_x() < 0)
        {
            player.set_x(0);
        }
        if(player.get_x() > 1470)
        {
            player.set_x(1470);
        }
        if(player.get_y() < 0)
        {
            player.set_y(0);
        }
        if(player.get_y() > 600)
        {
            player.set_y(600);
        }
    });

    scene.add_update([&]() {
        enemy.play_animation(1);
        enemy.set_w(240);
        enemy.set_h(120);
        if(enemy.get_x() < 0)
        {
            enemy.set_x(0);
            enemy.set_flip(SDL_FLIP_NONE);
        }
        if(enemy.get_x() > 1470)
        {
            enemy.set_x(1470);
            enemy.set_flip(SDL_FLIP_HORIZONTAL);
        }
        enemy.set_x(enemy.get_x() + (enemy.get_flip() == SDL_FLIP_NONE ? 25 : -25));
    });

    scene.add_update([&]() {
        enemy.play_animation(0);
        enemy.set_w(60);
        enemy.set_h(300);
        if(enemy.get_y() >= 555)
        {
            enemy.set_y(0);
            enemy.set_x(player.get_x());
        }
        {
            enemy.set_y(enemy.get_y() + 12);
        }
    });

    scene.add_update([&]() {
        if(Box::check_collision(&player, &enemy))
        {
            player.set_x(player.get_x() + (player.get_flip() == SDL_FLIP_NONE ? -25 : 25));
        }
    });

    scene.add_update([&]() {
        if(Box::check_collision(&player, &enemy))
        {
            if(!player_life.empty())
            {
                scene.del_sprite(player_life.back());
                player_life.pop_back();
            }
        }
    });

    scene.add_update([&]() {
        for(auto weapon : weapons)
        {
            if(Box::check_collision(weapon, &enemy))
            {
                enemy_life--;
            }
        }
    });
}
//将菜单和场景添加到窗口中

//必须等精灵或按钮都被添加到场景后才能加载场景
void Res::load_scene()
{
    window.load_scene(0);
}

//数据加载函数
void Res::load_data()
{
    create_renderer();
    create_scene();
    create_sprite();
    add_player_animation();
    set_win_lose_button();
    create_win_and_lose_scene();
    create_menu();
    create_menu_start();
    create_menu_intro();
    create_menu_exit();
    menu_add_button();
    window_add_scene();
    scene_add_update();
    load_scene();
}