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
    int velMax;

    // Facteur acceleration
    double factAccel;

public:
    // constructeur
    Ball();

    // Getters
    int getX();
    int getY();
    int getVelX();
    int getVelY();

    // setters
    void setX(double x);
    void setY(double y);

    // adders
    void addVelX();
    void addVelY();

    // Methodes
    void rebondX();
    void rebondY();
    void update();
};