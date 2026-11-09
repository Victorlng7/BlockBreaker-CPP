#pragma once

class Ball
{
private:
    // position
    int x;
    int y;
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
    void setX(int x);
    void setY(int y);

    // adders
    void addVelX();
    void addVelY();

    // Methodes
    void rebondX();
    void rebondY();
    void update();
};