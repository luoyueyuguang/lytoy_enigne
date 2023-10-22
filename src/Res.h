//
// Created by luoyue on 2023/10/16.
//

#ifndef LY_ENGINE_RES_H
#define LY_ENGINE_RES_H
#include "../defines.h"
#include "../Window.h"
#include "../Ui.h"
#include "../Text.h"


class Res
{
protected:

    Window window{"test", SDL_WINDOW_SHOWN, 1470, 810};
    Scene scene{"../res/background.png"};
    Sprite player{"../res/player.png"};
    Sprite enemy{"../res/enemy.png"};
    //Sprite enemy{"../res/enemy.png"};
    //Sprite weapon{"../res/image23.png"};

    UI menu{"../res/menu.png"};
    Button menu_exit{"Exit", "../res/GBShinto-Regular.otf", 50,
                     {0xff, 0xff, 0xff, 0xff}};
    Button menu_start{"Start", "../res/GBShinto-Regular.otf", 50,
                      {0xff, 0xff, 0xff, 0xff}};
    Button menu_intro{"Introduction", "../res/GBShinto-Regular.otf", 50,
                      {0xff, 0xff, 0xff, 0xff}};
    //创建渲染器
    void create_renderer()
    {
        window.CreateRenderer();
    }

    //创建场景
    void create_scene()
    {
        //设置场景的位置和大小
        scene.set_dst(0, 0, 1470, 810);
        //设置场景的来源图片的位置和大小
        scene.set_src(0, 0, 1960, 1080);
    }

    void create_player()
    {
        player.set_dst(735, 600, 45, 75);
        player.set_src(walk_rect[0]);
    }


    //创建动画 这里会有很长的数组, 考虑到一个函数中实现它， 或者再建一个类。
    //走路图源
    std::vector<Rect> walk_rect = {{280, 642, 75, 130},
                                   {355, 642,  75, 130},
                                   {430, 642, 75, 130},
                                   {515,   642, 75, 130},
                                   {0, 777, 75, 130},
                                   {77, 777, 75, 130},
                                   {154, 777, 75, 130},
                                   {233, 270, 75, 130}};
    //跑步图源
    std::vector<Rect> rush_rect = {{0, 902, 130, 100},
                                   {125, 902, 130, 100},
                                   {255, 902, 130, 100},
                                   {375, 902, 130, 100}};
    //攻击图源
    std::vector<Rect> attack_rect = {{510, 902, 140, 85},
                                     {510, 902, 140, 85},
                                     {309, 777, 147, 120},
                                     {309, 777, 147, 120},
                                     {309, 777, 147, 120},
                                     {309, 777, 147, 120},
                                     {456, 777, 125, 110},
                                     {456, 777, 125, 110},
                                     };


    std::vector<Rect> enemy_attack1= {{0, 902, 130, 100},
                                      {125, 902, 130, 100},
                                      {255, 902, 130, 100},
                                      {375, 902, 130, 100}};

    std::vector<Rect> enemy_attack2= {{0, 902, 130, 100},
                                      {125, 902, 130, 100},
                                      {255, 902, 130, 100},
                                      {375, 902, 130, 100}};


    void add_player_animation()
    {
        player.set_animation(walk_rect);
        player.set_animation(rush_rect);
        player.set_animation(attack_rect);
    }

    void create_menu() {
        //创建菜单
        menu.set_dst(0, 0, 1470, 810);
        menu.set_src(0, 0, 1960, 1080);
    }

    //创建开始按钮
    void create_menu_start()
    {
        //由于实现者自身水平的原因， 推荐使用set_x和set_y来设置按钮的位置， 而不是set_dst。
        menu_start.set_x(820);
        menu_start.set_y(520);
    }

    //创建介绍按钮
    void create_menu_intro()
    {
        menu_intro.set_x(820);
        menu_intro.set_y(600);
    }
    //创建退出按钮
    void create_menu_exit()
    {
        menu_exit.set_x(820);
        menu_exit.set_y(680);
    }
    //将按钮添加到菜单中
    void menu_add_button()
    {
        menu.add_button(&menu_start);
        menu.add_button(&menu_intro);
        menu.add_button(&menu_exit);
    }

    void window_add_scene()
    {
        window.add_scene(&menu);
        window.add_scene(&scene);
        scene.add_sprite(&player);
    }
    //将菜单和场景添加到窗口中

    //必须等精灵或按钮都被添加到场景后才能加载场景
    void load_scene()
    {
        window.load_scene(0);
        window.load_scene(1);
    }

    void load_data()
    {
        create_renderer();
        create_scene();
        create_player();
        add_player_animation();
        create_menu();
        create_menu_start();
        create_menu_intro();
        create_menu_exit();
        menu_add_button();
        window_add_scene();
        load_scene();
    }
};


#endif //LY_ENGINE_RES_H
