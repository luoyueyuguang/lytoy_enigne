#include "defines.h"
#include "Scene.h"
#include "Window.h"
#include "Sprite.h"
#include "Ui.h"
#include "Game.cpp"

#undef main
int main()
{
    Window window{"test", SDL_WINDOW_SHOWN, 980, 540};
    window.CreateRenderer();

    Sprite player{"../res/player.png"};
    player.set_dst(400, 400, 30, 50);


    std::vector<Rect> walk_rect = {{0,   40,  70, 130},
                                   {70,  35,  70, 130},
                                   {190, 110, 70, 130},
                                   {0,   180, 70, 130},
                                   {90,  245, 70, 130},
                                   {205, 240, 70, 130},
                                   {435, 270, 70, 130},
                                   {435, 270, 70, 130}};

    std::vector<Rect> rush_rect = {{255, 755, 95, 110}};

    std::vector<Rect> attacked_rect = {{385, 900, 85, 110}};

    player.set_animation(0, walk_rect);
    player.set_animation(1, rush_rect);
    player.set_animation(2, attacked_rect);

    player.set_src(walk_rect[0]);

    Scene scene{"../res/background.png"};
    scene.set_dst(0, 0, 980, 540);
    scene.set_src(0, 0, 1960, 1080);

    UI ui{"../res/menu.png"};
    ui.set_dst(0, 0, 980, 540);
    ui.set_src(0, 0, 1960, 1080);

    Button button(0, 0, 100, 100);
    button.set_color(0x00, 0x00, 0x00, 0x00);
    ui.add_button(&button);

    window.add_scene(&ui);
    window.add_scene(&scene);
    scene.add_sprite(&player);

    window.load_scene(0);
    window.load_scene(1);
    SDL_Event event;
    int i = 0;


    scene.add_event(SDL_KEYDOWN, [&](){
        switch (event.key.keysym.sym)
        {
            case SDLK_d: {
                player.set_flip(0x01);
                static int i = 0;
                i++;
                i &= 7;
                player.set_src(walk_rect[i]);
                player.set_x(player.get_x() + 10);
                break;
            }
            case SDLK_a: {
                player.set_flip(0x00);
                static int i = 0;
                i++;
                i &= 7;
                player.set_src(walk_rect[i]);
                player.set_x(player.get_x() - 10);
                break;
            }
            case SDLK_SPACE: {
                break;
            }
            default:
                break;
        }
        return 0;
    });



    ui.add_event(SDL_MOUSEBUTTONDOWN, [&](){
        switch (event.button.button)
        {
            case SDL_BUTTON_LEFT: {
                window.load_scene(1);
                i++;
                break;
            }
            default:
                break;
        }
        return 0;
    });

    while(window.get_running())
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                window.set_running(false);
                return 0;
            }
            switch (i)
            {
                case 0: {
                    ui.handle_event(event);
                    break;
                }
                case 1:
                    scene.handle_event(event);
                    break;
                default:
                    break;
            }
        }

        window.RenderClear();
        window.render_scene(i);
        switch (i)
        {
            case 0: {
                ui.render_button(window.get_render());
                break;
            }
            case 1: {
                //scene.render_sprite(window.get_render(), "player");
                break;
            }
            default:
                break;

        }
        //ui.render_button(window.get_render());
        window.RenderPresent();
    }
}
