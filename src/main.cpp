#include "Game.h"



#undef main
int main(int argc, char* argv[])
{
    //把所有需要用的资源初始化
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_AUDIO);
    SDL_Init(SDL_INIT_EVENTS);
    IMG_Init(IMG_INIT_PNG);
    Mix_Init(MIX_INIT_MP3);

    Game game;
    game.game_loop();


    SDL_Quit();
    IMG_Quit();
    return 0;
}
