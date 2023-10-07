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
}
