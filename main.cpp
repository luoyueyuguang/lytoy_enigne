#include "defines.h"
#include "Window.h"
#include "Ui.h"
#include "Text.h"



#undef main
int main(int argc, char* argv[])
{
    //把所有需要用的资源初始化
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_AUDIO);
    SDL_Init(SDL_INIT_EVENTS);
    IMG_Init(IMG_INIT_PNG);
    Mix_Init(MIX_INIT_MP3);

    //创建窗口
    Window window("test", SDL_WINDOW_SHOWN, 1470, 810);
    //创建渲染器
    window.CreateRenderer();

    //创建场景
    Scene scene("../res/background.png");
    //设置场景的位置和大小
    scene.set_dst(0, 0, 1470, 810);
    //设置场景的来源图片的位置和大小
    scene.set_src(0, 0, 1960, 1080);

    Sprite player("../res/player.png");
    player.set_dst(735, 600, 45, 75);
    player.set_src(0,   40,  70, 130);


    //创建动画 这里会有很长的数组, 考虑到一个函数中实现它， 或者再建一个类。
    //走路图源
    std::vector<Rect> walk_rect = {{0,   40,  70, 130},
                                   {70,  35,  70, 130},
                                   {190, 110, 70, 130},
                                   {0,   180, 70, 130},
                                   {90,  245, 70, 130},
                                   {205, 240, 70, 130},
                                   {435, 270, 70, 130},
                                   {435, 270, 70, 130}};
    //跑步图源
    std::vector<Rect> rush_rect = {{255, 755, 95, 110}};
    //攻击图源
    std::vector<Rect> attacked_rect = {{385, 900, 85, 110}};


    player.set_animation(walk_rect);
    player.set_animation(rush_rect);
    player.set_animation(attacked_rect);

    //创建菜单
    UI menu("../res/menu.png");
    menu.set_dst(0, 0, 1470, 810);
    menu.set_src(0, 0, 1960, 1080);

    //创建开始按钮
    Button menu_start{"Start", "../res/GBShinto-Regular.otf", 50,
                      {0xff, 0xff, 0xff, 0xff}};
    //由于实现者自身水平的原因， 推荐使用set_x和set_y来设置按钮的位置， 而不是set_dst。
    menu_start.set_x(820);
    menu_start.set_y(520);

    //创建介绍按钮
    Button menu_intro{"Introduction", "../res/GBShinto-Regular.otf", 50,
                     {0xff, 0xff, 0xff, 0xff}};
    menu_intro.set_x(820);
    menu_intro.set_y(600);

    //创建退出按钮
    Button menu_exit{"Exit", "../res/GBShinto-Regular.otf", 50,
                     {0xff, 0xff, 0xff, 0xff}};
    menu_exit.set_x(820);
    menu_exit.set_y(680);

    //将按钮添加到菜单中
    menu.add_button(&menu_start);
    menu.add_button(&menu_intro);
    menu.add_button(&menu_exit);

    //将菜单和场景添加到窗口中
    window.add_scene(&menu);
    window.add_scene(&scene);
    scene.add_sprite(&player);
    //必须等精灵或按钮都被添加到场景后才能加载场景
    window.load_scene(0);
    window.load_scene(1);

    //SDL_Event用于接收事件
    SDL_Event event;

    //scene_id用于切换场景
    int scene_id = 0;
    //主循环, 如果window.get_running()返回false则退出循环
    while (window.get_running())
    {
        //SDL_PollEvent用于获取事件
        while (SDL_PollEvent(&event))
        {
            //如果事件类型为SDL_QUIT则退出循环
            if (event.type == SDL_QUIT)
            {
                window.set_running(false);
                SDL_Quit();
            }

            //根据场景id来处理事件
            switch (scene_id)
            {
                case 0:
                    menu_start.on_click(event, [&](){scene_id = 1;});
                    menu_intro.on_click(event, [&](){});
                    menu_exit.on_click(event, [&](){window.set_running(false);});
                    break;
                case 1:
                    scene.handle_event(event);
                    break;
            }
        }

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

    //释放资源

    SDL_Quit();
    IMG_Quit();
    return 0;
}
