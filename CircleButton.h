//
// Created by luoyue on 2023/10/10.
//

#ifndef LY_ENGINE_CIRCLEBUTTON_H
#define LY_ENGINE_CIRCLEBUTTON_H

#include "Button.h"
#include "defines.h"

class CircleButton
{
public:
    CircleButton(int radius, int centreX, int centreY);
    void set_radius(int radius);
    int get_radius();

    void set_centreX(int centreX);
    int get_centreX();

    void set_centreY(int centreY);
    int get_centreY();
    void set_circle(int radius, int centreX, int centreY);

    static void render_circle(Render *render, int radius, int centreX, int centreY);
private:
    int radius = 0;
    int centreX = 0;
    int centreY = 0;
};


#endif //LY_ENGINE_CIRCLEBUTTON_H
