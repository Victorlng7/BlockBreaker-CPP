#include "ball.hh"
#include <ctime>
#include <cstdlib>

// Constructeur :
Ball::Ball()
{
    // Rayon
    this->radius = 25;

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
// Méthodes

void Ball::update()
{
    // update position
    this->y += this->velY;
    this->x += this->velX;
}

void Ball::rebondX()
{
    // Implémenter vélocitée
    this->addVelX();

    // Changer vélocitée pour simuler rebond
    this->x = this->x * -1;
}

void Ball::rebondY()
{
    // Implémenter vélocitée
    this->addVelY();

    // Changer vélocitée pour simuler rebond
    this->y = this->y * -1;
}