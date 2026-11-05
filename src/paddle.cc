#include "paddle.hh"

// constructeur:
Paddle::Paddle()
{
    this->posX = 0;
    this->posY = 0;

    this->width = 0;
    this->width = 0;
}

// getters :
int Paddle::getX()
{
    return this->posX;
}
int Paddle::getY()
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
void Paddle::setX(int p)
{
    this->posX = p;
}
void Paddle::setX(int p)
{
    this->posY = p;
}