#include "ball.hh"
#include <algorithm>
#include <cmath>

// Constructeur :
Ball::Ball()
{
    // Rayon
    this->radius = 15;

    // Position
    this->x = 400;
    this->y = 300;

    // Velocitée
    this->velX = 3.0;
    this->velY = 4.0;
    this->velMax = 7.0;

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
    const double acceleratedVelocity = this->velX * this->factAccel;
    this->velX = std::copysign(
        std::min(std::abs(acceleratedVelocity), this->velMax),
        acceleratedVelocity);
}
void Ball::addVelY()
{
    const double acceleratedVelocity = this->velY * this->factAccel;
    this->velY = std::copysign(
        std::min(std::abs(acceleratedVelocity), this->velMax),
        acceleratedVelocity);
}
void Ball::setVelX(double x)
{
    this->velX = x;
}
void Ball::setVelY(double y)
{
    this->velY = y;
}