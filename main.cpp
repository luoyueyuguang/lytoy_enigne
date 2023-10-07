#include "defines.h"
#include "Scene.h"
#include "Menu.h"
#include "Window.h"


#undef main
int main()
{
    int i = 100;
    Window window("test", SDL_WINDOW_SHOWN, 800, 600);
    Render* render = window.CreateRenderer();
    Scene scene("../res/background.png", new Rect{0, 0, 1960, 1080},
                new Rect{0, 0, 980, 540});
    scene.load_texture(render);
}
