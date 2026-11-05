#include "ball.hh"
#include <ctime>
#include <cstdlib>

// Constructeur :
Ball::Ball()
{
    // Graine aléatoire
    srand(time(nullptr));

    // Position
    this->x = 0;
    this->y = 0;

    // Velocitée
    this->velX = rand() % 20 + 20;
    this->velY = rand() % 20 + 20;
    this->velMax = 500;

    // facteur acceleration
    this->factAccel = 0.2;
}

// Getters
int Ball::getX()
{
    return this->x;
}

int Ball::getY()
{
    return this->y;
}

int Ball::getVelX()
{
    return this->velX;
}

int Ball::getVelY()
{
    return this->velY;
}

// Setters

void Ball::setX(int x)
{
    this->x = x;
}
void Ball::setY(int y)
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