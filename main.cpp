#include "defines.h"
#include "Scene.h"
#include "Window.h"
#include "Sprite.h"
#include "Ui.h"
#include "Event.h"

#undef main
int main()
{
    Window window{"test", SDL_WINDOW_SHOWN, 980, 540};
    window.CreateRenderer();

    Sprite player{"../res/player.png"};
    player.set_dst(400, 400, 30, 50);


    std::vector <Rect> walk_rect = {{0 , 40, 70, 130}, {70, 35, 70, 130},
                                        {190 , 110, 70, 130}, {0, 180, 70, 130},
                                        {90, 245, 70, 130},{205, 240, 70, 130},
                                        {435, 270, 70, 130}, {435, 270, 70, 130}};

    std::vector <Rect> rush_rect = {{255, 755, 95, 110}};

    std::vector <Rect> attacked_rect = {{385, 900, 85, 110}};

    player.set_animation(0,walk_rect);
    player.set_animation(1,rush_rect);
    player.set_animation(2,attacked_rect);

    player.set_src(walk_rect[0]);

    Scene scene{"../res/background.png"};
    scene.set_dst(0, 0, 980, 540);
    scene.set_src(0, 0, 1960, 1080);
    UI ui{"../res/menu.png"};
    ui.set_dst(0, 0, 980, 540);
    ui.set_src(0, 0, 1960, 1080);
    window.add_scene(&ui);
    window.add_scene(&scene);
    scene.add_sprite(&player);
    window.load_scene(0);
    window.load_scene(1);

    int i = 0;
    SDL_Event event;
    bool is_running = true;
    while(true)
    {
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                is_running = false;
                return 0;
            }
            if (event.type == SDL_KEYDOWN)
            {
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
                        player.set_src(walk_rect[i]);
                        i &= 7;
                        player.set_x(player.get_x() - 10);
                        break;
                    }
                    case SDLK_SPACE: {
                        break;
                    }
                    default:
                        break;
                }
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                switch (event.button.button)
                {
                    case SDL_BUTTON_LEFT:
                        i = 1;
                        break;
                    default:
                        break;
                }
            }
        }
        window.RenderClear();
        window.render_scene(i);
        window.RenderPresent();
    }
}
