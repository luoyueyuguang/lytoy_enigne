//
// Created by luoyue on 2023/10/16.
//

#ifndef LY_ENGINE_RES_H
#define LY_ENGINE_RES_H
#include "../defines.h"
#include "../Window.h"
#include "../Ui.h"
#include "../Text.h"
#include "../Box.h"


class Res
{
protected:

    Window window{"test", SDL_WINDOW_SHOWN, 1470, 810};
    Scene scene{"../res/background.png"};
    UI win_scene;
    UI lose_scene;

    Sprite player{"../res/player.png"};
    Sprite enemy{"../res/enemy.png"};
    Box box{&window};
    std::vector<int> player_life;
    //Sprite enemy{"../res/enemy.png"};
    //Sprite weapon{"../res/image23.png"};

    UI menu{"../res/menu.png"};
    Button menu_exit{"Exit", "../res/GBShinto-Regular.otf", 50,
                     {0xff, 0xff, 0xff, 0xff}};
    Button menu_start{"Start", "../res/GBShinto-Regular.otf", 50,
                      {0xff, 0xff, 0xff, 0xff}};
    Button menu_intro{"Introduction", "../res/GBShinto-Regular.otf", 50,
                      {0xff, 0xff, 0xff, 0xff}};

    Button win_scene_exit{"Exit", "../res/GBShinto-Regular.otf", 50,
                           {0xff, 0xff, 0xff, 0xff}};
    Button win_scene_restart{"Restart", "../res/GBShinto-Regular.otf", 50,
                              {0xff, 0xff, 0xff, 0xff}};
    Button win_scene_you_win{"You Win", "../res/GBShinto-Regular.otf", 50,
                              {0xff, 0xff, 0xff, 0xff}};

    Button lose_scene_exit{"Exit", "../res/GBShinto-Regular.otf", 50,
                           {0xff, 0xff, 0xff, 0xff}};
    Button lose_scene_restart{"Restart", "../res/GBShinto-Regular.otf", 50,
                              {0xff, 0xff, 0xff, 0xff}};
    Button lose_scene_you_lose{"You Lose", "../res/GBShinto-Regular.otf", 50,
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

    void create_sprite()
    {
        player.set_dst(735, 600, 45, 75);
        player.set_src(walk_rect[0]);
        enemy.set_dst(0, 555, 240, 120);
        enemy.set_src(hor_att[0]);
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


    std::vector<Rect> ver_att= {{240, 0, 210, 470},
                                {0,1045, 245, 425},
                                {0, 0 , 120, 615},
                                {120, 0, 120, 615},
                                };

    std::vector<Rect> hor_att = {{0, 2140, 480, 270},
                                 {0, 2910, 500, 240},
                                 {0, 3160, 500, 240},
                                 {0, 2400, 480, 240},};

    SDL_Rect attack = {0, 2660, 500, 250};


    void add_player_animation()
    {
        player.set_animation(walk_rect);
        player.set_animation(rush_rect);
        player.set_animation(attack_rect);
        enemy.set_animation(ver_att);
        enemy.set_animation(hor_att);
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

    void create_win_and_lose_scene()
    {
        win_scene.set_dst(0, 0, 1470, 810);
        win_scene.set_src(0, 0, 1960, 1080);
    }
    //将按钮添加到菜单中
    void menu_add_button()
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

    void window_add_scene()
    {
        window.add_scene(&menu);
        window.add_scene(&scene);
        scene.add_sprite(&player);
        scene.add_sprite(&enemy);
        for(int i = 0; i < 10; i++)
        {
            player_life.emplace_back(scene.add_sprite(new Sprite{"../res/life.png",
                                        {0, 0, 80, 80},
                                        {i * 50, 0, 40, 40},
                                        SDL_FLIP_NONE}));
        }
    }

    void scene_add_update()
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
            if(player.get_x() + player.get_w() >= enemy.get_x() && player.get_x() <= enemy.get_x() + enemy.get_w()
            && player.get_y() + player.get_h() >= enemy.get_y() && player.get_y() <= enemy.get_y() + enemy.get_h())
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
                }
            }
        });
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
        create_sprite();
        add_player_animation();
        create_menu();
        create_menu_start();
        create_menu_intro();
        create_menu_exit();
        menu_add_button();
        window_add_scene();
        scene_add_update();
        load_scene();
    }
};


#endif //LY_ENGINE_RES_H
