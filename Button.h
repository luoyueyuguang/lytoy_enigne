//
// Created by luoyue on 2023/10/9.
//

#ifndef LY_ENGINE_BUTTON_H
#define LY_ENGINE_BUTTON_H
#include "defines.h"
#include "Sprite.h"

class Button: virtual public Sprite
{
public:
    void render(Render *render) override;
    static void renderCircle(Render *render, int radius, int centreX, int centreY,
                      uint8_t r = 0x00, uint8_t g = 0xff, uint8_t b = 0x00, uint8_t a = 0xff);
    void renderCircle(Render *render);

    explicit Button(const char *fileName);
    Button(int radius, int centreX, int centreY, uint8_t r, uint8_t g, uint8_t b,
           uint8_t a);
    Button(int x, int y, int w, int h);

    void setClicked(bool isClicked);
    bool getClicked();

    void setRadius(int radius);
    int getRadius();

    void setCentreX(int centreX);
    int getCentreX();

    void setCentreY(int centreY);
    int getCentreY();

    void setR(uint8_t r);
    uint8_t getR();

    void setG(uint8_t g);
    uint8_t getG();

    void setB(uint8_t b);
    uint8_t getB();

    void setA(uint8_t a);
    uint8_t getA();

    void set_circle(int radius, int centreX, int centreY, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    void set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
private:
    bool isClicked = false;
    uint8_t r = 0x00, g = 0xff, b = 0x00, a = 0xff;
    int radius = 0;
    int centreX = 0;
    int centreY = 0;
};

#endif //LY_ENGINE_BUTTON_H
