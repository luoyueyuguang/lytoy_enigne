//
// Created by luoyue on 2023/10/10.
//

#include "CircleButton.h"

void CircleButton::set_radius(int radius)
{
    this->radius = radius;
}

int CircleButton::get_radius()
{
    return this->radius;
}

void CircleButton::set_centreX(int centreX)
{
    this->centreX = centreX;
}

int CircleButton::get_centreX()
{
    return this->centreX;
}

void CircleButton::set_centreY(int centreY)
{
    this->centreY = centreY;
}

int CircleButton::get_centreY()
{
    return this->centreY;
}

void CircleButton::set_circle(int radius, int centreX, int centreY) {
    this->radius = radius;
    this->centreX = centreX;
    this->centreY = centreY;
}

void
CircleButton::render_circle(Render *render, int radius, int centreX, int centreY)
{
    const int diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (x >= y)
    {
        SDL_RenderDrawPoint(render, centreX + x, centreY - y);
        SDL_RenderDrawPoint(render, centreX + x, centreY + y);
        SDL_RenderDrawPoint(render, centreX - x, centreY - y);
        SDL_RenderDrawPoint(render, centreX - x, centreY + y);
        SDL_RenderDrawPoint(render, centreX + y, centreY - x);
        SDL_RenderDrawPoint(render, centreX + y, centreY + x);
        SDL_RenderDrawPoint(render, centreX - y, centreY - x);
        SDL_RenderDrawPoint(render, centreX - y, centreY + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

CircleButton::CircleButton(int radius, int centreX, int centreY)
{
    this->radius = radius;
    this->centreX = centreX;
    this->centreY = centreY;
}
