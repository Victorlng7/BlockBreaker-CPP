#include "paddle.hh"

// constructeur:
Paddle::Paddle()
{
    this->posX = 500;
    this->posY = 500;

    this->width = 100;
    this->height = 20;
}

// getters :
float Paddle::getX()
{
    return this->posX;
}
float Paddle::getY()
{
    return this->posY;
}
int Paddle::getWidth()
{
    return this->width;
}
int Paddle::getHeight()
{
    return this->height;
}

// setters:
void Paddle::setX(double p)
{
    this->posX = p;
}
void Paddle::setY(double p)
{
    this->posY = p;
}