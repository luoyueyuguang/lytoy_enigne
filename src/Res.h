//
// Created by luoyue on 2023/10/16.
//

#ifndef LY_ENGINE_RES_H
#define LY_ENGINE_RES_H
#include "../include/defines.h"
#include "../include/Window.h"
#include "../include/Ui.h"
#include "../include/Text.h"
#include "../include/Box.h"


class Res
{
protected:

    //场景
    Window window{"test", SDL_WINDOW_SHOWN, 1470, 810};
    Scene scene{"../res/background.png"};
    UI win_scene{"../res/win.png"};
    UI lose_scene{"../res/lose.png"};

    //精灵
    Sprite player{"../res/player.png"};
    Sprite enemy{"../res/enemy.png"};

    //发出的攻击
    std::vector<Sprite*> weapons;
    //生命值
    std::vector<int> player_life;
    int enemy_life = 5;

    //菜单
    UI menu{"../res/menu.png"};
    //按钮
    Button menu_exit{"Exit", "../res/GBShinto-Regular.otf", 50,
                     {0xff, 0xff, 0xff, 0xff}};
    Button menu_start{"Start", "../res/GBShinto-Regular.otf", 50,
                      {0xff, 0xff, 0xff, 0xff}};
    Button menu_intro{"Introduction", "../res/GBShinto-Regular.otf", 50,
                      {0xff, 0xff, 0xff, 0xff}};

    Button win_scene_exit{"Exit", "../res/GBShinto-Regular.otf", 50,
                           {0x00, 0x00, 0x00, 0xff}};
    Button win_scene_restart{"Restart", "../res/GBShinto-Regular.otf", 50,
                              {0x00, 0x00, 0x00, 0xff}};
    Button win_scene_you_win{"You Win", "../res/GBShinto-Regular.otf", 80,
                              {0x00, 0x00, 0x00, 0xff}};

    Button lose_scene_exit{"Exit", "../res/GBShinto-Regular.otf", 50,
                           {0xff, 0xff, 0xff, 0xff}};
    Button lose_scene_restart{"Restart", "../res/GBShinto-Regular.otf", 50,
                              {0xff, 0xff, 0xff, 0xff}};
    Button lose_scene_you_lose{"You Lose", "../res/GBShinto-Regular.otf", 80,
                              {0xff, 0xff, 0xff, 0xff}};

    //创建渲染器



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

    //横冲图源
    std::vector<Rect> ver_att= {{240, 0, 210, 470},
                                {0,1045, 245, 425},
                                {0, 0 , 120, 615},
                                {120, 0, 120, 615},
                                };

    //横冲图源
    std::vector<Rect> hor_att = {{0, 2140, 480, 270},
                                 {0, 2910, 500, 240},
                                 {0, 3160, 500, 240},
                                 {0, 2400, 480, 240},};

    void create_renderer();
    void create_sprite();
    void create_scene();
    void add_player_animation();
    void create_menu_start();
    void create_menu();
    void load_scene();
    void scene_add_update();
    void window_add_scene();
    void player_life_emplace();
    void menu_add_button();
    void create_win_and_lose_scene();
    void set_win_lose_button();
    void create_menu_exit();
    void create_menu_intro();
    void load_data();
};


#endif //LY_ENGINE_RES_H
