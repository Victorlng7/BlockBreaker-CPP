#include <iostream>
#include "bind.hh"

// Constructuer
Binds::Binds()
{
    this->key = "";
}

// Methodes
void Binds::setBind(std::string bind)
{
    this->key = bind;
}
void Binds::clearBind()
{
    this->key = "";
}