#include "Pokemon.h"

Pokemon::Pokemon(const std::string &name)
    : _name{name}, _id{idGlobal++}
{
    std::cout << "Pokemon " << name << " created !" << std::endl;
}

Pokemon::Pokemon(const Pokemon &poke)
    : _name{poke._name}, _id{idGlobal++}
{
    std::cout << "pokemon created" << std::endl;
}

Pokemon &Pokemon::operator=(const Pokemon &other)
{
    if (this != &other)
    {
        _name = other._name;
    }

    return *this;
}

const std::string& Pokemon::name() const
{
    return _name;
}

int Pokemon::id() const
{
    return _id;
}