//
// Created by luoyue on 2023/10/7.
//

#ifndef LYTOY_ENIGNE_LYTOY_H
#define LYTOY_ENIGNE_LYTOY_H

extern "C" {
#include "SDL.h"
#include <SDL_image.h>
#include <SDL_test_images.h>
#include <SDL_blendmode.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_version.h>
#include <SDL_render.h>
#include <SDL_FontCache.h>
}

using Rect = SDL_Rect;
using Render = SDL_Renderer;
using Texture = SDL_Texture;
using Win_dow = SDL_Window;
using Surface = SDL_Surface;
using Color = SDL_Color;
using Point = SDL_Point;
using RenderFLip = SDL_RendererFlip;
using GameEvent = SDL_Event;
using KeyBoardEvent = SDL_KeyboardEvent;
using MouseButtonEvent = SDL_MouseButtonEvent;
using MouseMotionEvent = SDL_MouseMotionEvent;
using MouseWheelEvent = SDL_MouseWheelEvent;
using QuitEvent = SDL_QuitEvent;
using ll = long long;
using ull = unsigned long long;

#include<vector>
#include<map>
#include<string>
#include<utility>
#include<functional>
#include<array>
#include <valarray>

#endif //LYTOY_ENIGNE_LYTOY_H