#pragma once

#include <string>
#include <iostream>
#include <utility>

// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    Pokemon(const std::string &name)
    {
        _name = name;
        _id = idGlobal++;
        std::cout << "Pokemon " << name << " created !" << std::endl;
    }

    Pokemon(const Pokemon& other)
    : _name(other._name), _id(other._id)
    {
        std::cout << "Pokemon copied with success !" << std::endl;
    }

    std::string name() const
    {
        return _name;
    }

    int id() const
    {
        return _id;
    }

private:
    std::string _name;
    int _id;
    // inline permet de faire croire au compilateur
    // que la variable existe deja
    static inline int idGlobal;
};
