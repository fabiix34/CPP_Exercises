#pragma once

#include <string>
#include <iostream>
#include <utility>


// A creature that is cute and can fight other ones.
class Pokemon
{
public:
    Pokemon(const std::string& name)
        : _name{name}, _id{idGlobal++}
    {
        std::cout << "Pokemon " << name << " created !" << std::endl;
    }

    // pour faire un constructeur de copy
    // il faut également redéfinir l'operator =
    
    Pokemon(const Pokemon& poke)
        : _name{poke._name}, _id{idGlobal++}
    {
    }

    Pokemon& operator=(const Pokemon& other)
    {
        if (this != &other)
        {
            _name = other._name;
        }

        return *this;
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

typedef std::unique_ptr<Pokemon> PokemonPtr;
