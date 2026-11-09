#include "ball.hh"
#include <ctime>
#include <cstdlib>

// Constructeur :
Ball::Ball()
{
    // Rayon
    this->radius = 15;

    // Graine aléatoire
    srand(time(nullptr));

    // Position
    this->x = 400;
    this->y = 300;

    // Velocitée
    this->velX = 0.05f + static_cast<float>(std::rand() % 101) / 1000.0f;
    ;
    this->velY = 0.05f + static_cast<float>(std::rand() % 101) / 1000.0f;
    ;
    this->velMax = 2;

    // facteur acceleration
    this->factAccel = 1.05;
}

// Getters
float Ball::getX()
{
    return this->x;
}

float Ball::getY()
{
    return this->y;
}

float Ball::getVelX()
{
    return this->velX;
}

float Ball::getVelY()
{
    return this->velY;
}
int Ball::getRadius()
{
    return this->radius;
}

// Setters

void Ball::setX(double x)
{
    this->x = x;
}
void Ball::setY(double y)
{
    this->y = y;
}

// Adders
void Ball::addVelX()
{
    if (this->velX * this->factAccel > this->velMax)
    {
        this->velX = this->velMax;
    }
    else
    {
        this->velX *= this->factAccel;
    }
}
void Ball::addVelY()
{
    if (this->velY * this->factAccel > this->velMax)
    {
        this->velY = this->velMax;
    }
    else
    {
        this->velY *= this->factAccel;
    }
}
void Ball::setVelX(double x)
{
    this->velX = x;
}
void Ball::setVelY(double y)
{
    this->velY = y;
}