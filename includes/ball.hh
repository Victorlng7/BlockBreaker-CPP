#pragma once

class Ball
{
private:
    // Rayon
    int radius;
    // position
    double x;
    double y;
    // velocitée
    double velX;
    double velY;
    double velMax;

    // Facteur acceleration
    double factAccel;

public:
    // constructeur
    Ball();

    // Getters
    float getX();
    float getY();
    float getVelX();
    float getVelY();
    int getRadius();

    // setters
    void setX(double x);
    void setY(double y);
    void setVelX(double x);
    void setVelY(double y);

    // adders
    void addVelX();
    void addVelY();
};