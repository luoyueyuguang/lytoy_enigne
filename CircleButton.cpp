//
// Created by luoyue on 2023/10/10.
//

#include "CircleButton.h"

CircleButton::CircleButton(int radius, int centreX, int centreY)
{
    this->radius = radius;
    this->centreX = centreX;
    this->centreY = centreY;
}

void CircleButton::set_radius(int radius)
{
    this->radius = radius;
}

int CircleButton::get_radius() const
{
    return this->radius;
}

void CircleButton::set_centreX(int centreX)
{
    this->centreX = centreX;
}

int CircleButton::get_centreX() const
{
    return this->centreX;
}

void CircleButton::set_centreY(int centreY)
{
    this->centreY = centreY;
}

int CircleButton::get_centreY() const
{
    return this->centreY;
}

void CircleButton::set_circle(int radius, int centreX, int centreY) {
    this->radius = radius;
    this->centreX = centreX;
    this->centreY = centreY;
}

//参考了https://gist.github.com/Gumichan01/332c26f6197a432db91cc4327fcabb1c
void CircleButton::render_circle(Render *render, int radius, int centreX, int centreY)
{
    int offsetx, offsety, d;

    offsetx = 0;
    offsety = radius;
    d = radius -1;

    while (offsety >= offsetx) {

        SDL_RenderDrawLine(render, centreX - offsety, centreY + offsetx, centreX + offsety, centreY + offsetx);
        SDL_RenderDrawLine(render, centreX - offsetx, centreY + offsety, centreX + offsetx, centreY + offsety);
        SDL_RenderDrawLine(render, centreX - offsetx, centreY - offsety, centreX + offsetx, centreY - offsety);
        SDL_RenderDrawLine(render, centreX - offsety, centreY - offsetx, centreX + offsety, centreY - offsetx);

        if (d >= 2*offsetx) {
            d -= 2*offsetx + 1;
            offsetx +=1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }
}
