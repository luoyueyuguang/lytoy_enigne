#include "defines.h"
#include "Scene.h"
#include "Window.h"
#include "Sprite.h"
#include "Ui.h"

#undef main
int main()
{
    Window window{"test", SDL_WINDOW_SHOWN, 980, 540};
    window.CreateRenderer();
    Scene scene{"../res/background.png"};
    scene.set_dst(0, 0, 980, 540);
    scene.set_src(0, 0, 1960, 1080);
    UI ui{"../res/background.png"};


    //window.add_scene(&ui);
    //window.load_scene(&ui);
    window.add_scene(&scene);
    window.load_scene(&scene);
    window.RenderClear();
    window.render_scene(&scene);
    window.RenderPresent();
}
