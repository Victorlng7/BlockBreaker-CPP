#pragma once

class Paddle
{
private:
    // position :
    double posX;
    double posY;

    // Dimention :
    int width;
    int height;

public:
    // constructeur
    Paddle();

    // guetters
    float getX();
    float getY();
    int getWidth();
    int getHeight();

    // setters
    void setX(double p);
    void setY(double p);
};