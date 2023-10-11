#include "defines.h"
#include "GameObject.h"
#include "Window.h"
#include "Ui.h"



#undef main
int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    Window window("test", SDL_WINDOW_SHOWN, 980, 540);
    window.CreateRenderer();
    Scene scene("../res/background.png");
    scene.set_dst(0, 0, 980, 540);
    scene.set_src(0, 0, 1960, 1080);

    UI ui("../res/menu.png");
    ui.set_dst(0, 0, 980, 540);
    ui.set_src(0, 0, 1960, 1080);

    window.add_scene(&ui);
    window.add_scene(&scene);
    window.load_scene(0);
    window.load_scene(1);

    Button button{0, 0, 100, 100};
    button.set_dst(100, 100, 100, 100);

    Button button1{60, 500, 500};
    ui.add_button(&button);
    ui.add_button(&button1);
    SDL_Event event;

    int scene_id = 0;
    while (window.get_running())
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                window.set_running(false);
            }
            switch (scene_id)
            {
                case 0:
                    button.on_click(event, [&](){scene_id = 1;});
                    button1.on_click(event, [&](){scene_id = 1;});
                    break;
                case 1:
                    scene.handle_event(event);
                    break;
            }
        }
        window.RenderClear();
        window.render_scene(scene_id);
        switch (scene_id)
        {
            case 0:
                break;
            case 1:
                break;
        }
        window.RenderPresent();
    }
    return 0;
}
