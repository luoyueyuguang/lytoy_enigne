#include "defines.h"
#include "Scene.h"
#include "Menu.h"
#include "Window.h"
#include "Sprite.h"


#undef main
int main()
{
    int i = 100;
    Window window{"test", SDL_WINDOW_SHOWN, 980, 540};
    window.CreateRenderer();
    Scene scene("../res/background.png", new Rect{0, 0, 1960, 1080},
                new Rect{0, 0, 980, 540});
    window.add_scene(&scene);
    window.set_scene(0);

    window.RenderClear();
    window.RenderScene(0);
    window.RenderPresent();
}
