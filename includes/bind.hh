#include <iostream>
#pragma once

class Binds
{
private:
    std::string key;

public:
    // Constructeur
    Binds();

    // Methodes
    void setBind(std::string bind);
    void clearBind();
};