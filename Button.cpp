//
// Created by luoyue on 2023/10/9.
//

#include "Button.h"

Button::Button(const char *fileName) : Sprite(fileName){}

void Button::render(Render *render) {
    SDL_SetRenderDrawColor(render, r, g, b, a);
    SDL_RenderFillRect(render,new  Rect {this->dst.x, this->dst.y, this->dst.w, this->dst.h});
    //SDL_SetRenderDrawColor(render, 0x00, 0xff, 0x00, 0xff);
}

void Button::setClicked(bool isClicked)
{
    this->isClicked = isClicked;
}

//参考了https://stackoverflow.com/questions/38334081/how-to-draw-circles-arcs-and-vector-graphics-in-sdl
void Button::renderCircle(Render *render, int radius, int centreX, int centreY,
                          uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_SetRenderDrawColor(render, r, g, b, a);
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
    //SDL_SetRenderDrawColor(render, 0x00, 0xff, 0x00, 0xff);
}

Button::Button(int x, int y, int w, int h) : Sprite(nullptr) {
    this->dst.x = x;
    this->dst.y = y;
    this->dst.w = w;
    this->dst.h = h;
}

Button::Button(int radius, int centreX, int centreY, uint8_t r, uint8_t g, uint8_t b,
               uint8_t a) : Sprite(nullptr) {
    this->radius = radius;
    this->centreX = centreX;
    this->centreY = centreY;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Button::renderCircle(Render *render)
{
    renderCircle(render, this->radius, this->centreX, this->centreY, this->r, this->g, this->b, this->a);
}

bool Button::getClicked() {
    return this->isClicked;
}

void Button::set_circle(int radius, int centreX, int centreY, uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    this->radius = radius;
    this->centreX = centreX;
    this->centreY = centreY;
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

void Button::setRadius(int radius) {
    this->radius = radius;
}

int Button::getRadius() {
    return this->radius;
}

void Button::setCentreX(int centreX) {
    this->centreX = centreX;
}

int Button::getCentreX() {
    return this->centreX;
}

void Button::setCentreY(int centreY) {
    this->centreY = centreY;
}

int Button::getCentreY() {
    return this->centreY;
}

void Button::setR(uint8_t r) {
    this->r = r;
}

uint8_t Button::getR() {
    return this->r;
}

void Button::setG(uint8_t g) {
    this->g = g;
}

uint8_t Button::getG() {
    return this->g;
}

void Button::setB(uint8_t b) {
    this->b = b;
}

uint8_t Button::getB() {
    return this->b;
}

void Button::setA(uint8_t a) {
    this->a = a;
}

uint8_t Button::getA() {
    return this->a;
}

void Button::set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}
